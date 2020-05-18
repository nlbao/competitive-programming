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


const int MAX_N = 105;
const int oo = 2*int(1e9);


struct edge {
	int v;
	int c, f, cost;
	int back;
	edge(int v, int c, int cost, int back): v(v), c(c), cost(cost), back(back) {
		f = 0;
	}
};


int n, m, k, s, t, nAns = 0;
vector<edge> e[MAX_N];
int d[MAX_N], p[MAX_N], p_e[MAX_N], state[MAX_N];
deque<int> q;
vector<vector<int> > ans;


void add_edge(int u, int v, int c, int cost) {
	int i = e[u].size(), j = e[v].size();
	e[u].push_back(edge(v, c, cost, j));
	e[v].push_back(edge(u, 0, -cost, i));
}


bool find_path() {
	for (int i = 0; i <= n; ++i) {
		p[i] = p_e[i] = -1;
		state[i] = 0;
		d[i] = oo;
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
				state[v] = 1;
			}
		}
	}
	return p[t] > -1;
}


void dfs(int u) {
	ans[nAns].push_back(u);
	if (u == t) return;
	while (p[u] >= 0 && (e[u][p[u]].c == 0 || e[u][p[u]].f == 0)) --p[u];
	if (p[u] < 0) return;
	dfs(e[u][p[u]].v);
	--p[u];
}


int main() {
#ifdef DEBUG
	freopen("HIWAY.in", "r", stdin);
	freopen("HIWAY.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	k = 2;
	for (int i = 0; i <= n; ++i) e[i].clear();
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		add_edge(x, y, 1, c);
		add_edge(y, x, 1, c);
	}

	int flow = 0, cost = 0;
	while (find_path()) {
		int addFlow = k-flow;
		if (addFlow == 0) break;
		for (int v = t; v != s; v = p[v]) {
			int u = p[v], i = p_e[v];
			addFlow = min(addFlow, e[u][i].c - e[u][i].f);
		}
		for (int v = t; v != s; v = p[v]) {
			int u = p[v], i = p_e[v], r = e[u][i].back;
			e[u][i].f += addFlow;
			e[v][r].f -= addFlow;
			cost += addFlow*e[u][i].cost;
		}
		flow += addFlow;

	}

	if (flow < k) {
		printf("-1\n");
		return 0;
	}

	nAns = 0;
	ans.clear();
	for (int i = 0; i <= n; ++i) p[i] = (int)e[i].size()-1;
	for (int id = 0; id < k; ++id) {
		ans.push_back(vector<int>());
		dfs(s);
		++nAns;
	}

	printf("%d\n", cost);
	for (int i = 0; i < nAns; ++i) {
		int sz = ans[i].size();
		printf("%d ", sz);
		for (int j = 0; j < sz; ++j)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}