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


const int MAX_N = 1e4+44;
const int oo = 1e9;


int n;
int p[MAX_N], d[MAX_N], trace[MAX_N], x[MAX_N], y[MAX_N];
bool ok[MAX_N];


int getRoot(int u) {
	return p[u]==u ? u : p[u]=getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("100484G.in", "r", stdin);
	freopen("100484G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		cin >> x[i] >> y[i];
		p[i]=i;
		d[i]=oo;
	}
	int m=read();
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[getRoot(u)]=getRoot(v);
	}

	filla(ok, 1);
	d[1]=0;
	trace[1]=1;
	while (1) {
		int u=-1;
		fori(i,1,n) if (ok[i] && (u<0 || d[i]<d[u])) u=i;
		if (u<0) break;
		ok[u]=0;
		if (getRoot(trace[u])!=getRoot(u)) {
			cout << trace[u] << " " << u << endl;
			p[getRoot(trace[u])]=getRoot(u);
		}
		fori(i,1,n) if (ok[i]) {
			int dist=sqr(x[u]-x[i])+sqr(y[u]-y[i]);
			if (getRoot(u)==getRoot(i)) dist=0;
			if (dist<d[i]) {
				d[i]=dist;
				trace[i]=u;
			}
		}
	}
	return 0;
}