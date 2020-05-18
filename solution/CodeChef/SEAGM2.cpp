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


const int MAX_N = 17;
const double EPS = 1e-18;


ld a[MAX_N];
ll power[MAX_N];


int main() {
#ifdef DEBUG
	freopen("SEAGM2.in", "r", stdin);
	freopen("SEAGM2.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			ld pwin = 1;
			ll p10 = 0;
			for (int j = 0; j < m; ++j) {
				ld p;
				cin >> p;
				p *= 1e4;
				pwin *= p;
				p10 += 4;
				if (pwin > 1e4) {
					pwin /= 1e4;
					p10 -= 4;
				}
			}
			a[i] = pwin;
			power[i] = p10;
			// pwin(i) = a[i] * 10 ^ (-power[i])
		}

		// ans = pwin(1) / sum(pwin(1) .. pwin(n))
		ld num = a[1], de = a[1], ans = 0;
		for (int i = 2; i <= n; ++i)
			de += a[i] * pow(10, power[1] - power[i]);
		if (fabs(num) > EPS)
			ans = num/de;
		printf("%.9lf\n", (double)ans);
	}
	return 0;
}