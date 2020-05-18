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


const int MAX_N = 16;
const int MAX_F = (1<<MAX_N) + 2;


int n, k;
ll f[MAX_F][MAX_N];


int main() {
#ifdef DEBUG
	freopen("100589G.in", "r", stdin);
	freopen("100589G.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &k);
		int nMask = 1<<n;
		filla(f, 0);
		for (int i = 0; i < n; ++i)
			f[1<<i][i] = 1;
		for (int mask = 1; mask < nMask; ++mask)
			for (int i = 0; i < n; ++i)
				if (mask & (1<<i)) {
					int x = mask ^ (1<<i);
					if (x < 1) continue;
					for (int j = 0; j < n; ++j)
						if (abs(i-j) <= k && x&(1<<j))
							f[mask][i] += f[x][j];
				}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			ans += f[nMask-1][i];
		printf("%lld\n", ans);
	}
	return 0;
}