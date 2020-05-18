struct Flow {
	struct Edge {
		int v, c, f, inv;
		Edge() {}
		Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
	};

	static const int MAX_N = 2e5 + 55;
	static const int oo = 1e9;
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
		filla(d, 0);	d[s] = 1;
		queue<int> q;	q.push(s);
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