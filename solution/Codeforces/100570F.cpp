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
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5 + 55;


int n, nQ, crrCut, crrTurn, m;
int turn[MAX_N], nChild[MAX_N], a[MAX_N], g[MAX_N], ans[MAX_N], root[MAX_N];
ll d[MAX_N];
vector<pii> e[MAX_N];
vector<ll> c, b[MAX_N];
vector<int> qlist[MAX_N];
pair<int, ll> q[MAX_N];
bool cut[MAX_N];


void dfs_0(int u) {
	turn[u] = crrTurn;
	nChild[u] = 1;
	a[m++] = u;
	foreach(it, e[u]) {
		int v = it->sc;
		if (cut[v] || turn[v] == crrTurn) continue;
		dfs_0(v);
		nChild[u] += nChild[v];
	}
}


void dfs_1(int u) {
	turn[u] = crrTurn;
	foreach(it, e[u]) {
		int v = it->sc;
		if (cut[v] || turn[v] == crrTurn) continue;
		d[v] = d[u] + it->fr;
		if (u == crrCut) root[v] = v;
		else root[v] = root[u];
		dfs_1(v);
	}
}


inline int cntLessThan(vector<ll> &a, ll limit) {
	if (limit < 0) return 0;
	if ((int)a.size() < 1) return 0;
	return int(upper_bound(a.begin(), a.end(), limit) - a.begin());
}


void solve(int u) {
	m = 0;
	++crrTurn;
	dfs_0(u);
	int x = a[0];
	for (int i = 0; i < m; ++i) {
		int u = a[i];
		g[u] = max(nChild[u], m-nChild[u]);
		if (g[u] < g[x])
			x = u;
		b[u].clear();
	}
	cut[x] = true;

	++crrTurn;
	crrCut = x;
	d[x] = 0;
	root[x] = 0;
	dfs_1(x);

	c.clear();
	b[0].clear();
	for (int i = 0; i < m; ++i) {
		int u = a[i];
		c.push_back(d[u]);
		b[root[u]].push_back(d[u]);
	}
	sort(c.begin(), c.end());
	foreach(it, e[x]) {
		int v = it->sc;
		if (cut[v]) continue;
		sort(b[v].begin(), b[v].end());
	}

	for (int i = 0; i < m; ++i) {
		int u = a[i];
		foreach(it, qlist[u]) {
			int id = *it;
			ll limit = q[id].sc - d[u];
			int t = cntLessThan(c, limit);
			if (u != crrCut)
				t -= cntLessThan(b[root[u]], limit);
			ans[id] += t;
		}
	}

	foreach(it, e[x]) {
		int v = it->sc;
		if (cut[v]) continue;
		solve(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("100570F.in", "r", stdin);
	freopen("100570F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	for (int i = 0; i < n-1; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		e[x].push_back(pii(w, y));
		e[y].push_back(pii(w, x));
	}

	for (int i = 0; i < nQ; ++i) {
		cin >> q[i].fr >> q[i].sc;
		qlist[q[i].fr].push_back(i);
		ans[i] = 0;
	}

	crrTurn = 0;
	filla(turn, 0);
	filla(cut, false);
	solve(1);
	for (int i = 0; i < nQ; ++i)
		cout << ans[i] << endl;

	return 0;
}