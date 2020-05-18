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


const int MAX_N = 5e5+1;
const int MAX_LOG = 20;

int n, m, nTime, logN;
int start[MAX_N], finish[MAX_N], a[MAX_N], h[MAX_N], p[MAX_N][MAX_LOG];
vector<int> e[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	start[u] = ++nTime;
	ok[u] = 0;
	for (int i = 1; i < logN; ++i)
		if (h[u] - (1<<i) < 1) p[u][i] = -1;
		else p[u][i] = p[p[u][i-1]][i-1];
	foreach(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		h[v] = h[u]+1;
		p[v][0] = u;
		dfs(v);
	}
	finish[u] = ++nTime;
}


int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	for (int i = logN-1; i >= 0; --i)
		if (h[u]-(1<<i) >= h[v])
			u = p[u][i];
	if (u == v) return u;
	for (int i = logN-1; i >= 0; --i)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}


bool cmp(int i, int j) {
	return start[i] < start[j];
}


bool isAncestor(int r, int u) {
	return (start[r] <= start[u] && finish[u] <= finish[r]);
}


int solve() {
	if (m == 1) return 0;
	for (int i = 0; i < m; ++i) ok[i] = 1;
	for (int i = 0; i < m-1; ++i) {
		int u = a[i], v = a[i+1];
		if (isAncestor(u, v)) ok[i] = 0;
		if (isAncestor(v, u)) ok[i+1] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < m; ++i) if (ok[i]) ++cnt;
	int r = a[1];
	for (int i = 2; i < m; ++i)
		r = lca(r, a[i]);
	if (isAncestor(a[0], r) && a[0] != r) ++cnt;
	return (cnt+1) >> 1;
}


int main() {
#ifdef DEBUG
	freopen("path-covering.in", "r", stdin);
	freopen("path-covering.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	logN = 1;
	while ((1<<logN) <= n) ++logN;
	nTime = 0;
	h[1] = 1;
	p[1][0] = -1;
	filla(ok, 1);
	dfs(1);

	int nQ = read();
	while (nQ--) {
		m = read();
		for (int i = 0; i < m; ++i)
			cin >> a[i];
		sort(a, a+m, cmp);
		cout << solve() << endl;
	}

	return 0;
}