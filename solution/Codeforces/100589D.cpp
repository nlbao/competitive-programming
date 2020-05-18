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
const int MAX_LOG = 20;
const double EPS = 1e-13;


int n, m, nTime, logN;
vector<pii> e[MAX_N];
int p[MAX_N][MAX_LOG];
int h[MAX_N], d[MAX_N], root[MAX_N], start[MAX_N], finish[MAX_N];
int pos[MAX_N], s[MAX_N], deg[MAX_N], a[MAX_N];
bool isCycle[MAX_N];
queue<int> q;


void dfs(int u) {
	start[u] = ++nTime;
	for (int i = 1; i <= logN; ++i)
		if (h[u] - (1<<i) > 0)
			p[u][i] = p[p[u][i-1]][i-1];
		else
			p[u][i] = -1;
	foreach(it, e[u]) {
		int v = it->second;
		if (isCycle[v] || p[v][0] != 0) continue;
		p[v][0] = u;
		h[v] = h[u]+1;
		d[v] = d[u] + it->first;
		root[v] = root[u];
		dfs(v);
	}
	finish[u] = nTime;
}


inline bool isAncestor(int u, int v) {
	return start[u] <= start[v] && finish[v] <= finish[u];
}


int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	if (h[u] > h[v])
		for (int i = logN; i >= 0; --i)
			if (h[u] - (1<<i) >= h[v])
				u = p[u][i];
	if (u == v) return u;
	for (int i = logN; i >= 0; --i)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}


ll dist(int u, int v) {
	if (u == v) return 0;
	if (root[u] == root[v])
		return d[u] + d[v] - 2LL*d[lca(u, v)];
	int i = pos[root[u]], j = pos[root[v]];
	ll t = abs(s[j]-s[i]);
	return min(t, s[m] - t) + d[u] + d[v];
}


// inline bool cmp(double d1, double v1, double d2, double v2) {
// 	return (d1/v1) + EPS < (d2/v2);
// }


inline bool cmp(ll d1, ll v1, ll d2, ll v2) {
	return v2 * d1 < v1 * d2;
}


bool check(int s1, int t, int s2, ll v1, ll v2) {
	if (!cmp(dist(s1, t), v1, dist(s2, t), v2)) return false;
	if (v1 <= v2) return true;

	if (root[s1] == root[t]) {
		int r = lca(s1, t);
		if (isAncestor(r, s2)) {
			// case 1
			int r1 = lca(s2, s1), r2 = lca(s2, t);
			if (h[r2] > h[r1]) r = r2;
			else r = r1;
			return cmp(dist(s1, r), v1, dist(s2, r), v2);
		}
		// case 2
		return cmp(dist(s1, r), v1, dist(s2, r), v2);
	}

	// case 3
	if (root[s1] == root[s2]) {
		int r = lca(s1, s2);
		return cmp(dist(s1, r), v1, dist(s2, r), v2);
	}
	if (root[t] == root[s2]) {
		int r = lca(t, s2);
		return cmp(dist(s1, r), v1, dist(s2, r), v2);
	}

	// case 4
	if (!cmp(dist(s1, root[s1]), v1, dist(s2, root[s1]), v2))
		return false;
	if (cmp(dist(s1, root[s2]), v1, dist(s2, root[s2]), v2))
		return true;
	int i = pos[root[s1]], j = pos[root[t]], k = pos[root[s2]];
	if (i > j) swap(i, j);
	ll tmp = s[j] - s[i];
	if (i < k && k < j) tmp = s[m] - tmp;
	ll d1 = d[s2] + tmp;
	ll d2 = dist(s2, root[t]);
	return cmp(d1, v1, d2, v2);
}


int main() {
#ifdef DEBUG
	freopen("100589D.in", "r", stdin);
	freopen("100589D.out", "w", stdout);
#endif
	int nQ;
	scanf("%d%d", &n, &nQ);
	filla(deg, 0);
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		e[x].push_back(pii(c, y));
		e[y].push_back(pii(c, x));
		++deg[x], ++deg[y];
	}

	// detect cycle
	filla(isCycle, true);
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 1) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		isCycle[u] = false;
		foreach(it, e[u]) {
			int v = it->second;
			--deg[v];
			if (deg[v] == 1)
				q.push(v);
		}
	}

	m = 0;
	s[0] = 0;
	filla(deg, 0);
	for (int i = 1; i <= n; ++i)
		if (isCycle[i]) {
			int u = i;
			pos[u] = ++m, a[m] = u, s[m] = 0;
			while (u != -1) {
				deg[u] = 1;
				int v = -1;
				foreach(it, e[u]) {
					v = it->second;
					if (!isCycle[v] || deg[v] == 1) {
						v = -1;
						continue;
					}
					pos[v] = ++m, a[m] = v, s[m] = s[m-1] + it->first;
					break;
				}
				u = v;
			}
			u = a[m];
			foreach(it, e[u]) {
				int v = it->second;
				if (v != i) continue;
				++m, a[m] = v, s[m] = s[m-1] + it->first;
				break;
			}
			break;
		}

	// dfs, lca
	nTime = 0;
	logN = 0;
	while ((1<<(logN+1)) <= n) ++logN;
	filla(p, 0);
	filla(d, 0);
	for (int i = 1; i <= n; ++i)
		if (isCycle[i]) {
			p[i][0] = -1;
			h[i] = 1;
			root[i] = i;
			dfs(i);
		}

	// solve
	while (nQ--) {
		int s1, t, s2, v1, v2;
		scanf("%d%d%d%d%d", &s1, &t, &s2, &v1, &v2);
		if (check(s1, t, s2, v1, v2)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}