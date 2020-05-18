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


const int MAX_N = 1e3 + 3;


int n, m, nC, nTime, top;
int d[MAX_N], a[MAX_N], c[MAX_N];
int stk[MAX_N], num[MAX_N], low[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	stk[top++] = u;
	low[u] = num[u] = ++nTime;
	foreach(it, e[u]) {
		int v = *it;
		if (ok[v]) {
			if (num[v] == 0) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], num[v]);
		}
	}
	if (low[u] == num[u]) {
		a[++nC] = 0;
		int v = -1;
		while (top > 0 && v != u) {
			v = stk[--top];
			c[v] = nC;
			++a[nC];
			ok[v] = false;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("monks-birthday-treat.in", "r", stdin);
	freopen("monks-birthday-treat.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	filla(d, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[y].push_back(x);
		++d[x];
	}

	for (int i = 1; i <= n; ++i) {
		if (d[i] == 0) {
			printf("1\n");
			return 0;
		}
	}

	top = nTime = nC = 0;
	filla(ok, true);
	filla(a, 0);
	filla(num, 0);
	for (int i = 1; i <= n; ++i)
		if (ok[i])
			dfs(i);

	filla(d, 0);
	for (int i = 1; i <= n; ++i) {
		int u = c[i];
		foreach(it, e[i]) {
			int v = c[*it];
			if (u == v) continue;
			++d[v];
		}
	}

	int ans = n;
	for (int i = 1; i <= nC; ++i)
		if (d[i] == 0)
			ans = min(ans, a[i]);
	printf("%d\n", ans);
	return 0;
}