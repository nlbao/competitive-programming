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


struct Flow {
	static const int MAX_N = 2e5 + 55;
	static const int oo = 1e9;

	struct Edge {
		int v, c, f, inv;
		Edge() {}
		Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
	};

	int n, s, t;
	vector<Edge> e[MAX_N];
	int d[MAX_N], pos[MAX_N], sz[MAX_N];
	queue<int> q;

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		filla(sz, 0);
		for (int i = 0; i <= n; ++i)
			e[i].clear();
	}

	void addEdge(int u, int v, int c) {
		e[u].push_back(Edge(v, c, sz[v]++));
		e[v].push_back(Edge(u, 0, sz[u]++));
	}

	bool bfs() {
		filla(d, 0);
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

	int getFlow() {
		int flow = 0;
		while (bfs()) {
			filla(pos, 0);
			for (int delta = 1; delta > 0; )
				flow += (delta = dfs(s, oo));
		}
		return flow;
	}
};


const int MAX_N = 1e3 + 33;
const int MAX_TIME = 1e2 + 22;


int id[MAX_N][MAX_TIME];
Flow flow;


int main() {
#ifdef DEBUG
	freopen("100526.in", "r", stdin);
	freopen("100526.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		int n, pos, nPeople, nTime, m;
		cin >> n;
		cin >> pos >> nPeople >> nTime;
		int nC = 2, s = 1, t = 2;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= nTime; ++j)
				id[i][j] = ++nC;
		flow.init(nC, s, t);
		flow.addEdge(s, id[pos][0], nPeople);
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int u = read();
			for (int j = 0; j <= nTime; ++j)
				flow.addEdge(id[u][j], t, nPeople);
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int u, v, p, cost;
			cin >> u >> v >> p >> cost;
			for (int j = 0; j <= nTime-cost; ++j)
				flow.addEdge(id[u][j], id[v][j+cost], p);
		}
		for (int i= 1; i <= n; ++i)
			for (int j = 0; j < nTime; ++j)
				flow.addEdge(id[i][j], id[i][j+1], nPeople);
		cout << flow.getFlow() << endl;
	}

	return 0;
}