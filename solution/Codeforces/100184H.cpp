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
const int MAX_F = 4*MAX_N;


int n, u, v, nTime;
vector<pii> e[MAX_N];
ll value, cost[MAX_N], d[MAX_N], f[MAX_F];
int start[MAX_N], finish[MAX_N], c[MAX_N], p[MAX_N];
map<ll, vector<int> > listPos;


ll get(int k, int l, int r) {
	if (l > u || r < u) return 0;
	if (l == r) return f[k];
	int mid = (l+r)>>1;
	int pl = k<<1, pr = pl+1;
	return max(f[k], max(get(pl, l, mid), get(pr, mid+1, r)));
}


void update(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		f[k] = max(f[k], value);
		return;
	}
	int mid = (l+r)>>1;
	int pl = k<<1, pr = pl+1;
	update(pl, l, mid);
	update(pr, mid+1, r);
}


void newUpdate(int l, int r, ll val) {
	if (l > r) return;
	u = l, v = r;
	value = val;
	update(1, 1, n);
}


void dfs(int u) {
	start[u] = ++nTime;
	c[u] = 1;
	foreach(it, e[u]) {
		int v = it->second;
		if (p[v] != 0) continue;
		p[v] = u;
		cost[v] = it->first;
		dfs(v);
		c[u] += c[v];
	}
	finish[u] = nTime;

	if (p[u] == -1) return;
	int l = start[u], r = finish[u];
	newUpdate(l, r, cost[u] * (n-c[u]));
	newUpdate(1, l-1, cost[u] * c[u]);
	newUpdate(r+1, n, cost[u] * c[u]);
}


inline ll getCnt(ll x, int l, int r) {
	if (l > r) return 0;
	map<ll, vector<int> >::iterator it = listPos.find(x);
	if (it == listPos.end()) return 0;
	vector<int> &t = it->second;
	return int(lower_bound(t.begin(), t.end(), r+1) - lower_bound(t.begin(), t.end(), l));
}


int main() {
#ifdef DEBUG
	freopen("100184H.in", "r", stdin);
	freopen("100184H.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		e[x].push_back(pii(c, y));
		e[y].push_back(pii(c, x));
	}

	nTime = 0;
	filla(f, 0);
	filla(p, 0);
	p[1] = -1;
	dfs(1);

	for (int i = 1; i <= n; ++i) {
		u = start[i];
		ll x = get(1, 1, n);
		listPos[x].push_back(u);
	}
	foreach(it, listPos)
		sort(it->second.begin(), it->second.end());

	ll ans = 0;
	for (int u = 1; u <= n; ++u) {
		if (p[u] == -1) continue;
		int l = start[u], r = finish[u];
		ll x = cost[u] * (n-c[u]), y = cost[u] * c[u];
		ll cnt = getCnt(x, l, r);
		cnt += getCnt(y, 1, l-1);
		cnt += getCnt(y, r+1, n);
		ans = max(ans, cnt);
	}
	printf("%lld\n", ans);
	return 0;
}