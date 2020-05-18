#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


int n, m, ans, minValue, top, nTime;
vector<int> e[MAX_N];
int p[MAX_N], num[MAX_N], low[MAX_N], stk[MAX_N], f[MAX_N];
bool ok[MAX_N];


inline bool isCut(int u) {
	if (u == 1) return true;
	if (low[u] >= num[u]) return true;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != u) continue;
		if (low[v] >= num[u]) return true;
	}
	return false;
}


void dfs(int u) {
	num[u] = low[u] = ++nTime;
	stk[++top] = u;
	f[u] = 1;
	foreach(it, e[u]) {
		int v = *it;
		if (v == p[u] || !ok[v]) continue;
		if (p[v] == 0) {
			p[v] = u;
			dfs(v);
			f[u] += f[v];
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		int v = -1;
		while (v != u) {
			v = stk[top--];
			ok[v] = false;
		}
	}

	if (isCut(u)) {
		int maxF = 0, c = n-1;
		foreach(it, e[u]) {
			int v = *it;
			if (p[v] != u) continue;
			if (low[v] >= num[u]) {
				maxF = max(maxF, f[v]);
				c -= f[v];
			}
		}
		maxF = max(maxF, c);
		if (maxF < minValue) {
			minValue = maxF;
			ans = u;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("100703E.in", "r", stdin);
	freopen("100703E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	ans = 1;
	minValue = n-1;
	filla(p, 0);
	filla(ok, true);
	p[1] = -1;
	nTime = top = 0;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}