#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 505;
const int oo = int(1e9);


struct edge {
	int v;
	int c, f, cost;
	int back;
	edge(int v, int c, int cost, int back): v(v), c(c), cost(cost), back(back) {
		f = 0;
	}
};


int n, m, s, t;
vector<edge> e[MAX_N];
int a[MAX_N], d[MAX_N], p[MAX_N], p_e[MAX_N], state[MAX_N];
bool exchange[MAX_N][MAX_N];
deque<int> q;


void add_edge(int u, int v, int c, int cost) {
	// cout << u << " " << v << endl;
	e[u].push_back(edge(v, c, cost, e[v].size()));
	e[v].push_back(edge(u, 0, -cost, (int)e[u].size() - 1));
}


bool findPath() {
	for (int i = 0; i < MAX_N; ++i) {
		d[i] = oo;
		p[i] = p_e[i] = -1;
		state[i] = 0;
	}
	d[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		int u = q.front();	q.pop_front();
		state[u] = 2;
		for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
			if (e[u][i].f >= e[u][i].c) continue;
			int v = e[u][i].v;
			int tmp = d[u] + e[u][i].cost;
			if (tmp < d[v]) {
				d[v] = tmp;
				p[v] = u;
				p_e[v] = i;
				if (state[v] == 0) q.push_back(v);
				else if (state[v] == 2) q.push_front(v);
			}
		}
	}
	return p[t] > -1;
}


int solve() {
	int cost = 0, flow = 0;
	while(findPath()) {
		int addFlow = n;
		for (int v = t; v != s; v = p[v]) {
			int u = p[v], i = p_e[v];
			addFlow = min(addFlow, e[u][i].c - e[u][i].f);
		}
		for (int v = t; v != s; v = p[v]) {
			int u = p[v], i = p_e[v], r = e[u][i].back;
			e[u][i].f += addFlow;
			e[v][r].f -= addFlow;
			cost += e[u][i].cost*addFlow;
		}
		flow += addFlow;
	}
	if (flow < n) return -1;
	return cost;
}


int main() {
#ifdef DEBUG
	freopen("GREED.in", "r", stdin);
	freopen("GREED.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		// read input
		n = read();
		s = 0;	t = MAX_N - 2;
		for (int i = 0; i < MAX_N; ++i) e[i].clear();
		fill(a, 0);
		for (int i = 0; i < n; ++i) ++a[read()];
		for (int i = 1; i < MAX_N; ++i) {
			add_edge(s, i, a[i], 0);
			if (i <= n)
				add_edge(i, t, 1, 0);
		}

		m = read();
		fill(exchange, false);
		for (int i = 0; i < m; ++i) {
			int x = read(), y = read();
			if (x == y) continue;
			exchange[x][y] = exchange[y][x] = true;
		}
		for (int u = 1; u < t; ++u)
			for (int v = u+1; v < t; ++v)
				if (exchange[u][v]) {
					add_edge(u, v, oo, 1);
					add_edge(v, u, oo, 1);
				}
		// solve
		printf("%d\n", solve());
	}

	return 0;
}