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
	freopen("set-marble.in", "r", stdin);
	freopen("set-marble.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		int n = read();
		ll s = 0, w = 0;
		for (int i = 0; i < n; ++i) {
			ll x = read();
			s += x;
			w = __gcd(w, x);
		}
		ll h = s / w;
		cout << h << " " << w << "\n";
	}
	return 0;
}