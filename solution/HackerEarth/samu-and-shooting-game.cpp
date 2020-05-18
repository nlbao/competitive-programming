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


const int MAX_N = (1e3 + 333) * 2 * 10;
const double EPS = 1e-9;


int n, W, X, Y;
double p1, p2;
double f[2][MAX_N];


inline double getmax(double x, double y) {
	return x + EPS < y ? y : x;
}


int main() {
#ifdef DEBUG
	freopen("samu-and-shooting-game.in", "r", stdin);
	freopen("samu-and-shooting-game.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> X >> Y >> n >> W >> p1 >> p2;
		p1 /= 100, p2 /= 100;
		filla(f, 0);
		f[0][0] = f[1][0] = 1;
		int t = 0, xmin = min(X, Y), xmax = W + n * max(X, Y);
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			int tt = t;
			t ^= 1;
			// f[t][0] = f[tt][0] * getmax(1-p1, 1-p2);
			f[t][0] = 0;
			for (int x = xmin; x <= xmax; ++x) {
				f[t][x] = 0;
				if (x >= X) f[t][x] = getmax(f[t][x], f[tt][x-X] * p1);
				if (x >= Y) f[t][x] = getmax(f[t][x], f[tt][x-Y] * p2);
				if (x >= W) ans = getmax(ans, f[t][x]);
				// if (i == n-1 && x >= W) ans = getmax(ans, f[t][x]);
				// cout << "	" << i << " " << x << ": " << f[t][x] << endl;
			}
		}
		cout << ans*100 << endl;
	}

	return 0;
}