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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 111;


int c[MAX_N];


int main() {
#ifdef DEBUG
	freopen("COPS.in", "r", stdin);
	freopen("COPS.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		int t = x*y;
		filla(c, 0);
		for (int i = 0; i < n; ++i) {
			int p = read();
			int a = max(1, p - t);
			int b = min(101, p + t + 1);
			++c[a], --c[b];
		}
		int ans = 0;
		for (int i = 1, s = 0; i <= 100; ++i) {
			s += c[i];
			if (s == 0) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}