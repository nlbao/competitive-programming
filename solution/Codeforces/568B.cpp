#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 4*1e3 + 33;
const ll MODULE = 1e9 + 7;


int n;
int c[MAX_N][MAX_N], f[MAX_N][MAX_N], g[MAX_N];


inline ll mmod(ll x) {
	if (x > MODULE)
		x %= MODULE;
	return x;
}


int main() {
#ifdef DEBUG
	freopen("568B.in", "r", stdin);
	freopen("568B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n;

	filla(c, 0);
	c[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = mmod(c[i-1][j-1] + c[i-1][j]);
	}

	filla(f, 0);
	filla(g, 0);
	f[0][0] = g[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int x = 1; x <= i; ++x) {
			f[i][x] = mmod(1LL * f[i-1][x] * x);
			f[i][x] = mmod(f[i][x] + f[i-1][x-1]);
			g[i] = mmod(g[i] + f[i][x]);
		}

	ll ans = 0;
	for (int k = 1; k <= n; ++k)
		ans = mmod(ans + 1LL*c[n][k]*g[n-k]);
	cout << ans << '\n';
	return 0;
}