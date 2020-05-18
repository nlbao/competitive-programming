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
typedef pair<ll, pii> Edge;
typedef pair<pii, pii> Query;


const int MAX_N = 2e5 + 5;
const int oo = 2e9 + 99;


int n, nA, m;
int a[MAX_N], src[MAX_N], p[MAX_N];
ll d[MAX_N];
set<node> heap;
vector<pii> e[MAX_N];
Edge edges[MAX_N];
Query q[MAX_N];
bool ans[MAX_N];


inline int getRoot(int u) {
	return p[u] == u ? u : p[u] = getRoot(p[u]);
}


void dijktra() {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	for (int i = 0; i < nA; ++i) {
		int u = a[i];
		d[u] = 0;
		src[u] = u;
		heap.insert(node(0, u));
	}
	set<node>::iterator p;
	while (!heap.empty()) {
		int u = heap.begin()->sc;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v = it->sc;
			ll tmp = d[u] + it->fr;
			if (tmp >= d[v]) continue;
			p = heap.find(node(d[v], v));
			if (p != heap.end()) heap.erase(p);
			d[v] = tmp;
			src[v] = src[u];
			heap.insert(node(d[v], v));
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("amppz_2014_ben.in", "r", stdin);
	freopen("amppz_2014_ben.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n >> nA >> m;
	for (int i = 0; i < nA; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		e[x].push_back(pii(c, y));
		e[y].push_back(pii(c, x));
	}

	dijktra();

	m = 0;
	for (int u = 1; u <= n; ++u) {
		if (d[u] >= oo) continue;
		int x = src[u];
		foreach(it, e[u]) {
			int v = it->sc, y = src[v];
			if (x >= y) continue;
			edges[m++] = Edge(d[u] + it->fr + d[v], pii(x, y));
		}
	}
	sort(edges, edges+m);

	int nQ = read();
	for (int i = 0; i < nQ; ++i) {
		int c, u, v;
		cin >> u >> v >> c;
		q[i] = Query(pii(c, i), pii(u, v));
	}
	sort(q, q+nQ);

	for (int i = 0; i < nA; ++i)
		p[a[i]] = a[i];
	for (int i = 0, j = 0; i < nQ; ++i) {
		int w = q[i].fr.fr;
		int id = q[i].fr.sc;
		while (j < m && edges[j].fr <= w) {
			p[getRoot(edges[j].sc.fr)] = getRoot(edges[j].sc.sc);
			++j;
		}
		ans[id] = getRoot(q[i].sc.fr) == getRoot(q[i].sc.sc);
	}
	for (int i = 0; i < nQ; ++i)
		if (ans[i]) cout << "TAK\n";
		else cout << "NIE\n";

	return 0;
}