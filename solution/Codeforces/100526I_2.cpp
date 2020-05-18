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


const int MAX_F = 91;


ll f[MAX_F];
pii ans;


ll gcd(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


bool find_sol(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}


inline bool ok(int x, int y) {
	if (y != ans.second)
		return y < ans.second;
	if (x != ans.first)
		return x < ans.first;
	return false;
}


inline void update(ll x, ll y) {
	if (x < 1 || y < 1) return;
	if (x > y) return;
	if (y > ans.second) return;
	if (y == ans.second && x > ans.first) return;
	ans = pii(x, y);
}


void solve(ll n) {
	ans = pii(1, n-1);
	ll limit = min(n, 50000LL);
	for (int i = 0; i < MAX_F; ++i) {
		ll a = f[i], b = f[i+1];
		if (b >= n) break;
		ll x, y, g;
		if (!find_sol(a, b, n, x, y, g)) continue;

		ll tx = b/g, ty = a/g;

		// if (x > limit) {
		// 	ll k = (x - limit) / tx + 1;
		// 	x -= k*tx;
		// 	y += k*ty;
		// }
		// if (y > limit) {
		// 	ll k = (y - limit) / ty + 1;
		// 	x += k*tx;
		// 	y -= k*ty;
		// }

		if (y < x) continue;

		cout << "find: " << a << " " << b << ": " << x << " " << y << " " << g << endl;

		ll x0 = x, y0 = y;
		x = x0, y = y0;

		for (ll k = 0; x < n && y > 0; ++k) {
			x += tx;
			y -= ty;
			update(x, y);
		}
		// x = x0, y = y0;
		// for (ll k = 0; x > 0 && y < n; ++k) {
		// 	x -= tx;
		// 	y += ty;
		// 	update(x, y);
		// }

		// if (ans.first == 1 && ans.second == 47) {
		cout << "!!!!! " << a << " " << b << ": " << x << " " << y << endl;
		// 	break;
		// }
	}
}


int main() {
#ifdef DEBUG
	freopen("100526I.in", "r", stdin);
	freopen("100526I.out", "w", stdout);
#endif
	f[0] = f[1] = 1;
	for (int i = 2; i < MAX_F; ++i) {
		f[i] = f[i-1] + f[i-2];
		// cout << f[i] << endl;
	}

	int nTest = read();
	while (nTest--) {
		int n = read();
		solve(n);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}