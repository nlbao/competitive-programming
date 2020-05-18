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
const int MAX_M = 333;


int n, m, nTime;
int start[MAX_N], finish[MAX_N], id[MAX_N], h[MAX_N], p[MAX_N];
vector<int> e[MAX_N];
ll f[MAX_M], value[MAX_N];
int c[MAX_M][MAX_N], x[MAX_M], y[MAX_M];


void dfs(int u) {
	start[u] = ++nTime;
	id[nTime] = u;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != 0) continue;
		p[v] = u;
		h[v] = h[u]+1;
		dfs(v);
	}
	finish[u] = nTime;
}


void update(int w, ll val) {
	value[w] += val;
	for (int i = 1; i <= m; ++i)
		f[i] += val * c[i][w];
}


ll get(int u) {
	ll ans = 0;
	int l = start[u], r = finish[u];
	for (int i = 1; i <= m; ++i) {
		if (y[i] < l) continue;
		if (x[i] > r) break;
		if (l <= x[i] && y[i] <= r) {
			ans += f[i];
			continue;
		}
		for (int k = max(x[i], l); k <= min(y[i], r); ++k)
			ans += value[h[id[k]]];
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100589A.in", "r", stdin);
	freopen("100589A.out", "w", stdout);
#endif
	int nQ;
	scanf("%d%d", &n, &nQ);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	nTime = 0;
	filla(p, 0);
	p[1] = -1, h[1] = 1;
	dfs(1);

	int len = sqrt(n);
	filla(f, 0);
	filla(c, 0);
	filla(value, 0);
	m = 0;
	for (int i = 1, j; i <= n; i = j+1) {
		j = min(i+len-1, n);
		++m;
		x[m] = i, y[m] = j;
		for (int k = i; k <= j; ++k)
			++c[m][h[id[k]]];
	}

	while (nQ--) {
		int types = read();
		if (types == 1) {
			int l, y;
			scanf("%d%d", &l, &y);
			update(l+1, y);
		}
		else {
			int x = read();
			printf("%lld\n", get(x));
		}
	}
	return 0;
}