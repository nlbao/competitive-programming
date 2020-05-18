#pragma comment(linker, "/STACK:1024000000")

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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5) + 5;
const int MAX_LOG = 20;

int n, m, logN;
vector<int> e[MAX_N];
vector<pii> query[MAX_N];
int p[MAX_N], h[MAX_N];
bool ok[MAX_N];


struct Path {
	int u, v, r;
	Path(int u = 0, int v = 0, int r = 0) : u(u), v(v), r(r) {}
} a[MAX_N];


bool cmp(const Path &a, const Path &b) {
	return h[a.r] > h[b.r];
}


int getRoot(int u) {
	if (p[u] == u) return u;
	return p[u] = getRoot(p[u]);
}


void dfs(int u) {
	ok[u] = false;
	p[u] = u;
	for (int i = 0, sz = (int)query[u].size(); i < sz; ++i) {
		int v = query[u][i].first;
		if (!ok[v])
			a[query[u][i].second].r = getRoot(v);
	}
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			h[v] = h[u]+1;
			dfs(v);
			p[v] = u;
		}
	}
}


void dfs_remove(int u) {
	ok[u] = false;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (!ok[v] || h[v] < h[u]) continue;
		dfs_remove(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("4912.in", "r", stdin);
	freopen("4912.out", "w", stdout);
#endif
	while (scanf("%d", &n) == 1) {
		m = read();
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			query[i].clear();
			ok[i] = true;
		}

		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = Path(x, y, -1);
			query[x].push_back(make_pair(y, i));
			query[y].push_back(make_pair(x, i));
		}

		h[1] = 1;
		dfs(1);

		sort(a, a+m, cmp);

		int ans = 0;
		for (int i = 1; i <= n; ++i) ok[i] = true;
		for (int i = 0; i < m; ++i)
			if (ok[a[i].u] && ok[a[i].v]) {
				++ans;
				dfs_remove(a[i].r);
			}
		printf("%d\n", ans);
	}

	return 0;
}