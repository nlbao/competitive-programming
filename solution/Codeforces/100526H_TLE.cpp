#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pii> Node;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e3 + 33;
const int MAX_P = 1e2 + 25;
const int MAX_LIMIT = 1e5 + 5;
const ll oo = 1e18;


int n, m, nP, start, dest, limit;
vector<pii> e[MAX_N], e2[MAX_N];
int cost[MAX_N];
ll d[MAX_N], f[MAX_P][MAX_LIMIT];
bool petrol[MAX_N];
set<Node> heap;
set<pii> heap0;

int id[MAX_N];
ll minF[MAX_P][MAX_LIMIT];


void dijkstra(int s) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[s] = 0;
	heap0.clear();
	heap0.insert(pii(d[s], s));
	while (!heap0.empty()) {
		int u = heap0.begin()->sc;
		heap0.erase(heap0.begin());
		foreach(it, e[u]) {
			int v = it->sc;
			ll tmp = d[u] + it->fr;
			if (tmp >= d[v]) continue;
			set<pii>::iterator p = heap0.find(pii(d[v], v));
			if (p != heap0.end())
				heap0.erase(p);
			d[v] = tmp;
			heap0.insert(pii(d[v], v));
		}
	}
}


inline void update_minF(int i, int j, ll value) {
	i = id[i];
	j = limit+1-j;
	while (j <= limit) {
		minF[i][j] = min(minF[i][j], value);
		j += lowbit(j);
	}
}


inline ll get_minF(int i, int j) {
	i = id[i];
	j = limit+1-j;
	ll ans = oo;
	while (j > 0) {
		ans = min(ans, minF[i][j]);
		j -= lowbit(j);
	}
	return ans;
}


inline void update(int u, int k, ll value) {
	if (k < 0 || k > limit) return;
	if (value >= f[u][k]) return;

	ll tmp = get_minF(u, k+1);
	if (tmp <= value) return;

	set<Node>::iterator it = heap.find(Node(f[u][k], pii(u, k)));
	if (it != heap.end())
		heap.erase(it);
	f[u][k] = value;
	heap.insert(Node(f[u][k], pii(u, k)));

	update_minF(u, k, f[u][k]);
}


ll solve() {
	nP = 0;
	for (int i = 1; i <= n; ++i) {
		e2[i].clear();
		if (!petrol[i]) continue;
		dijkstra(i);
		for (int j = 1; j <= n; ++j)
			if (i != j && petrol[j] && d[j] < oo)
				e2[i].push_back(pii(d[j], j));
		id[i] = ++nP;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= limit+1; ++j)
			minF[i][j] = oo;
	// update_minF(start, 0, 0);

	for (int i = 1; i <= n; ++i)
		if (petrol[i])
			for (int j = 0; j <= limit; ++j)
				f[i][j] = oo;
	heap.clear();
	update(start, 0, 0);

	while (!heap.empty()) {
		Node p = *heap.begin();
		heap.erase(heap.begin());
		int u = p.sc.fr, k = p.sc.sc;
		ll tmp = p.fr;
		if (u == dest) return p.fr;
		if (k < limit && f[u][k] >= f[u][k+1]) continue;
		update(u, k+1, f[u][k]+cost[u]);
		foreach(it, e2[u])
			update(it->sc, k - it->fr, tmp);
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("100526H.in", "r", stdin);
	freopen("100526H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> n >> m >> nP;
		cin >> limit;
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			petrol[i] = false;
		}
		while (m--) {
			int x, y, c;
			cin >> x >> y >> c;
			e[x].push_back(pii(c, y));
			e[y].push_back(pii(c, x));
		}
		while (nP--) {
			int x, c;
			cin >> x >> c;
			petrol[x] = true;
			cost[x] = c;
		}
		cin >> start >> dest;
		petrol[dest] = true;
		cost[dest] = 0;
		cout << solve() << endl;
	}

	return 0;
}