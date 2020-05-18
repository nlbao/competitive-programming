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


const int MAX_N = 111;
const ll MODULE = 1e9 + 7;


int n, start, finish;
vector<int> e[MAX_N];
ll fac[MAX_N], f[MAX_N], g[MAX_N][MAX_N];
bool ok[MAX_N], hasFinish[MAX_N];
int a[MAX_N];


void dfs(int u, int par) {
	ok[u] = false;
	f[u] = 1;
	if (u == finish) {
		hasFinish[u] = true;
		return;
	}
	foreach(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		dfs(v, u);
		hasFinish[u] = hasFinish[u] || hasFinish[v];
	}

	int m = 0, tmp = -1;
	foreach(it, e[u]) {
		int v = *it;
		if (v != par) {
			if (!hasFinish[v]) a[m++] = v;
			else tmp = v;
		}
	}

	if (!hasFinish[u]) {
		for (int i = 0; i < m; ++i)
			f[u] = (f[u] * f[a[i]]) % MODULE;
		f[u] = (f[u] * fac[m]) % MODULE;
		return;
	}

	f[u] = f[tmp];
	if (m == 0) return;

	filla(g, 0);
	g[0][0] = 1;
	g[0][1] = f[a[0]];
	for (int i = 1; i < m; ++i) {
		int v = a[i];
		g[i][0] = 1;
		for (int x = 1; x <= i+1; ++x) {
			g[i][x] = ((g[i-1][x-1] * f[v]) % MODULE + g[i-1][x]) % MODULE;
		}
	}

	f[u] = f[tmp];
	for (int x = 1; x <= m; ++x) {
		ll t = (g[m-1][x] * fac[x]) % MODULE;
		t = (t * f[tmp]) % MODULE;
		f[u] = (f[u] + t) % MODULE;
	}
}


int main() {
#ifdef DEBUG
	freopen("dfs-on-tree.in", "r", stdin);
	freopen("dfs-on-tree.out", "w", stdout);
#endif
	fac[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		fac[i] = (fac[i-1] * i) % MODULE;

	int nTest = read();
	while (nTest--) {
		scanf("%d%d%d", &n, &start, &finish);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		filla(ok, true);
		filla(hasFinish, false);
		dfs(start, -1);
		printf("%d\n", (int)f[start]);
	}
	return 0;
}