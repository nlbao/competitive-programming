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
const ll oo = 1e18;


int n;
vector<pii> e[MAX_N];
ll d[MAX_N], g[MAX_N];
bool police[MAX_N], booster[MAX_N];

typedef pair<ll, int> node;
set<node> heap;


void dijkstra(int s) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[s] = 0;
	heap.clear();
	heap.insert(node(d[s], s));

	while (!heap.empty()) {
		set<node>::iterator p = heap.begin();
		int u = p->second;
		ll dist = p->first;
		heap.erase(p);
		foreach(it, e[u]) {
			int v = it->second;
			ll tmp = dist + it->first;
			if (tmp < d[v]) {
				p = heap.find(node(d[v], v));
				if (p != heap.end())
					heap.erase(p);
				d[v] = tmp;
				heap.insert(node(d[v], v));
			}
		}
	}
}


bool check(ll limit) {
	heap.clear();
	for (int i = 1; i <= n; ++i) {
		if (booster[i]) {
			d[i] = g[i];
			heap.insert(node(d[i], i));
		}
		else d[i] = oo;
	}

	while (!heap.empty()) {
		set<node>::iterator p = heap.begin();
		int u = p->second;
		ll dist = p->first;
		heap.erase(p);

		if (dist > limit) return false;
		if (police[u]) return true;

		foreach(it, e[u]) {
			int v = it->second;
			ll tmp = dist + 2LL * it->first;
			if (tmp < d[v]) {
				p = heap.find(node(d[v], v));
				if (p != heap.end())
					heap.erase(p);
				d[v] = tmp;
				heap.insert(node(d[v], v));
			}
		}
	}
	return false;
}


int main() {
#ifdef DEBUG
	freopen("100589K.in", "r", stdin);
	freopen("100589K.out", "w", stdout);
#endif
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		++x, ++y;
		e[x].push_back(pii(c, y));
		e[y].push_back(pii(c, x));
	}

	filla(police, false);
	m = read();
	for (int i = 0; i < m; ++i)
		police[read()+1] = true;
	filla(booster, false);
	m = read();
	for (int i = 0; i < m; ++i)
		booster[read()+1] = true;

	int s = read()+1, t = read()+1;
	dijkstra(t);
	if (d[s] >= oo) {
		printf("-1\n");
		return 0;
	}

	ll minDist = 2LL*d[s];
	for (int i = 1; i <= n; ++i)
		g[i] = d[i];
	booster[t] = true;
	if (check(minDist)) printf("-1\n");
	else printf("%lld\n", minDist / 2LL);
	return 0;
}