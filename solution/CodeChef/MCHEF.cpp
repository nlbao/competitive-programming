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
const int MAX_K = 505;


int n, m, k;
int a[MAX_N], l[MAX_N], r[MAX_N], c[MAX_N];
int id[MAX_N], p[MAX_N], cost[MAX_N];
pii b[MAX_N];
ll f[2][MAX_K];


int getNext(int u) {
	if (p[u] == u) return u;
	return p[u] = getNext(p[u]);
}


bool cmp(int i, int j) {
	return c[i] < c[j];
}


inline void update(int l, int r, int c) {
	l = getNext(l);
	for (int i = l; i <= r; ++i) {
		i = getNext(i);
		if (i > r) break;
		cost[i] = c;
		p[i] = i+1;
	}
}


ll solve() {
	int t = 0;
	filla(f, 0);
	for (int i = 0; i < n; ++i) {
		int tt = t;
		t ^= 1;
		ll w = b[i].first, cost = b[i].second;
		for (int x = 0; x < cost; ++x) f[t][x] = f[tt][x];
		for (int x = cost; x <= k; ++x)
			f[t][x] = max(f[tt][x], f[tt][x-cost] + w);
	}
	ll ans = 0;
	for (int i = 0; i <= k; ++i)
		ans = max(ans, f[t][i]);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("MCHEF.in", "r", stdin);
	freopen("MCHEF.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &l[i], &r[i], &c[i]);
			id[i] = i;
		}
		sort(id, id+m, cmp);
		for (int i = 1; i <= n+1; ++i) {
			p[i] = i;
			cost[i] = k+1;
		}
		for (int i = 0; i < m; ++i) {
			int x = id[i];
			update(l[x], r[x], c[x]);
		}

		m = 0;
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += a[i];
			if (a[i] < 0 && cost[i] <= k)
				b[m++] = pii(-a[i], cost[i]);
		}
		n = m;
		printf("%lld\n", sum + solve());
	}
	return 0;
}