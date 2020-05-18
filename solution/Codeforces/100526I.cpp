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


const int MAX_F = 100;


ll f[MAX_F];
pii ans;


inline void update(ll x, ll y) {
	if (x < 1 || y < 1) return;
	if (x > y) return;
	if (y > ans.second) return;
	if (y == ans.second && x > ans.first) return;
	ans = pii(x, y);
}


void solve(ll n) {
	ans = pii(1, n-1);
	ll limit = min(n, 25000LL);
	ll a, b, t;
	for (ll y = 1; y < limit && y < ans.second; ++y) {
		for (int i = 0; i < MAX_F; ++i) {
			a = f[i], b = f[i+1];
			if (b >= n) break;
			t = b*y;
			if (t >= n) break;
			t = n - t;
			if (t < 1 || t%a != 0) continue;
			ll x = t / a;
			update(x, y);
		}

		for (int i = 0; i < MAX_F; ++i) {
			a = f[i], b = f[i+1];
			if (b >= n) break;
			t = a*x;
			if (t >= n) break;
			t = n - t;
			if (t < 1 || t%b != 0) continue;
			ll y = t / b;
			update(x, y);
		}
	}
	// for (ll x = 1; x < limit; ++x) {
	// 	for (int i = 0; i < MAX_F; ++i) {
	// 		a = f[i], b = f[i+1];
	// 		if (b >= n) break;
	// 		t = a*x;
	// 		if (t >= n) break;
	// 		t = n - t;
	// 		if (t < 1 || t%b != 0) continue;
	// 		ll y = t / b;
	// 		update(x, y);
	// 	}
	// }
}


int main() {
#ifdef DEBUG
	freopen("100526I.in", "r", stdin);
	freopen("100526I.out", "w", stdout);
#endif
	f[0] = f[1] = 1;
	for (int i = 2; i < MAX_F; ++i)
		f[i] = f[i-1] + f[i-2];

	int nTest = read();
	while (nTest--) {
		int n = read();
		solve(n);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}