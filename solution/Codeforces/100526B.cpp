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


const int MAX_N = 22;
const int MAX_A = 3600;
const int oo = 1e9;


int n, nTime;
int a[MAX_N], d[MAX_A];
set<pii> heap;


void solve() {
	for (int x = 0; x <= MAX_A; ++x)
		d[x] = oo;
	d[0] = 0;
	heap.clear();
	heap.insert(pii(d[0], 0));
	while (!heap.empty()) {
		set<pii>::iterator it = heap.begin();
		int u = it->second, tmp = d[u]+1;
		heap.erase(it);
		for (int i = 1; i <= n; ++i) {
			int v = u + a[i];
			v = min(v, MAX_A);
			v = max(v, 0);
			if (tmp < d[v]) {
				it = heap.find(pii(d[v], v));
				if (it != heap.end())
					heap.erase(it);
				d[v] = tmp;
				heap.insert(pii(d[v], v));
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("100526B.in", "r", stdin);
	freopen("100526B.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &nTime);
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		sort(a+1, a+1+n);
		int m = 0;
		for (int i = 1; i <= n; ++i)
			if (i == 1 || a[i] != a[i-1])
				a[++m] = a[i];
		n = m;
		solve();
		int u = -1, t = oo;
		for (int x = nTime; x <= MAX_A; ++x)
			if (d[x] < oo) {
				t = d[x];
				u = x;
				break;
			}
		printf("%d %d\n", t, u-nTime);
	}
	return 0;
}