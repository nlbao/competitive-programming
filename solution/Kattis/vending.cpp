#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 55;


int n, nC, nTime, top;
int f[MAX_N], cost[MAX_N], price[MAX_N], cnt[MAX_N], pre[MAX_N];
int deg[MAX_N], num[MAX_N], low[MAX_N], stk[MAX_N], c[MAX_N];
ll d[MAX_N], g[MAX_N];
bool ok[MAX_N];
vector<pii> e[MAX_N];
vector<int> listC[MAX_N];


void dfs(int u) {
	stk[++top] = u;
	num[u] = low[u] = ++nTime;
	foreach(it, e[u]) {
		int v = it->second;
		if (!ok[v]) continue;
		if (num[v] == 0) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		++nC;
		int v = -1;
		while (v != u) {
			v = stk[top--];
			ok[v] = false;
			c[v] = nC;
			listC[nC].push_back(v);
		}
	}
}


ll solve(int id) {
	int m = listC[id].size();
	if (m == 1) return d[listC[id][0]];
	ll ans = 0, sum = 0;
	for (int i = 0; i < m; ++i)
		sum += d[listC[id][i]];
	for (int i = 0; i < m; ++i) {
		int u = listC[id][i];
		ans = max(ans, sum - d[u] + g[u]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("H.in", "r", stdin);
	freopen("H.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d%d", &f[i], &cost[i], &price[i], &cnt[i]);

	filla(d, 0);
	filla(deg, 0);
	for (int i = 1; i <= n; ++i) {
		int j = f[i];
		ll t = price[j] - cost[i];
		if (t <= 0) continue;
		d[j] = max(d[j], t);
		e[i].push_back(pii(t, j));
		++deg[j];
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += d[i] * (cnt[i] - 1);

	nC = nTime = top = 0;
	filla(ok, true);
	filla(num, 0);
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			dfs(i);
	for (int i = 1; i <= n; ++i)
		if (ok[i])
			dfs(i);

	filla(g, 0);
	for (int u = 1; u <= n; ++u)
		foreach(it, e[u]) {
			int v = it->second;
			if (c[u] == c[v]) continue;
			g[v] = max(g[v], (ll)it->first);
		}
	for (int i = 1; i <= nC; ++i)
		ans += solve(i);

	printf("%lld\n", ans);
	return 0;
}