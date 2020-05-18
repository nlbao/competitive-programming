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


const int MAX_N = 111;


int a[MAX_N], c[MAX_N], cost[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100703M.in", "r", stdin);
	freopen("100703M.out", "w", stdout);
#endif
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) c[i] = read();
	for (int i = 1; i <= n; ++i) cost[i] = read();
	int ans = 0, m = 0;
	for (int i = 1; i <= n; ++i) {
		int x = a[i] / c[i];
		if (a[i]%c[i] != 0) ++x;
		m = max(m, x);
	}
	for (int i = 1; i <= n; ++i) {
		ans += cost[i] * (m*c[i] - a[i]);
	}
	printf("%d\n", ans);
	return 0;
}