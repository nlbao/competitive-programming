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


const int MAX_N = 111;
const int oo = int(1e9);


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
			int u = q.front();	q.pop();
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


int n, m, minCost;
vector<pii> e[MAX_N];
set<pii> heap;
int d1[MAX_N], dn[MAX_N], id[2][MAX_N];


void dijkstra(int s, int d[]) {
	for (int i = 0; i <= n; ++i)
		d[i] = oo;
	d[s] = 0;
	heap.clear();
	heap.insert(make_pair(d[s], s));
	while (!heap.empty()) {
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v = it->second;
			int tmp = d[u] + it->first;
			if (tmp < d[v]) {
				set<pii>::iterator p = heap.find(make_pair(d[v], v));
				if (p != heap.end()) heap.erase(p);
				d[v] = tmp;
				heap.insert(make_pair(tmp, v));
			}
		}
	}
}


int solve() {
	int nV = 2;
	id[0][1] = id[1][1] = 1;
	id[0][n] = id[1][n] = 2;
	for (int i = 2; i < n; ++i) {
		id[0][i] = ++nV;
		id[1][i] = ++nV;
	}

	Flow flow(nV);
	for (int i = 2; i < n; ++i)
		flow.addEdge(id[0][i], id[1][i], 1);

	dijkstra(1, d1);
	dijkstra(n, dn);
	if (d1[n] >= minCost) return -1;

	for (int u = 1; u <= n; ++u)
		foreach(it, e[u]) {
			int v = it->second;
			if (d1[u] + it->first + dn[v] == d1[n]) {
				flow.addEdge(id[1][u], id[0][v], oo);
				flow.addEdge(id[1][v], id[0][u], oo);
			}
		}
	return flow.maxFlow();
}


int main() {
#ifdef DEBUG
	freopen("100534I.in", "r", stdin);
	freopen("100534I.out", "w", stdout);
#endif
	n = read(), m = read();
	minCost = oo;
	for (int i = 0; i < m; ++i) {
		int x = read()+1, y = read()+1, w = read();
		if ((x == 1 && y == n) || (x == n && y == 1)) {
			minCost = min(minCost, w);
			continue;
		}
		e[x].push_back(make_pair(w, y));
		e[y].push_back(make_pair(w, x));
	}

	int ans = solve();
	if (ans < 0) printf("IMPOSSIBLE\n");
	else printf("%d\n", ans);
	return 0;
}