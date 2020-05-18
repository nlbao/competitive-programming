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


const int MAX_N = 5055;


int n, m;
int a[MAX_N], b[MAX_N];
ll f[2][MAX_N];
bool ok[2][MAX_N];


int main() {
#ifdef DEBUG
	freopen("VOSLIS.in", "r", stdin);
	freopen("VOSLIS.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= m; ++i) b[i] = read();
	int t = 0;
	ll ans = 0;
	filla(f, 0);
	filla(ok, false);
	for (int i = 1; i <= n; ++i) {
		int tt = t;
		t ^= 1;
		ll maxF = 0;
		for (int j = 1; j <= m; ++j) {
			f[t][j] = f[tt][j];
			ok[t][j] = ok[tt][j];
			if (a[i] == b[j]) {
				f[t][j] = max(f[t][j], maxF);
				ok[t][j] = true;
			}
			if (ok[tt][j])
				maxF = max(maxF, f[tt][j] + abs(a[i]-b[j]));
			ans = max(ans, f[t][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}