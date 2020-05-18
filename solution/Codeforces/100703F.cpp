#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


template<class Flow, class Cost>
struct MinCostFlow {
	static const Cost oo = 1e9 + 9;

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


const int MAX_N = 444;


int n, m;
int a[MAX_N], b[MAX_N], id[4][MAX_N];


int solve(int cX, int cY) {
	int s = 1, t = 2, nC = 2;
	for (int i = 1; i <= m; ++i)
		id[0][i] = ++nC;
	for (int i = 1; i <= n; ++i) {
		id[1][i] = ++nC;
		id[2][i] = ++nC;
	}
	for (int i = 1; i <= 2; ++i)
		id[3][i] = ++nC;

	MinCostFlow<int, int> flow(nC, s, t);
	for (int i = 1; i <= m; ++i) {
		flow.addEdge(s, id[0][i], 1, 0);
		for (int j = 1; j <= n; ++j)
			flow.addEdge(id[0][i], id[1][j], 1, 0);
	}
	for (int i = 1; i <= n; ++i) {
		flow.addEdge(id[1][i], id[2][i], 1, 0);
		flow.addEdge(id[2][i], id[3][1], 1, a[i]);
		flow.addEdge(id[2][i], id[3][2], 1, b[i]);
	}
	flow.addEdge(id[3][1], t, cX, 0);
	flow.addEdge(id[3][2], t, cY, 0);

	pii ans = flow.getFlow();
	if (ans.first != m) return flow.oo;
	return ans.second;
}


int main() {
#ifdef DEBUG
	freopen("100703F.in", "r", stdin);
	freopen("100703F.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	int x = m/2, y = m-x;
	int ans = solve(x, y);
	if (x != y)
		ans = min(ans, solve(y, x));
	printf("%d\n", ans);
	return 0;
}