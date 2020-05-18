#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <bitset>
#include <ctime>

// #pragma comment(linker, "/STACK:16777216")
#pragma comment(linker, "/STACK:1677721600")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, (x), sizeof(a))
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)

// int read() {	int x;	scanf("%d", &x);	return x;	}
// int readln() {	int x;	scanf("%d\n", &x);	return x;	}

const int MAX_N = int(1e6) + 66;
const int MAX_LOG = 22;
const int oo = int(1e9);

int n, logN, nTime;
int g[MAX_N], a[MAX_N], r[MAX_N], start[MAX_N], finish[MAX_N];
int minChild[MAX_N], minId[MAX_N], p[MAX_N], f[MAX_N][3];
vector<int> e[MAX_N];
bool ok[MAX_N];


void dfs_0(int u) {
	ok[u] = false;
	start[u] = ++nTime;
	minChild[u] = oo;
	for (int i = 0; i < 3; ++i)
		f[u][i] = -1;

	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			p[v] = u == 1 ? v : p[u];
			dfs_0(v);
			minChild[u] = min(minChild[u], minId[v]);
			for (int k = 0; k < 3; ++k)
				if (f[u][k] == -1 || minId[v] < minId[f[u][k]]) {
					for (int t = 2; t > k; --t)
						f[u][t] = f[u][t-1];
					f[u][k] = v;
					break;
				}
		}
	}
	minId[u] = min(u, minChild[u]);
	finish[u] = ++nTime;
}


void dfs_1(int u) {
	ok[u] = false;
	int m = 0;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			g[v] = g[u];
			a[m++] = v;
		}
	}

	if (u != 1) {
		r[m] = oo;
		for (int i = m-1; i >= 0; --i)
			r[i] = min(r[i+1], minId[a[i]]);
		int tmp = oo;
		for (int i = 0; i < m; ++i) {
			int v = a[i];
			g[v] = min(g[v], min(tmp, r[i+1]));
			tmp = min(tmp, minId[v]);
		}
	}

	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) dfs_1(v);
	}
}


inline bool isAncestor(int p, int u) {
	return start[p] <= start[u] && finish[u] <= finish[p];
}


int solve(int u, int v) {
	int pu = p[u], pv = p[v];
	if (isAncestor(pu, v) && isAncestor(pv, u))
		return 1;
	int ans = min(g[u], g[v]);
	if (u != 1) ans = min(ans, minChild[u]);
	if (v != 1) ans = min(ans, minChild[v]);
	for (int k = 0; k < 3; ++k) {
		int p = f[1][k];
		if (p > -1 && !isAncestor(p, u) && !isAncestor(p, v))
			ans = min(ans, minId[p]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("4916.in", "r", stdin);
	freopen("4916.out", "w", stdout);
#endif
	while (scanf("%d", &n) == 1) {
		// int nQ = read();
		int nQ;
		scanf("%d", &nQ);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		logN = 0;
		while ((1<<logN) <= n) ++logN;

		nTime = 0;
		p[1] = 1;
		filla(ok, true);
		dfs_0(1);

		g[1] = oo;
		filla(ok, true);
		dfs_1(1);

		int ans = 0;
		while (nQ--) {
			int u, v;
			scanf("%d%d", &u, &v);
			u = u ^ ans;
			v = v ^ ans;
			ans = solve(u, v);
			printf("%d\n", ans);
		}
	}
	return 0;
}
