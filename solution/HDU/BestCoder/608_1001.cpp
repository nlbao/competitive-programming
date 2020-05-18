#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

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


const int MAX_N = 1e3 + 3;


int n;
ll p;
ll a[MAX_N], l[MAX_N], r[MAX_N];


ll solve() {
	if (n == 1) return p;
	l[0] = 0;
	for (int i = 1; i <= n; ++i)
		l[i] = max(a[i], a[i] + l[i-1]);
	r[n+1] = 0;
	for (int i = n; i >= 1; --i)
		r[i] = max(a[i], a[i] + r[i+1]);
	ll ans = -1e18;
	for (int i = 1; i <= n; ++i) {
		if (i > 1) ans = max(ans, l[i-1]);
		if (i < n) ans = max(ans, r[i+1]);
		ans = max(ans, max(l[i-1], r[i+1]) + p);
		ans = max(ans, l[i-1] + p + r[i+1]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("608_1001.in", "r", stdin);
	freopen("608_1001.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		p = read();
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		printf("%lld\n", solve());
	}
	return 0;
}