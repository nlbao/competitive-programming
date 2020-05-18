#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const double EPS = 1e-9;


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
					if (tmp + EPS < d[v]) {
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


const int MAX_N = 55;


int n, d, k;
double a[MAX_N][MAX_N];
int id[2][MAX_N], ans[MAX_N];


void solve() {
	// init flow
	int nC = 2, s = 1, t = 2;
	for (int i = 1; i <= n; ++i) id[0][i] = ++nC;
	for (int i = 1; i <= d; ++i) id[1][i] = ++nC;
	MinCostFlow<int, double> flow(nC, s, t);
	for (int i = 1; i <= n; ++i) {
		int u = id[0][i];
		flow.addEdge(s, u, 1, 0);
		for (int j = 1; j <= d; ++j)
			flow.addEdge(u, id[1][j], 1, -log(a[i][j]));
	}
	for (int i = 1; i <= d; ++i) {
		int u = id[1][i];
		flow.addEdge(u, t, 1, 0);
		if (k > 1)
			flow.addEdge(u, t, k-1, 100);
	}
	// get ans
	flow.getFlow();
	double maxP = 1;
	for (int i = 1; i <= n; ++i) {
		int u = id[0][i];
		foreach(it, flow.e[u]) {
			int v = it->v;
			if (v != s && it->f == 1) {
				int j = v-id[1][1]+1;
				maxP *= a[i][j];
				ans[i] = j;
				break;
			}
		}
	}
	printf("%.6lf\n", maxP);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}


int main() {
#ifdef DEBUG
	freopen("DINING.in", "r", stdin);
	freopen("DINING.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d%d", &n, &d, &k);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= d; ++j)
				scanf("%lf", &a[i][j]);
		solve();
	}
	return 0;
}