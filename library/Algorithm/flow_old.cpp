// Fast flow - Dinic algorithm
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