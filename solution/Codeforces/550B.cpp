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


const int MAX_N = 18;


int n, l, r, x;
int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("550B.in", "r", stdin);
	freopen("550B.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; ++i)
		a[i] = read();

	int ans = 0, m = 1<<n;
	for (int mask = 0; mask < m; ++mask) {
		ll s = 0;
		int minA = 1e9, maxA = -1, c = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1<<i)) {
				++c;
				s += a[i];
				minA = min(minA, a[i]);
				maxA = max(maxA, a[i]);
			}
		if (c > 1 && l <= s && s <= r && maxA - minA >= x)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}