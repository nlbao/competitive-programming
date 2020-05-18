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


const int MAX_N = 1e5 + 5;
const int MAX_P = 20;


struct edge {
	int v, time, id;
	edge() {}
	edge(int v, int time, int id) : v(v), time(time), id(id) {}
};


int n, m, A, B, ABTime, logN;
vector<edge> e[MAX_N];
bool ok[MAX_N], use[MAX_N];
int a[MAX_N], d[MAX_N], h[MAX_N], p[MAX_N][MAX_P];


void dfs(int u) {
	ok[u] = false;
	for (int i = 1; i <= logN; ++i)
		if (h[u] - (1<<i) < 1) break;
		else p[u][i] = p[p[u][i-1]][i-1];
	for (int i = 0; i < (int)e[u].size(); ++i) {
		int v = e[u][i].v, time = e[u][i].time, id = e[u][i].id;
		if (ok[v]) {
			p[v][0] = u;
			h[v] = h[u] + 1;
			d[v] = d[u] + time;
			use[id] = true;
			dfs(v);
		}
		else if (!use[id]) {
			A = u;
			B = v;
			ABTime = time;
		}
	}
}


int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] < h[v])
		for (int i = logN; i >= 0; --i)
			if (h[v] - (1<<i) >= h[u])
				v = p[v][i];
	if (u == v) return u;
	for (int i = logN; i >= 0; --i)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}


ll dist(int u, int v) {
	int r = lca(u, v);
	return d[u] + d[v] - 2*d[r];
}


ll minDist(int u, int v) {
	if (u == v) return 0;
	ll x = dist(u, v);
	ll y = dist(u, A) + ABTime + dist(B, v);
	ll z = dist(u, B) + ABTime + dist(A, v);
	return min(x, min(y, z));
}


int main() {
#ifdef DEBUG
	freopen("grand-tour.in", "r", stdin);
	freopen("grand-tour.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 0; i < n; ++i) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		e[x].push_back(edge(y, t, i));
		e[y].push_back(edge(x, t, i));
	}

	filla(ok, true);
	filla(use, false);
	filla(p, 0);
	logN = 0;
	while ((1<<logN) <= n) ++logN;
	h[1] = 1;
	d[1] = 0;
	dfs(1);

	ll ans = 0;
	int m = read(), pre;
	for (int i = 0; i < m; ++i) {
		int u = read();
		ans += a[u];
		if (i > 0) ans += minDist(pre, u);
		pre = u;
	}
	cout << ans << endl;
	return 0;
}