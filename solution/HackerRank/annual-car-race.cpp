// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 501;
const int MAX_M = sqr(MAX_N) / 2 + 1;
const int oo = 1e9;


int n, m, s, t;
int cost[MAX_M], d[MAX_N], trace[MAX_N];
pii edge[MAX_M];
vector<int> e[MAX_N];
bool ok[MAX_M];
set<pii> heap;


inline int getVexter(int i, int u) {
	return u == edge[i].first ? edge[i].second : edge[i].first;
}


void dijkstra() {
	for (int i = 1; i <= n; ++i) d[i] = oo;
	d[s] = 0;
	heap.clear();
	heap.insert(mp(d[s], s));
	while (!heap.empty()) {
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		if (u == t) break;
		foreach(it, e[u]) if (ok[*it]) {
			int v = getVexter(*it, u);
			int tmp = d[u] + cost[*it];
			if (tmp < d[v]) {
				heap.erase(mp(d[v], v));
				d[v] = tmp;
				heap.insert(mp(d[v], v));
				trace[v] = *it;
			}
		}
	}
}


void removePaths(int val) {
	while (d[t] == val) {
		int u = t;
		while (u != s) {
			int i = trace[u];
			ok[i] = 0;
			u = getVexter(i, u);
		}
		dijkstra();
	}
}


int main() {
#ifdef DEBUG
	freopen("annual-car-race.in", "r", stdin);
	freopen("annual-car-race.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> n >> m;
		cin >> s >> t;
		++s, ++t;
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < m; ++i) {
			int x, y, val;
			cin >> x >> y >> val;
			edge[i] = make_pair(++x, ++y);
			cost[i] = val;
			ok[i] = 1;
			e[x].push_back(i);
			e[y].push_back(i);
		}
		for (int i = 0; i < 2; ++i) {
			dijkstra();
			removePaths(d[t]);
		}
		dijkstra();
		cout << (d[t] >= oo ? -1 : d[t]) << endl;
	}

	return 0;
}