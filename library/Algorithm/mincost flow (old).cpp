struct Edge {
	int v, c, w, f, inv;
	Edge() {}
	Edge(int v, int c, int w, int inv) v(v), c(c), w(w), f(0), inv(inv) {}
};


int n, m, k, s, t;
vector <Edge> e[MAXN];
int parent[MAXN], p_edge[MAXN], d[MAXN], state[MAXN];
deque <int> q;


void addEdge(int u, int v, int c, int w){
	int i = e[u].size(), j = e[v].size();
	e[u].push_back(Edge(v, c, w, j));
	e[v].push_back(Edge(u, 0, -w, i));
}

int findPath(){
	for (int i = 1; i <= n; ++i){
		d[i] = MAXC;
		state[i] = 0;
		parent[i] = p_edge[i] = -1;
	}
	d[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		int u = q.front();  q.pop_front();
		state[u] = 2;
		for (int i = 0, sz = e[u].size(); i < sz; ++i) {
			if (e[u][i].f < e[u][i].c) {
				int v = e[u][i].v;
				int tmp = d[u] + e[u][i].w;
				if (tmp < d[v]) {
					d[v] = tmp;
					parent[v] = u;
					p_edge[v] = i;
					if (state[v] == 0) q.push_back(v);
					else if (state[v] == 2) q.push_front(v);
					state[v] = 1;
				}
			}
		}
	}
	return (parent[t] > -1);
}

int cal() {
	ll flow = 0, cost = 0;
	while (findPath()){
		int addFlow = k - flow;
		if (addFlow == 0)
			break;
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v], i = p_edge[v];
			addFlow = min(addFlow, e[u][i].c - e[u][i].f);
		}
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v], i = p_edge[v], j = e[u][i].inv;
			e[u][i].f += addFlow;
			e[v][j].f -= addFlow;
			cost += ll(addFlow) * ll(e[u][i].w);
		}
		flow += addFlow;
	}
	return flow;
}



///////////////////////////////


template<class Flow, class Cost>
struct MinCostFlow {
	static const Cost oo = 1e9;

	struct Edge {
		int v, inv;
		Flow c, f;
		Cost w;
		Edge() {};
		Edge(int v, Flow c, Cost w, int inv) : v(v), inv(inv), c(c), f(0), w(w) {}
	};

	int n, s, t;
	vector<vector<Edge> > e;
	vector<Cost> d;
	vector<int> parent, pEdge, state;
	deque<int> q;

	MinCostFlow(int n, int s = 1, int t = 2) : n(n), s(s), t(t), e(n+1), d(n+1), parent(n+1), pEdge(n+1), state(n+1) {}

	void addEdge(int u, int v, Flow c, Cost w) {
		int i = e[u].size(), j = e[v].size();
		e[u].push_back(Edge(v, c, w, j));
		e[v].push_back(Edge(u, 0, -w, i));
	}

	bool findPath() {
		for (int i = 1; i <= n; ++i) {
			d[i] = oo;
			state[i] = 0;
			parent[i] = pEdge[i] = -1;
		}
		d[s] = 0;
		while (!q.empty()) q.pop_front();
		q.push_front(s);
		while (!q.empty()) {
			int u = q.front();  q.pop_front();
			state[u] = 2;
			for (int i = 0, sz = (int)e[u].size(); i < sz; ++i)
				if (e[u][i].f < e[u][i].c) {
					int v = e[u][i].v;
					Cost tmp = d[u] + e[u][i].w;
					if (tmp < d[v]) {
						d[v] = tmp;
						parent[v] = u;
						pEdge[v] = i;
						if (state[v] == 0) q.push_back(v);
						else if (state[v] == 2) q.push_front(v);
						state[v] = 1;
					}
				}
		}
		return (parent[t] > -1);
	}

	pair<Flow, Cost> getFlow(Flow flowLimit = oo) {
		Flow flow = 0, cost = 0;
		while (findPath()) {
			Flow add = flowLimit - flow;
			if (add <= 0) break;
			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v], i = pEdge[v];
				add = min(add, e[u][i].c - e[u][i].f);
			}
			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v], i = pEdge[v];
				e[u][i].f += add;
				e[v][e[u][i].inv].f -= add;
				cost += Cost(add) * e[u][i].w;
			}
			flow += add;
		}
		return make_pair(flow, cost);
	}
};