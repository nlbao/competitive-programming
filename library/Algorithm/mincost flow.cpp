template<class Flow, class Cost>
struct MinCostFlow {
	struct Edge {
		int v, inv;
		Flow c, f;
		Cost w;
		Edge() {}
		Edge(int v, Flow c, Cost w, int inv) : v(v), inv(inv), c(c), f(0), w(w) {}
	};

	static const int MAX_N = 1e5+55;
	static const Cost oo = 1e9;
	int n, s, t;
	vector<Edge> e[MAX_N];
	Cost d[MAX_N];
	int p[MAX_N], pEdge[MAX_N], state[MAX_N];

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		fori(i,1,n) e[i].clear();
	}

	void addEdge(int u, int v, Flow c, Cost w) {
		int i = sz(e[u]), j = sz(e[v]);
		e[u].pb(Edge(v, c, w, j));
		e[v].pb(Edge(u, 0, -w, i));
	}

	bool findPath() {
		fori(i,1,n) {
			d[i] = oo;
			state[i] = 0;
			p[i] = pEdge[i] = -1;
		}
		d[s] = 0;
		deque<int> q;
		q.push_back(s);
		while (!q.empty()) {
			int u = q.front();		q.pop_front();
			state[u] = 2;
			fori(i, 0, sz(e[u])-1) if (e[u][i].f < e[u][i].c) {
				int v = e[u][i].v;
				Cost tmp = d[u] + e[u][i].w;
				if (tmp >= d[v]) continue;
				d[v] = tmp;
				p[v] = u;	pEdge[v] = i;
				if (state[v] == 0) q.push_back(v);
				else if (state[v] == 2) q.push_front(v);
				state[v] = 1;
			}
		}
		return p[t] > -1;
	}

	pair<Flow, Cost> getFlow(Flow limit = oo) {
		Flow flow = 0;	Cost cost = 0;
		while (findPath()) {
			Flow add = limit-flow;
			if (add <= 0) break;
			for (int v = t; v != s; v = p[v]) {
				int u = p[v], i = pEdge[v];
				add = min(add, e[u][i].c - e[u][i].f);
			}
			flow += add;
			for (int v = t; v != s; v = p[v]) {
				int u = p[v], i = pEdge[v];
				e[u][i].f += add;
				e[v][e[u][i].inv].f -= add;
				cost += Cost(add) * e[u][i].w;
			}
		}
		return mp(flow, cost);
	}
};