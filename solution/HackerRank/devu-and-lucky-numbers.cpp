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


const int MAX_N = 104;
const ll MODULE = 1e9 + 7;


ll f[MAX_N][MAX_N][MAX_N], c[MAX_N][MAX_N][MAX_N];



int main() {
#ifdef DEBUG
	freopen("devu-and-lucky-numbers.in", "r", stdin);
	freopen("devu-and-lucky-numbers.out", "w", stdout);
#endif
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);

	ll ans = 0;
	filla(c, 0);
	filla(f, 0);
	c[0][0][0] = 1;
	f[0][0][0] = 0;
	for (int i = 0; i <= x; ++i)
		for (int j = 0; j <= y; ++j)
			for (int k = 0; k <= z; ++k) if (c[i][j][k]) {
				if (i+j+k > 0)
					ans = (ans + f[i][j][k]) % MODULE;
				if (i < x) {
					c[i+1][j][k] = (c[i+1][j][k] + c[i][j][k]) % MODULE;
					f[i+1][j][k] = (f[i+1][j][k] + f[i][j][k] * 10 + c[i][j][k] * 4) % MODULE;
				}
				if (j < y) {
					c[i][j+1][k] = (c[i][j+1][k] + c[i][j][k]) % MODULE;
					f[i][j+1][k] = (f[i][j+1][k] + f[i][j][k] * 10 + c[i][j][k] * 5) % MODULE;
				}
				if (k < z) {
					c[i][j][k+1] = (c[i][j][k+1] + c[i][j][k]) % MODULE;
					f[i][j][k+1] = (f[i][j][k+1] + f[i][j][k] * 10 + c[i][j][k] * 6) % MODULE;
				}
			}
	cout << ans;
	return 0;
}