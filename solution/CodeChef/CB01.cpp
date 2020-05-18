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


const ll MODULE = 1e3+ 9;
const int MAX_N = MODULE + 10;


ll c[MAX_N][MAX_N];


ll getC(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	if (k == 0 || k == n) return 1;
	if (n < MODULE) return c[n][k];
	ll ans = 1;
	while (n) {
		ll t = getC(n % MODULE, k % MODULE);
		if (t == 0) return 0;
		ans = (ans * t) % MODULE;
		n /= MODULE;
		k /= MODULE;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("CB01.in", "r", stdin);
	freopen("CB01.out", "w", stdout);
#endif
	filla(c, 0);
	for (int i = 0; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MODULE;
	}

	int nTest = read();
	while (nTest--) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
		printf("%lld\n", getC(n, k));
	}
	return 0;
}