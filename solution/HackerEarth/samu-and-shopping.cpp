#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int oo = 1e9;


int f[2][3];


int main() {
#ifdef DEBUG
	freopen("samu-and-shopping.in", "r", stdin);
	freopen("samu-and-shopping.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		int n = read(), t = 0, value;
		for (int x = 0; x < 3; ++x)
			f[t][x] = 0;
		for (int i = 0; i < n; ++i) {
			int tt = t;
			t ^= 1;
			for (int x = 0; x < 3; ++x) {
				cin >> value;
				f[t][x] = oo;
				for (int y = 0; y < 3; ++y) if (x != y)
					f[t][x] = min(f[t][x], f[tt][y] + value);
			}
		}
		int ans = f[t][0];
		for (int i = 1; i < 3; ++i)
			ans = min(ans, f[t][i]);
		cout << ans << endl;
	}

	return 0;
}