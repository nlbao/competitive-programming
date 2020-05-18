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


const int MAX_N = 1e3 + 5;
const ll MODULE = 1e9 + 7;
const ll PHI = 1e9 + 6;


ll n, d;
int c[MAX_N][MAX_N];


inline ll mmod(ll x) {
	if (abs(x) > MODULE)
		x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


ll mpow(ll x, ll d, ll m) {
	if (d < 1) return 1;
	if (d == 1) return x%m;
	ll t = mpow(x, d>>1, m);
	t = (t*t) % m;
	if (d&1) return (t*x) % m;
	return t;
}


ll cal(ll n, ll d) {
	ll ans = 0;
	for (int k = 0; k <= n; ++k) {
		ll t = c[n][k];
		ll t1 = mpow(d, k, PHI);
		ll t2 = mpow(d+1, n-k, PHI);
		ll t3 = (t1*t2) % PHI;
		t3 = mpow(2, t3, MODULE);
		t = mmod(t * t3);
		if (k&1) t = -t;
		ans = mmod(ans + t);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("CNTDSETS.in", "r", stdin);
	freopen("CNTDSETS.out", "w", stdout);
#endif
	filla(c, 0);
	c[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MODULE;
	}

	int nTest = read();
	while (nTest--) {
		n = read();
		d = read();
		ll l = cal(n, d-1);
		ll r = cal(n, d);
		ll ans = mmod(r-l);
		printf("%d\n", (int)ans);
	}
	return 0;
}