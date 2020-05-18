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

inline ll read() {	ll x;   cin >> x;   return x;   }


typedef pair<ll, int> node;

const int MAX_N = 2e5 + 5;
const ll oo = 1e18;


int n;
int x[MAX_N], y[MAX_N], id[MAX_N];
vector<pii> e[MAX_N];
ll d[MAX_N];
set<node> heap;


bool cmpX(int i, int j) {
	if (x[i] != x[j]) return x[i] < x[j];
	if (y[i] != y[j]) return y[i] < y[j];
	return i < j;
}


bool cmpY(int i, int j) {
	if (y[i] != y[j]) return y[i] < y[j];
	if (x[i] != x[j]) return x[i] < x[j];
	return i < j;
}


inline void addEdge(int i, int j) {
	int u = id[i], v = id[j];
	e[u].push_back(pii(min(abs(x[u]-x[v]), abs(y[u]-y[v])), v));
}


ll dijkstra() {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[1] = 0;
	heap.clear();
	heap.insert(node(0, 1));
	while (!heap.empty()) {
		int u = heap.begin()->sc;
		if (u == n) break;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v = it->sc;
			ll tmp = d[u] + it->fr;
			if (tmp >= d[v]) continue;
			set<node>::iterator p = heap.find(node(d[v], v));
			if (p != heap.end()) heap.erase(p);
			d[v] = tmp;
			heap.insert(node(d[v], v));
		}
	}
	return d[n];
}


int main() {
#ifdef DEBUG
	freopen("amppz_2014_kap.in", "r", stdin);
	freopen("amppz_2014_kap.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		id[i-1] = i;
	}

	sort(id, id+n, cmpX);
	for (int i = 1; i < n; ++i) {
		addEdge(i-1, i);
		addEdge(i, i-1);
	}
	sort(id, id+n, cmpY);
	for (int i = 1; i < n; ++i) {
		addEdge(i-1, i);
		addEdge(i, i-1);
	}

	cout << dijkstra() << '\n';

	return 0;
}