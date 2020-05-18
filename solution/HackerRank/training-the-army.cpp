#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 4*(200 + 30 + 2);
const int oo = int(1e9);


struct Edge {
	int v, inv;
	int c, f;
	Edge(int v, int inv, int c) : v(v), inv(inv), c(c), f(0) {}
};


int n, s, t;
vector<Edge> e[MAX_N];
int id[MAX_N], d[MAX_N], pos[MAX_N], sz[MAX_N];
queue<int> q;


inline void add_edge(int u, int v, int c) {
	int i = (int)e[u].size(), j = (int)e[v].size();
	e[u].push_back(Edge(v, j, c));
	e[v].push_back(Edge(u, i, 0));
}


bool findPath() {
	for (int i = 1; i <= n; ++i)
		d[i] = -1;
	d[s] = 0;
	while (!q.empty()) q.pop();
	q.push(s);
	while (!q.empty()) {
		int u = q.front();	q.pop();
		if (u == t) return true;
		for_each(it, e[u]) {
			int v = it->v;
			if (d[v] == -1 && it->f < it->c) {
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	return false;
}


int incFlow(int u, int flow) {
	if (u == t || flow == 0) return flow;
	for (int &i = pos[u]; i < sz[u]; ++i) {
		int v = e[u][i].v;
		if (d[v] == d[u]+1) {
			int delta = incFlow(v, min(flow, e[u][i].c - e[u][i].f));
			if (delta > 0) {
				e[u][i].f += delta;
				e[v][e[u][i].inv].f -= delta;
				return delta;
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("training-the-army.in", "r", stdin);
	freopen("training-the-army.out", "w", stdout);
#endif
	s = 1;
	t = 2;
	n = 2;
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	for (int i = 1; i <= n1; ++i) {
		id[i] = ++n;
		int x = read();
		add_edge(s, n, x);
		add_edge(n, t, 1);
	}
	for (int i = 0; i < n2; ++i) {
		++n;
		int m = read();
		for (int k = 0; k < m; ++k)
			add_edge(id[read()], n, 1);
		m = read();
		for (int k = 0; k < m; ++k)
			add_edge(n, id[read()], 1);
	}

	for (int i = 1; i <= n; ++i)
		sz[i] = (int)e[i].size();

	int flow = 0;
	while (findPath()) {
		filla(pos, 0);
		for (int delta = 1; delta > 0; )
			flow += (delta = incFlow(s, oo));
	}
	printf("%d\n", flow);
	return 0;
}