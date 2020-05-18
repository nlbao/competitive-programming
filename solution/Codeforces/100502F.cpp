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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_V = 505;
const int MAX_N = sqr(MAX_V);


double cost, x[MAX_V], y[MAX_V], ans[MAX_V][MAX_V];
int id[MAX_V][MAX_V];
int p[MAX_N];
vector<int> e[MAX_V];
pair<double, pii> a[MAX_N];
set<pii> list[MAX_N];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


inline int unite(int u, int v) {
	if (p[u] > p[v]) swap(u, v);
	// merge two list
	set<pii>::iterator tmp;
	foreach(it, list[v]) {
		pii x = *it;
		tmp = list[u].find(make_pair(x.second, x.first));
		if (tmp != list[u].end()) {
			ans[x.first][x.second] = ans[x.second][x.first] = cost;
			list[u].erase(tmp);
		}
		else list[u].insert(x);
	}
	list[v].clear();
	// unite
	p[u] += p[v];
	p[v] = u;
	return u;
}


int main() {
#ifdef DEBUG
	freopen("100502F.in", "r", stdin);
	freopen("100502F.out", "w", stdout);
#endif
	int n = read();
	for (int i = 1; i <= n; ++i) {
		x[i] = read();
		y[i] = read();
	}

	int m = read();
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	// init
	int N = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (i != j) {
			double d = sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
			a[N++] = make_pair(-d, make_pair(i, j));
		}
	sort(a, a+N);

	filla(ans, 0);
	filla(id, -1);
	filla(p, -1);
	for (int i = 0; i < N; ++i) {
		int u = a[i].second.first, v = a[i].second.second;
		int r1 = id[u][v] = i;
		list[i].clear();
		list[i].insert(a[i].second);
		cost = -a[i].first;

		foreach(it, e[u]) {
			int x = *it;
			if (x == v || id[x][v] < 0) continue;
			int r2 = getRoot(id[x][v]);
			if (r2 != r1)
				r1 = unite(r1, r2);
		}
		foreach(it, e[v]) {
			int y = *it;
			if (y == u || id[u][y] < 0) continue;
			int r2 = getRoot(id[u][y]);
			if (r2 != r1)
				r1 = unite(r1, r2);
		}
	}

	// queries
	m = read();
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%.8lf\n", ans[u][v]);
	}
	return 0;
}