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


const int MAX_N = 55;
const int MAX_K = 55;
const ll MOD = 1e9+7;


int N, K, m;
int a[MAX_N], p[MAX_N];
vector<int> e[MAX_N];
ll c[MAX_K][MAX_K], fact[MAX_K];
ll f[MAX_N][MAX_K], g[MAX_N][MAX_K];


inline ll mmod(ll x) {
	return x % MOD;
}


void dfs(int u) {
	f[u][1] = 1;
	foreach(it, e[u]) {
		int v = *it;
		if (!p[v]) {
			p[v]=u;
			dfs(v);
		}
	}

	int m = 0;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v]==u) a[++m] = v;
	}
	if (m==0) return;

	for (int x=0; x<=K; ++x)
		g[0][x]=0;
	g[0][1]=1;
	for (int i=1; i<=m; ++i) {
		int v=a[i];
		for (int x=0; x<=K; ++x)
			g[i][x] = 0;
		for (int x=1; x<=K; ++x)
			for (int y=1; y<=K; ++y) {
				if (x+y <= K)
					g[i][x+y] = mmod(g[i][x+y] + mmod(g[i-1][x] * f[v][y]));
				if (x+y-1 <= K)
					g[i][x+y-1] = mmod(g[i][x+y-1] + mmod(g[i-1][x] * f[v][y]));
				else
					break;
			}
		g[i][1]=1;
	}
	for (int x=0; x<=K; ++x)
		f[u][x] = g[m][x];
}


ll solve() {
	ll ans = 0;
	for (int x = 1; x <= min(N, K); ++x) {
		ll a = f[1][x];
		ll b = mmod(fact[x] * c[K][x]);
		ans = mmod(ans + mmod(a * b));
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("COLTREE.in", "r", stdin);
	freopen("COLTREE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(c, 0);
	c[0][0] = 1;
	for (int i = 1; i < MAX_K; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = mmod(c[i-1][j-1] + c[i-1][j]);
	}
	fact[0] = 1;
	for (ll i = 1; i < MAX_K; ++i)
		fact[i] = mmod(fact[i-1] * i);

	int nTest = read();
	while (nTest--) {
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) e[i].clear();
		for (int i = 0; i < N-1; ++i) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		filla(f, 0);
		filla(p, 0);
		p[1] = -1;
		dfs(1);
		cout << solve() << endl;
	}

	return 0;
}