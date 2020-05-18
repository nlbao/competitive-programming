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

    pair<Flow, Cost> getFlow(Flow flowLimit) {
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


const int MAX_N = 33;
const int MAX_M = 33;


char s[MAX_N][MAX_M];
int a[MAX_N][MAX_M];
int id[2][MAX_N][MAX_M];


int main() {
#ifdef DEBUG
	freopen("543C.in", "r", stdin);
	freopen("543C.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		// printf("%s\n", s[i]);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);

	// init
	int nC = 2, nChar = int('z'-'a')+1;
	for (int i = 0; i < n; ++i) id[0][i][m] = ++nC;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			id[0][i][j] = ++nC;
	for (int j = 0; j < m; ++j)
		for (int k = 0; k < nChar; ++k)
			id[1][j][k] = ++nC;
	// graph
	MinCostFlow<int, int> flow(nC);
	for (int i = 0; i < n; ++i)
		flow.addEdge(1, id[0][i][m], 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			flow.addEdge(id[0][i][m], id[0][i][j], 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < nChar; ++k) {
				int cost = int(s[i][j] - 'a') - k;
				if (cost != 0) cost = a[i][j];
				for (int u = 0; u < n; ++u) if (u != i)
					if (int(s[u][j] - 'a') == k)
						cost += a[u][j];
				// cout << i << " " << j << " " << k << " " << cost << endl;
				flow.addEdge(id[0][i][j], id[1][j][k], 1, cost);
			}
	for (int j = 0; j < m; ++j)
		for (int k = 0; k < nChar; ++k)
			flow.addEdge(id[1][j][k], 2, 1, 0);
	// solve
	pii ans = flow.getFlow(n);
	printf("%d\n", ans.second);

	// cout << ans.first << " " << ans.second << endl;
	return 0;
}