#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> node;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

inline ll read() {	ll x;   cin >> x;	return x;   }


const int MAX_N = 1e3 + 33;
const ll oo = 1e18;
const ll LIMIT = 1e17;


int n, m, start, dest;
vector<pii> e[MAX_N];
bool isMyBank[MAX_N];
ll d[MAX_N][MAX_N][2], f[MAX_N], g[MAX_N];
queue<node> q;
bool inQ[MAX_N][MAX_N][2];


inline void push(int i, int j, int k) {
	if (inQ[i][j][k]) return;
	inQ[i][j][k] = true;
	q.push(node(i, pii(j, k)));
}


void bellman() {
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 2; ++k) {
				d[i][j][k] = oo;
				inQ[i][j][k] = false;
			}
	d[start][0][0] = 0;
	while (!q.empty()) q.pop();
	push(start, 0, 0);
	while (!q.empty()) {
		node p = q.front();	q.pop();
		int u = p.first, j = p.second.first, k = p.second.second;
		foreach(it, e[u]) {
			int v = it->second;
			ll tmp = d[u][j][k] + it->first;
			int jj = j+1;
			int kk = k | int(!isMyBank[v]);
			if (tmp >= d[v][jj][kk]) continue;
			d[v][jj][kk] = tmp;
			push(v, jj, kk);
		}
	}
}

ll solve() {
	bellman();
	for (int i = 0; i < n; ++i) {
		f[i] = d[dest][i][0];
		g[i] = d[dest][i][1];
	}

	bool ck = false;
	for (int i = 0; i < n; ++i)
		if (f[i] < oo) {
			ck = true;
			break;
		}
	if (!ck) return -1;

	int i = 0, j = 0;
	while (i < n && f[i] >= oo) ++i;
	while (j < n && g[j] >= oo) ++j;
	if (i < j) return oo;

	ll ans = -1;
	for (int i = 0; i < n; ++i) {
		if (f[i] >= oo) continue;
		ll a = 1, b = oo;
		for (int j = 0; j < n; ++j) {
			if (g[j] >= oo) continue;
			ll x = g[j]-f[i];
			ll y = i-j;
			if (y == 0) {
				if (g[j] <= f[i]) {
					a = oo, b = -1;
					break;
				}
			}
			else if (y > 0) {
				ll t = x / y;
				if (x%y == 0) --t;
				b = min(b, t);
			}
			else {
				ll t = x/y;
				if (x%y == 0) ++t;
				a = max(a, t);
			}
		}
		if (a <= b) ans = max(ans, b);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6891.in", "r", stdin);
	freopen("6891.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	while (cin >> n >> m >> start >> dest) {
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			isMyBank[i] = false;
		}
		for (int i = 0; i < m; ++i) {
			int x, y, c;
			cin >> x >> y >> c;
			e[x].push_back(pii(c, y));
			e[y].push_back(pii(c, x));
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
			isMyBank[read()] = true;
		ll ans = solve();
		if (ans < 0) cout << "Impossible\n";
		else if (ans >= LIMIT) cout << "Infinity\n";
		else cout << ans << '\n';
	}
	return 0;
}