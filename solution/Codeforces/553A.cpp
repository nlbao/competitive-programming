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


const int MAX_N = 1e3 + 33;
const ll MODULE = 1e9 + 7;


int a[MAX_N], c[MAX_N][MAX_N];
ll f[2][MAX_N], s[2][MAX_N];


inline ll mmod(ll x) {
	if (abs(x) > MODULE) x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


int main() {
#ifdef DEBUG
	freopen("553A.in", "r", stdin);
	freopen("553A.out", "w", stdout);
#endif
	filla(c, 0);
	c[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = mmod(c[i-1][j-1] + c[i-1][j]);
	}

	int k = read(), n = 0;
	for (int i = 1; i <= k; ++i) {
		a[i] = read();
		n += a[i];
	}

	filla(f, 0);
	filla(s, 0);
	int t = 0, sum = 0;
	for (int i = 0; i <= n; ++i) s[t][i] = 1;
	for (int x = 1; x <= k; ++x) {
		int tt = t;
		t ^= 1;
		sum += a[x];
		for (int i = 0; i <= n; ++i) f[t][i] = s[t][i] = 0;
		for (int i = sum; i <= n; ++i)
			f[t][i] = mmod(s[tt][i-1] * (ll)c[i-(sum-a[x])-1][a[x]-1]);
		for (int i = 1; i <= n; ++i)
			s[t][i] = mmod(s[t][i-1] + f[t][i]);
	}

	int ans = f[t][n];
	printf("%d\n", ans);
	return 0;
}