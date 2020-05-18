#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e6 + 6;
const int MAX_LOG = 20;


int n, m, nTime, logN;
vector<int> e[MAX_N];
int h[MAX_N], start[MAX_N], finish[MAX_N], p[MAX_N][MAX_LOG];
bool ok[MAX_N];
pii a[MAX_Q];


void dfs(int u) {
	ok[u] = false;
	start[u] = ++nTime;
	for (int i = 1; i <= logN; ++i)
		if (h[u] - (1<<i) > 0)
			p[u][i] = p[p[u][i-1]][i-1];
		else p[u][i] = -1;
	foreach(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		p[v][0] = u;
		h[v] = h[u]+1;
		dfs(v);
	}
	finish[u] = ++nTime;
}


inline bool isAncestor(int u, int v) {
	return start[u] <= start[v] && finish[v] <= finish[u];
}


int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	for (int i = logN; i >= 0; --i)
		if (h[u] - (1<<i) >= h[v])
			u = p[u][i];
	if (u == v) return u;
	for (int i = logN; i >= 0; --i)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}


bool solve() {
	if (m < 3) return true;
	--m;
	int u = a[m--].second;
	while (m >= 0 && isAncestor(a[m].second, u)) {
		u = a[m].second;
		--m;
	}
	if (m < 0) return true;
	int v = a[m--].second;
	while (m >= 0) {
		int r = a[m].second;
		bool pu = isAncestor(r, u);
		bool pv = isAncestor(r, v);
		if (pu && pv)
			return m == 0 && r == lca(u, v);
		if (!pu && !pv)
			return false;
		if (pu) u = r;
		else v = r;
		--m;
	}
	return true;
	// return isAncestor(u, v) || isAncestor(v, u);
}


int main() {
#ifdef DEBUG
	freopen("KNODES.in", "r", stdin);
	freopen("KNODES.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		logN = 0;
		while ((1<<logN) < n) ++logN;
		filla(ok, true);
		nTime = 0;
		h[1] = 1;
		p[1][0] = -1;
		dfs(1);

		int nQ = read();
		while (nQ--) {
			scanf("%d", &m);
			for (int i = 0; i < m; ++i) {
				int u = read();
				a[i] = pii(h[u], u);
			}
			sort(a, a+m);
			if (solve()) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}