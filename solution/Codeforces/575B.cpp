#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int MAX_K = 1e6+66;
const int MAX_LOG = 19;
const ll MODULE = 1e9+7;


int n, logN;
vector<pii> e[MAX_N];
int p[MAX_N][MAX_LOG], h[MAX_N], pre[MAX_N], a[MAX_N], b[MAX_N];
bool ok[MAX_N];
ll pow2[MAX_K];


inline ll mmod(ll x) {
	x %= MODULE;
	if (x<0) x += MODULE;
	return x;
}


void dfs(int u) {
	ok[u]=0;
	fori(i,1,logN) {
		if (h[u]-(1<<i) < 1) break;
		p[u][i] = p[p[u][i-1]][i-1];
	}
	foreach(it, e[u]) {
		int v=it->fr;
		if (!ok[v]) continue;
		pre[v]=it->sc;
		h[v]=h[u]+1;
		p[v][0]=u;
		dfs(v);
	}
}


inline int lca(int u, int v) {
	if (h[u]<h[v]) swap(u, v);
	if (h[u]>h[v])
		ford(i,logN,0) if (h[u]-(1<<i)>=h[v]) u=p[u][i];
	if (u==v) return u;
	ford(i,logN,0) if (p[u][i]!=p[v][i]) {
		u=p[u][i];
		v=p[v][i];
	}
	return p[u][0];
}


void solve(int u) {
	foreach(it, e[u]) {
		int v=it->fr;
		if (p[v][0]==u) {
			solve(v);
			a[u]+=a[v];
			b[u]+=b[v];
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("575B.in", "r", stdin);
	freopen("575B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n-1) {
		int x, y, c;
		cin >> x >> y >> c;
		if (c==0) {
			e[x].pb(mp(y, -1));
			e[y].pb(mp(x, -1));
		}
		else {
			e[x].pb(mp(y, 0));
			e[y].pb(mp(x, 1));
		}
	}

	pow2[0]=1;
	fori(i,1,MAX_K-1) pow2[i] = mmod(pow2[i-1] * 2LL);
	logN=0;
	while (1<<(logN+1) <= n) ++logN;

	filla(ok, 1);
	filla(p, 0);
	pre[1]=-1;	h[1]=1;
	dfs(1);

	filla(a, 0);
	filla(b, 0);
	int nQ=read(), u=1, v, r;
	while (nQ--) {
		cin >> v;
		r=lca(u,v);
		++a[u], --a[r];
		++b[v], --b[r];
		u=v;
	}

	ll ans=0;
	solve(1);
	fori(u,2,n) {
		if (a[u]>0 && pre[u]==0) ans = mmod(ans + pow2[a[u]]-1);
		if (b[u]>0 && pre[u]==1) ans = mmod(ans + pow2[b[u]]-1);
	}
	cout << ans << endl;

	return 0;
}