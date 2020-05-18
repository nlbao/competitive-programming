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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 2e5+5;


int n, m, nE;
int din[MAX_N], dout[MAX_N], p[MAX_N];
pii e[MAX_N];


int getRoot(int u) {
	return p[u]<1 ? u : p[u]=getRoot(p[u]);
}


bool solve() {
	int r=getRoot(1);
	if (getRoot(n) != r) return 0;
	fori(i,1,n) if (getRoot(i) == r) {
		if (din[i]!=dout[i]) return 0;
	}
	fori(i,1,nE) {
		int u=getRoot(e[i].fr), v=getRoot(e[i].sc);
		if (u!=r && v!=r) return 0;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("the-cabbalistic-hills-1.in", "r", stdin);
	freopen("the-cabbalistic-hills-1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> m;
		fori(i,1,n) {
			p[i]=-1;
			din[i]=dout[i]=0;
		}
		nE=0;
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			if (x==y) continue;
			e[++nE]=mp(x,y);
			++dout[x], ++din[y];
			x=getRoot(x), y=getRoot(y);
			if (x!=y) p[x]=y;
		}
		if (solve()) cout << "Go on get the Magical Lamp\n";
		else cout << "Danger!! Lucifer will trap you\n";
	}

	return 0;
}