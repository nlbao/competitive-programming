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

const int MAX_N = 5*int(1e4) + 4;
const int MAX_M = int(1e5) + 5;


int n, m;
int x[MAX_M], y[MAX_M];
int p[MAX_N], f[MAX_N], h[MAX_N];
vector<int> e[MAX_N];
bool isBridge[MAX_M];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


void dfs(int u) {
	foreach(it, e[u]) {
		int v = *it;
		if (f[v] == 0) {
			f[v] = u;
			h[v] = h[u]+1;
			dfs(v);
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("ONBRIDGE.in", "r", stdin);
	freopen("ONBRIDGE.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		filla(p, -1);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			++x[i], ++y[i];
			int u = getRoot(x[i]), v = getRoot(y[i]);
			if (u != v) {
				p[u] = v;
				e[x[i]].push_back(y[i]);
				e[y[i]].push_back(x[i]);
				isBridge[i] = true;
			}
			else isBridge[i] = false;
		}
		// build tree
		filla(f, 0);
		filla(p, -1);
		for (int i = 1; i <= n; ++i) if (f[i] == 0) {
			f[i] = -1;
			h[i] = 1;
			dfs(i);
		}
		// cal
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			if (isBridge[i]) ++ans;
			else {
				int u = getRoot(x[i]), v = getRoot(y[i]);
				while (u != v) {
					--ans;
					if (h[u] > h[v]) {
						p[u] = getRoot(f[u]);
						u = p[u];
					}
					else {
						p[v] = getRoot(f[v]);
						v = p[v];
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}