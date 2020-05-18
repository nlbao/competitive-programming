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


const int MAX_N = 1e5 + 5;


int c[MAX_N], a[MAX_N];
bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("SUMPAIR.in", "r", stdin);
	freopen("SUMPAIR.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, d;
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);

		ll ans = 0;
		filla(ok, true);
		for (int i = n-1, j = i; j >= 0; --i) {
			if (!ok[i]) continue;
			while (j >= 0 && (j >= i || !ok[j])) --j;
			if (j < 0) break;
			if (a[i]-a[j] < d) {
				ans += a[i] + a[j];
				ok[i] = ok[j] = false;
				--j;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}