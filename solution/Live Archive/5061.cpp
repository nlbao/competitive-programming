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


const int MAX_N = 5e4+44;
const int MAX_LOG = 19;


int n, logN;
int h[MAX_N], p[MAX_N][MAX_LOG], f[MAX_N], g[MAX_N];
vector<int> e[MAX_N];


void dfs(int u) {
	fori(i,1,logN) {
		if (h[u]-(1<<i)<1) p[u][i]=-1;
		else p[u][i]=p[p[u][i-1]][i-1];
	}
	foreach(it, e[u]) {
		int v=*it;
		if (p[v][0]) continue;
		p[v][0]=u;
		h[v]=h[u]+1;
		dfs(v);
	}
}


inline int lca(int u, int v) {
	if (h[u]<h[v]) swap(u,v);
	ford(i,logN,0) if (h[u]-(1<<i)>=h[v]) u=p[u][i];
	if (u==v) return u;
	ford(i,logN,0) if (p[u][i]!=p[v][i]) {
		u=p[u][i];
		v=p[v][i];
	}
	return p[u][0];
}


int dfs_2(int u) {
	foreach(it, e[u]) {
		int v=*it;
		if (p[v][0]!=u) continue;
		f[u]+=dfs_2(v);
	}
	f[u]+=g[u];
	return f[u]+g[u];
}


int main() {
#ifdef DEBUG
	freopen("5061.in", "r", stdin);
	freopen("5061.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) e[i].clear();
		fori(i,1,n-1) {
			int x, y;
			cin >> x >> y;
			++x, ++y;
			e[x].pb(y);
			e[y].pb(x);
		}
		logN=0;
		while ((1<<(logN+1))<=n) ++logN;
		filla(p, 0);
		p[1][0]=-1;
		h[1]=1;
		dfs(1);
		filla(f, 0);
		filla(g, 0);
		int nQ=read();
		while (nQ--) {
			int x, y, c;
			cin >> x >> y >> c;
			++x, ++y;
			int r=lca(x, y);
			f[x]+=c;
			f[y]+=c;
			g[r]-=c;
		}
		dfs_2(1);
		cout << "Case #" << testid << ":" << endl;
		fori(i,1,n) cout << f[i] << endl;
	}

	return 0;
}