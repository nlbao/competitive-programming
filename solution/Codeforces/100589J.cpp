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


int n[3];
int a[3][MAX_N];
ll f[3][MAX_N];


int main() {
#ifdef DEBUG
	freopen("100589J.in", "r", stdin);
	freopen("100589J.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &n[i]);
			for (int k = 0; k < n[i]; ++k)
				scanf("%d", &a[i][k]);
		}
		for (int k = 0; k < n[2]; ++k)
			f[2][k] = 1;
		for (int i = 1; i >= 0; --i) {
			ll s = 0;
			int x = n[i+1]-1;
			for (int k = n[i]-1; k >= 0; --k) {
				while (x >= k && a[i+1][x] >= a[i][k]) {
					s += f[i+1][x];
					--x;
				}
				f[i][k] = s;
			}
		}
		ll ans = 0;
		for (int i = 0; i < n[0]; ++i)
			ans += f[0][i];
		printf("%lld\n", ans);
	}
	return 0;
}