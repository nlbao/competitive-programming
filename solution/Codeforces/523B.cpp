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


const int MAX_N = 2e5 + 5;


int n, T;
double C;
double a[MAX_N], s[MAX_N], f[MAX_N], g[MAX_N];


int main() {
#ifdef DEBUG
	freopen("523B.in", "r", stdin);
	freopen("523B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> T >> C;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		// scanf("%lf", &a[i]);

	a[0] = 0;
	s[0] = 0;
	g[0] = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i-1] + a[i];
		if (i >= T) {
			s[i] -= a[i-T];
			f[i] = s[i] / T;
		}
		g[i] = (g[i-1] + a[i] / T) / C;
	}

	int m = read();
	while (m--) {
		int i = read();
		cout << f[i] << " " << g[i] << " " << fabs(g[i]-f[i]) / f[i] << endl;
		// printf("%.9lf %.9lf %.9lf\n", f[i], g[i], fabs(g[i]-f[i])/f[i]);
	}

	return 0;
}