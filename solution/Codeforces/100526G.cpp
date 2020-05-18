#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, int> node;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 14;
const ll oo = 1e9;
const ld EPS = 1e-9;


int n;
node f[MAX_N];


inline ld calf(ld a, ld b, ld c, ld x) {
	return -a*x*x + b*x + c;
}


ld cal(ld a, ld b, ld c) {
	ld l = 0, r = oo;
	ld ans = max(calf(a, b, c, l), calf(a, b, c, r));
	for (int i = 0; i < 1000; ++i) {
		ld xl = l + (r-l)/3;
		ld xr = r - (r-l)/2;
		ld tl = calf(a, b, c, xl);
		ld tr = calf(a, b, c, xr);
		ans = max(ans, max(tl, tr));
		if (tl + EPS < tr) l = xl;
		else r = xr;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100526G.in", "r", stdin);
	freopen("100526G.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			f[i] = node(cal(a, b, c), i);
		}
		sort(f, f+n);
		printf("%d\n", f[n-1].second + 1);
	}
	return 0;
}