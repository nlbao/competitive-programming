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


const int MAX_N = 1e5 + 5;


int n, m, maxA;
int a[MAX_N], p[MAX_N], g[MAX_N];
vector<int> b[MAX_N], e[MAX_N];
bool ok[MAX_N];


int getRoot(int u) {
	return p[u] < 1 ? u : p[u] = getRoot(p[u]);
}


inline void merge(int u, int v) {
	u = getRoot(u);
	v = getRoot(v);
	if (u == v) return;
	p[u] = v;
	g[v] = __gcd(g[v], g[u]);
	ok[g[v]] = true;
}


void update(int newValue, int old) {
	foreach(it, b[newValue]) {
		ok[newValue] = true;
		p[*it] = -1;
		g[*it] = newValue;
	}
	foreach(it, b[newValue]) {
		int u = *it;
		foreach(it2, e[u]) {
			int v = *it2;
			if (a[v] % old == 0) {
				ok[a[v]] = true;
				merge(u, v);
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("6825.in", "r", stdin);
	freopen("6825.out", "w", stdout);
#endif
	while (scanf("%d%d", &n, &m) == 2) {
		maxA = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			maxA = max(maxA, a[i]);
			e[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (a[x] < a[y]) swap(x, y);
			e[x].push_back(y);
		}

		for (int i = 1; i <= maxA; ++i) {
			ok[i] = false;
			b[i].clear();
		}
		for (int i = 1; i <= n; ++i)
			b[a[i]].push_back(i);
		for (int i = 1; i <= maxA; ++i) {
			if (ok[i]) continue;
			for (int j = i; j <= maxA; j += i) {
				update(j, i);
				if (ok[i]) break;
			}
		}

		int ans = 0;
		for (int i = 1; i <= maxA; ++i)
			if (ok[i]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}