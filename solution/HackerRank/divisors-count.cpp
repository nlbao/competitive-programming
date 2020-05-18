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

inline ll read() {	ll x;   cin >> x;   return x;   }


int main() {
#ifdef DEBUG
	freopen("divisors-count.in", "r", stdin);
	freopen("divisors-count.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		ll n = read(), c = 0;
		ll p = 1;
		while (p <= n && n%p == 0) {
			++c;
			p <<= 1;
		}
		cout << c << '\n';
	}
	return 0;
}