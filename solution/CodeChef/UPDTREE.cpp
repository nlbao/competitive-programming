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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const int MAX_LOG = 18;


int n, nTime, logN;
vector<int> e[MAX_N];
bool ok[MAX_N];
int h[MAX_N], d[MAX_N];
int start[MAX_N], finish[MAX_N], p[MAX_LOG][MAX_N];
ll f[MAX_N];


void dfs_0(int u) {
	ok[u] = false;
	start[u] = ++nTime;
	for (int i = 1; i <= logN; ++i)
		if (h[u]-(1<<i) < 1) p[i][u] = 0;
		else p[i][u] = p[i-1][p[i-1][u]];
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			h[v] = h[u]+1;
			p[0][v] = u;
			dfs_0(v);
		}
	}
	finish[u] = ++nTime;
}


inline bool isAncestor(int u, int v) {
	return start[u] <= start[v] && finish[v] <= finish[u];
}


int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	if (h[u] > h[v])
		for (int i = logN; i >= 0; --i)
			if (h[u]-(1<<i) >= h[v])
				u = p[i][u];
	if (u == v) return u;
	for (int i = logN; i >= 0; --i)
		if (p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v];
		}
	return p[0][u];
}


inline void add(int u, int v, int value) {
	if (h[u] >= h[v]) return;
	d[v] += value;
	d[u] -= value;
}


void remove(int ru, int u, int rv, int v) {
	if (ru == u || rv == v) return;
	if (h[ru] > h[rv]) {
		swap(ru, rv);
		swap(u, v);
	}
	if (!isAncestor(ru, rv) || !isAncestor(rv, u)) return;
	if (isAncestor(u, v)) add(rv, u, -1);
	else if (isAncestor(v, u)) add(rv, v, -1);
	else add(rv, lca(u, v), -1);
}


void update(int a, int b, int c, int d) {
	if (a == b) return;
	int ra = lca(a, b), rc = lca(c, d);
	add(ra, a, 1);
	add(ra, b, 1);
	remove(ra, a, rc, c);
	remove(ra, a, rc, d);
	remove(ra, b, rc, c);
	remove(ra, b, rc, d);
}


void dfs_1(int u) {
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (p[0][v] == u) {
			dfs_1(v);
			d[u] += d[v];
		}
	}
}


void dfs_2(int u) {
	f[u] += ll(d[u]);
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (p[0][v] == u) {
			f[v] = f[u];
			dfs_2(v);
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("UPDTREE.in", "r", stdin);
	freopen("UPDTREE.out", "w", stdout);
#endif
	int m1, m2;
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	logN = 0;
	while (1<<(logN+1) <= n) ++logN;
	filla(ok, true);
	nTime = 0;
	h[1] = 1;
	p[0][1] = 0;
	dfs_0(1);

	filla(d, 0);
	while (m1--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		update(a, b, c, d);
	}

	dfs_1(1);
	d[1] = f[1] = 0;
	dfs_2(1);

	while (m2--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int r = lca(a, b);
		printf("%lld\n", f[a] + f[b] - 2LL*f[r]);
	}
	return 0;
}