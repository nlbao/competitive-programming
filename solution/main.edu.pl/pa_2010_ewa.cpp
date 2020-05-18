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

inline ll read() {	ll x;   cin >> x;   return x;   }


struct Flow {
	static const int oo = 1e9;

	struct Edge {
		int v, c, f, inv;
		Edge() {}
		Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
	};

	int n, s, t;
	vector<vector<Edge> > e;
	vector<int> d, pos, sz;
	queue<int> q;

	Flow(int n, int s = 1, int t = 2): n(n), s(s), t(t), e(n+1), d(n+1), pos(n+1), sz(n+1, 0) {}

	void addEdge(int u, int v, int c) {
		e[u].push_back(Edge(v, c, sz[v]++));
		e[v].push_back(Edge(u, 0, sz[u]++));
	}

	bool bfs() {
		fillv(d, 0);
		d[s] = 1;
		while (!q.empty()) q.pop();
		q.push(s);
		while (!q.empty()) {
			int u = q.front();  q.pop();
			if (u == t) return true;
			foreach(it, e[u]) {
				int v = it->v;
				if (!d[v] && it->f < it->c) {
					d[v] = d[u]+1;
					q.push(v);
				}
			}
		}
		return false;
	}

	int dfs(int u, int flow) {
		if (u == t || flow == 0) return flow;
		for (; pos[u] < sz[u]; ++pos[u]) {
			int i = pos[u], v = e[u][i].v;
			if (d[v] == d[u]+1) {
				int delta = dfs(v, min(flow, e[u][i].c - e[u][i].f));
				if (delta) {
					e[u][i].f += delta;
					e[v][e[u][i].inv].f -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	int maxFlow() {
		int flow = 0;
		while (bfs()) {
			fillv(pos, 0);
			fill(pos.begin(), pos.end(), 0);
			for (int delta = 1; delta > 0; )
				flow += (delta = dfs(s, oo));
		}
		return flow;
	}
};


const int MAX_N = 1044;
const int oo = 1e9;
const int MAX_M = MAX_N*(MAX_N-1);


int n, m;
int x[MAX_M], y[MAX_M];
int d[MAX_N], f[MAX_N], g[MAX_N];
vector<int> e[MAX_N], invE[MAX_N];
queue<int> q;


void bfs(int s, vector<int> e[MAX_N]) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[s] = 0;
	while (!q.empty()) q.pop();
	q.push(s);
	while (!q.empty()) {
		int u = q.front();	q.pop();
		foreach(it, e[u]) {
			int v = *it;
			if (d[v] < oo) continue;
			d[v] = d[u]+1;
			q.push(v);
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("pa_2010_ewa.in", "r", stdin);
	freopen("pa_2010_ewa.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
		e[x[i]].push_back(y[i]);
		invE[y[i]].push_back(x[i]);
	}

	bfs(1, e);
	for (int i = 1; i <= n; ++i)
		f[i] = d[i];
	bfs(n, invE);
	for (int i = 1; i <= n; ++i)
		g[i] = d[i];

	int s = 1, t = n;
	Flow flow(n, s, t);
	for (int i = 0; i < m; ++i) {
		int u = x[i], v = y[i];
		if (f[u] + 1 + g[v] > 3) continue;
		flow.addEdge(u, v, 1);
	}
	cout << flow.maxFlow() << '\n';

	return 0;
}