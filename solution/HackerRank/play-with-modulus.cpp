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

inline int read() {   int x;   cin >> x;   return x;   }


int main() {
#ifdef DEBUG
	freopen("play-with-modulus.in", "r", stdin);
	freopen("play-with-modulus.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		ll a, b;
		cin >> a >> b;
		a %= b;
		if (a < 0) a += b;
		cout << a << '\n';
	}
	return 0;
}