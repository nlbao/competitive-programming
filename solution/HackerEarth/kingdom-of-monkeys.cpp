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


int n, m;
ll a[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];


ll dfs(int u) {
	ok[u] = false;
	ll ans = a[u];
	foreach(it, e[u]) {
		int v = *it;
		if (ok[v])
			ans += dfs(v);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("kingdom-of-monkeys.in", "r", stdin);
	freopen("kingdom-of-monkeys.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		filla(ok, true);
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			if (ok[i])
				ans = max(ans, dfs(i));
		printf("%lld\n", ans);
	}
	return 0;
}