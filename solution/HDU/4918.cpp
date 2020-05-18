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



int findRoot(int x, int parent) {
	int r = 0;
	q[r++] = x;
	fa[x] = -1;
	for (int i = 0; i < r; ++i) {
		int u = q[i];
		for (int k = 0; k < sz[u]; ++k) {
			int v = e[u][k];
			if (!ok[v] || v == fa[u]) continue;
			q[r++] = v;
			fa[v] = u;
		}
	}

	int minC = oo, ans = x;
	for (int i = r-1; i >= 0; --i) {
		int u = q[i];
		c[u] = 1;
		for (int k = 0; k < sz[u]; ++k) {
			int v = e[u][k];
			if (ok[v] && v != fa[u])
				c[u] += c[v];
		}
		int value = min(c[u], r-c[u]);
		if (value < minC) {
			minC = value;
			ans = u;
		}
	}

	ok[ans] = false;
	fa[ans] = parent;
	for (int k = 0; k < sz[ans]; ++k) {
		int v = e[ans][k];
		if (ok[v] && v != fa[ans])
			findRoot(v, ans);
	}
}


int main() {
#ifdef DEBUG
	freopen("4918.in", "r", stdin);
	freopen("4918.out", "w", stdout);
#endif
	while (scanf("%d", &n) == 1) {
		int nQ = readln();
		for (int i = 1; i <= n; ++i) {
			w[i] = read();
			e[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d\n", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		for (int i = 1; i <= n; ++i) {
			sz[i] = (int)e[i].size();
		}

		filla(ok, true);
		root = findRoot(1, -1);

		while (nQ--) {
			char ch;
			int u, x;
			scanf("%c %d %d\n", &ch, &u, &x);
		}
	}
	return 0;
}