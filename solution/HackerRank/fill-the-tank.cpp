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


const int MAX_N = 55;
const int MAX_A = 1e6 + 6;
const ll oo = 1e16;
const ll LIMIT = 1e9 + 4;


int n, m;
int a[MAX_N];
ll d[MAX_A];
set<pii> heap;


void init() {
	m = a[0];
	for (int i = 1; i < n; ++i)
		m = min(m, a[i]);

	for (int i = 0; i < m; ++i) d[i] = oo;
	d[0] = 0;
	heap.clear();
	heap.insert(pii(0, 0));
	while (!heap.empty()) {
		pii p = *heap.begin();
		heap.erase(heap.begin());
		int u = p.second;
		if (d[u] >= LIMIT) break;
		for (int i = 0; i < n; ++i) {
			int v = (u+a[i]) % m;
			ll tmp = d[u] + a[i];
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


bool solve(ll c) {
	return d[c%m] <= c;
}


int main() {
#ifdef DEBUG
	freopen("fill-the-tank.in", "r", stdin);
	freopen("fill-the-tank.out", "w", stdout);
#endif
	int nQ;
	scanf("%d%d", &n, &nQ);
	for (int i = 0; i < n; ++i)
		a[i] = read();
	init();
	while (nQ--) {
		int c = read();
		if (solve(c)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}