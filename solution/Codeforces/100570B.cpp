#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


typedef pair<ll, int> node;


const int MAX_N = 1e5 + 55;
const ll oo = 1e18;


struct Edge {
	int u, v, w, c;
	Edge(int u, int v, int w, int c) : u(u), v(v), w(w), c(c) {}
};


int n, m, nC;
vector<Edge> e[MAX_N];
ll d[MAX_N][2];
int color[MAX_N][2];
multiset<node> heap;


inline void sub_update(int u, int i, int col, ll val) {
	if (col == -1 || val >= oo) return;
	multiset<node>::iterator it = heap.find(node(d[u][i], u));
	if (it != heap.end())
		heap.erase(it);
	d[u][i] = val;
	color[u][i] = col;
	heap.insert(node(d[u][i], u));
}


inline void update(int u, int col, ll val) {
	if (val >= d[u][1]) return;
	if (val < d[u][0]) {
		if (col != color[u][0])
			sub_update(u, 1, color[u][0], d[u][0]);
		sub_update(u, 0, col, val);
		return;
	}
	if (col == color[u][0]) return;
	sub_update(u, 1, col, val);
}


void dijkstra(int s) {
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j) {
			d[i][j] = oo;
			color[i][j] = -1;
		}
	heap.clear();
	update(s, 0, 0);
	while (!heap.empty()) {
		ll dist = heap.begin()->first;
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		for (int i = 0; i < 2; ++i) {
			if (color[u][i] < 0) continue;
			if (d[u][i] > dist) continue;
			foreach(it, e[u]) {
				int v = it->v, col = it->c;
				if (col == color[u][i]) continue;
				update(v, col, dist + it->w);
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("100570B.in", "r", stdin);
	freopen("100570B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> nC;
	for (int i = 0; i < m; ++i) {
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		e[u].push_back(Edge(u, v, w, c));
	}
	int s = read();
	dijkstra(s);

	int nQ = read();
	while (nQ--) {
		int t;
		cin >> t;
		ll ans = min(d[t][0], d[t][1]);
		if (ans >= oo) ans = -1;
		cout << ans << endl;
	}

	return 0;
}