#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 3e5 + 5;
const int oo = 1e9;


struct Query {
	int u, v, w;
	Query(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};


int n, m, nQ, crrTurn, crrRoot;
vector<int> e[MAX_N];
vector<pii> qlist[MAX_N];
vector<Query> newQ;
int turn[MAX_N], nChild[MAX_N], root[MAX_N];
int a[MAX_N], d[MAX_N], g[MAX_N], f[MAX_N];
bool cut[MAX_N];


inline void addQuery(int u, int v, int w) {
	qlist[u].push_back(pii(w, v));
	if (u == v) return;
	qlist[v].push_back(pii(w, u));
}


void dfs_0(int u) {
	turn[u] = crrTurn;
	nChild[u] = 1;
	g[u] = 1;
	foreach(it, e[u]) {
		int v = *it;
		if (cut[v] || turn[v] == crrTurn) continue;
		dfs_0(v);
		nChild[u] += nChild[v];
		g[u] = max(g[u], nChild[v]);
	}
	a[m++] = u;
}


void dfs_1(int u) {
	turn[u] = crrTurn;
	nChild[u] = 1;
	g[u] = f[u];
	foreach(it, e[u]) {
		int v = *it;
		if (cut[v] || turn[v] == crrTurn) continue;
		d[v] = d[u] + 1;
		if (u == crrRoot) root[v] = v;
		else root[v] = root[u];
		dfs_1(v);
		nChild[u] += nChild[v];
		g[u] = min(g[u], g[v]-1);
	}
}


int find(int u) {
	++crrTurn;
	m = 0;
	dfs_0(u);
	if (m == 1) {
		if (f[u] < 0) return 0;
		foreach(it, qlist[u]) {
			int v = it->second, w = it->first;
			if (w < 0) return 0;
		}
		return u;
	}

	u = a[0];
	for (int i = 0; i < m; ++i) {
		int x = a[i];
		g[x] = max(g[x], m-g[x]);
	}
	for (int i = 1; i < m; ++i)
		if (g[a[i]] < g[u])
			u = a[i];
	cut[u] = true;

	d[u] = 0;
	++crrTurn;
	crrRoot = u;
	root[u] = -1;
	dfs_1(u);

	int failNode = -1;
	for (int i = 0; i < m; ++i) {
		int x = a[i];
		foreach(it, qlist[x]) {
			int y = it->second, w = it->first;
			if (turn[x] != crrTurn || turn[y] != crrTurn) continue;
			if (root[x] == root[y] && w < d[x] + d[y]) {
				if (failNode != -1 && failNode != root[x]) return 0;
				failNode = root[x];
			}
		}
	}

	int minG = oo;
	for (int i = 0; i < m; ++i)
		if (root[a[i]] == a[i])
			minG = min(minG, g[a[i]]-1);

	newQ.clear();
	for (int i = 0; i < m; ++i) {
		int x = a[i];
		foreach(it, qlist[x]) {
			int y = it->second, w = it->first;
			if (w < 0) return 0;
			if (turn[x] != crrTurn || turn[y] != crrTurn) continue;
			if (failNode == -1) {
				minG = min(minG, w - (d[x] + d[y]));
				continue;
			}
			int rx = root[x], ry = root[y];
			if (rx == failNode && ry == failNode) continue;
			if (rx == failNode) {
				int t = w - (d[y] + 1);
				newQ.push_back(Query(x, rx, t));
			}
			else if (ry == failNode) {
				int t = w - (d[x] + 1);
				newQ.push_back(Query(y, ry, t));
			}
			else {
				int t = w - (d[x] + d[y] + 2);
				newQ.push_back(Query(failNode, failNode, t));
			}
		}
	}
	foreach(it, newQ)
		addQuery(it->u, it->v, it->w);

	int v = failNode;
	if (v == -1 && minG >= 0) return u;
	f[v] = min(f[v], minG-1);
	return find(v);
}


int solve() {
	for (int i = 1; i <= n; ++i) {
		cut[i] = false;
		turn[i] = 0;
		f[i] = oo;
	}
	crrTurn = 0;
	return find(1);
}


int main() {
#ifdef DEBUG
	freopen("amppz_2014_jas.in", "r", stdin);
	freopen("amppz_2014_jas.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	int testid = 0;
	while (nTest--) {
		cin >> n >> nQ;
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			qlist[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for (int i = 0; i < nQ; ++i) {
			int a, b, d;
			cin >> a >> b >> d;
			addQuery(a, b, d);
		}
		int ans = solve();
		if (ans) printf("TAK %d\n", ans);
		else printf("NIE\n");
	}

	return 0;
}