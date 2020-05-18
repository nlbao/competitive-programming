// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+55;


int n, m, crrTurn, nV;
int p[MAX_N], turn[MAX_N], a[MAX_N];


int getRoot(int u) {
	return p[u]<0 ? u : p[u]=getRoot(p[u]);
}


inline void init(int u) {
	if (turn[u]==crrTurn) return;
	turn[u]=crrTurn;
	p[u]=-1;
	a[++nV]=u;
}


int main() {
#ifdef DEBUG
	freopen("AGRAPH.in", "r", stdin);
	freopen("AGRAPH.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	filla(turn, 0);
	crrTurn=0;
	while (nTest--) {
		cin >> n >> m;
		// fori(i,1,n) p[i]=-1;
		nV=0;
		++crrTurn;
		ll ce=0;
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			init(x);
			init(y);
			x=getRoot(x);
			y=getRoot(y);
			if (x==y) continue;
			p[x]+=p[y];
			p[y]=x;
			++ce;
		}

		int sEqual=0, s=0;
		m=0;
		fori(i,1,nV) {
			int u=a[i];
			if (getRoot(u)!=u) continue;
			int x=-p[u];
			if (!(x&1)) sEqual += x/2;
			else {
				++m;
				s += x/2;
			}
		}
		m += n-nV;

		ll ans=0;
		int l=max(0, m/2-44);
		int r=min(m, m/2+44);
		fori(i,l,r) {
			ll a = sEqual + s + m-i;
			ll b = sEqual + s + i;
			ans=max(ans, a*b - ce);
		}
		cout << ans << endl;
	}

	return 0;
}