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


const ll MODULE = 1e9 + 7;


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x % MODULE;
	ll t = mpow(x, d>>1);
	t = (t*t) % MODULE;
	if (d&1) return (t*x) % MODULE;
	return t;
}


ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


int main() {
#ifdef DEBUG
	freopen("count-the-necklaces.in", "r", stdin);
	freopen("count-the-necklaces.out", "w", stdout);
#endif
	ll n, k;
	cin >> n >> k;
	if (n == 1) {
		cout << k;
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll p = mpow(k, gcd(i, n));
		ans = (ans + p) % MODULE;
	}
	ans = (ans * mpow(n, MODULE-2)) % MODULE;
	cout << ans;

	return 0;
}