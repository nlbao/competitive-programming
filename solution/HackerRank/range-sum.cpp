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


const int MAX_N = 1e5 + 55;


ll s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("range-sum.in", "r", stdin);
	freopen("range-sum.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		int n, nQ;
		cin >> n >> nQ;
		s[0] = 0;
		for (int i = 1; i <= n; ++i) {
			s[i] = s[i-1] + read();
		}
		while (nQ--) {
			int l, r;
			cin >> l >> r;
			cout << s[r] - s[l-1] << '\n';
		}
	}
	return 0;
}