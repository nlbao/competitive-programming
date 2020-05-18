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


const int MAX_N = 1e5 + 5;
const ll MODULE = 1e9 + 7;


ll a[MAX_N], fac[MAX_N], invfac[MAX_N];


inline ll mmod(ll x) {
	if (abs(x) >= MODULE) x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return mmod(x);
	ll t = mpow(x, d>>1);
	t = mmod(t*t);
	if (d&1) return mmod(t*x);
	return t;
}


int main() {
#ifdef DEBUG
	freopen("ANKGAME.in", "r", stdin);
	freopen("ANKGAME.out", "w", stdout);
#endif
	fac[0] = invfac[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fac[i] = mmod(fac[i-1] * i);
		invfac[i] = mpow(fac[i], MODULE-2);
	}

	// solve
	int nTest = read();
	while (nTest--) {
		int n = read(), c1 = 0, m = 0;
		for (int i = 0; i < n; ++i) {
			ll x;
			scanf("%lld", &x);
			if (x == 1) ++c1;
			else a[m++] = x;
		}
		n = m;

		if (n == 0) {
			if (c1&1) printf("1\n");
			else printf("0\n");
			continue;
		}

		sort(a, a+n);
		int c = 1;
		ll pre = a[0], tmp = 1;
		for (int i = 1; i < n; ++i)
			if (a[i] != pre) {
				tmp = mmod(tmp * invfac[c]);
				c = 1;
				pre = a[i];
			}
			else ++c;
		tmp = mmod(tmp * invfac[c]);

		ll ans = 0;
		if (c1%2 == 0) ans = mmod(fac[n] * tmp);
		for (int i = 0; i < c1; i += 2) {
			int x = c1-i;
			ll t1 = mmod(fac[x+n] * mmod(tmp * invfac[x]));
			ll t2 = mmod(fac[x+n-1] * mmod(tmp * invfac[x-1]));
			ll t = mmod(t1-t2);
			ans = mmod(ans + t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}