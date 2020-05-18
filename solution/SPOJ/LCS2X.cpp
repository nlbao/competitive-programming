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


const int MAX_N = 1e3 + 555;


int n, m;
int a[MAX_N], b[MAX_N];
int f[2][MAX_N];


int main() {
#ifdef DEBUG
	freopen("LCS2X.in", "r", stdin);
	freopen("LCS2X.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++i) a[i] = read();
		for (int i = 1; i <= n; ++i) b[i] = read();
		int t = 0, ans = 0;
		filla(f, 0);
		for (int i = 1; i <= m; ++i) {
			int tt = t;
			t ^= 1;
			int maxF = 0;
			for (int j = 1; j <= n; ++j) {
				f[t][j] = f[tt][j];
				if (a[i] == b[j])
					f[t][j] = maxF + 1;
				if (2*b[j] <= a[i])
					maxF = max(maxF, f[tt][j]);
				ans = max(ans, f[t][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}