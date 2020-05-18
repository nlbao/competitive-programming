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


int main() {
#ifdef DEBUG
	freopen("EGBOBRD.in", "r", stdin);
	freopen("EGBOBRD.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n;
		ll k;
		scanf("%d%lld", &n, &k);
		ll ans = 0, pre = 0;
		for (int i = 0; i < n; ++i) {
			ll a = read();
			--pre;
			if (pre > 0) {
				ll t = min(a, pre);
				a -= t;
				pre -= t;
			}
			if (a == 0) continue;
			ll d = a/k;
			ans += d;
			if (a%k == 0) continue;
			++ans;
			pre = k - (a%k);
		}
		printf("%lld\n", ans);
	}
	return 0;
}