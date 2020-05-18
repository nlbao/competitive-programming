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


const int MAX_N = 1e3 + 3;
const int MAX_K = 55;
const int MAX_A = 55;
const ll oo = 1e16;


int n, m, k;
int a[MAX_K], fav[MAX_N], deg[MAX_N];
ll d[MAX_A], limit[MAX_N];
set<pii> heap;
vector<int> e[MAX_N];
queue<int> q;


void init() {
	m = a[0];
	for (int i = 1; i < k; ++i)
		m = min(m, a[i]);
	for (int i = 0; i < m; ++i) d[i] = oo;
	d[0] = 0;
	heap.clear();
	heap.insert(pii(0, 0));
	while (!heap.empty()) {
		pii p = *heap.begin();
		heap.erase(heap.begin());
		int u = p.second;
		for (int i = 0; i < k; ++i) {
			int v = (u+a[i])%m;
			int tmp = d[u] + a[i];
			if (tmp < d[v]) {
				set<pii>::iterator it = heap.find(pii(d[v], v));
				if (it != heap.end())
					heap.erase(it);
				d[v] = tmp;
				heap.insert(pii(d[v], v));
			}
		}
	}
}


inline bool check(ll x) {
	if (x == 0) return true;
	if (x < m) return false;
	if (x == m) return true;
	return d[x % m] <= x;
}


void addEdge(int u, int v) {
	e[u].push_back(v);
	++deg[v];
}


int main() {
#ifdef DEBUG
	freopen("ANKMARKS.in", "r", stdin);
	freopen("ANKMARKS.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		for (int i = 1; i <= n; ++i)
			fav[i] = read();
		k = read();
		for (int i = 0; i < k; ++i)
			a[i] = read();

		init();

		ll sum = 0;
		filla(deg, 0);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1; i <= n; ++i) {
			if (i > 1 && fav[i] > fav[i-1]) addEdge(i-1, i);
			if (i < n && fav[i] > fav[i+1]) addEdge(i+1, i);
		}

		// topo
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; ++i)
			if (deg[i] == 0)
				q.push(i);
		filla(limit, 0);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			ll ans = -1;
			for (ll x = limit[u]; ans == -1; ++x)
				if (check(x))
					ans = x;
			sum += ans;
			ll t = (ans == 0) ? m : 2LL*ans + 1;
			foreach(it, e[u]) {
				int v = *it;
				--deg[v];
				limit[v] = max(limit[v], t);
				if (deg[v] == 0)
					q.push(v);
			}
		}
		printf("%.6lf\n", 1.0 * sum / n);
	}
	return 0;
}