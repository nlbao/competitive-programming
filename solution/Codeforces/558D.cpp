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


int h, nQ;
vector<pll> a;


ll solve() {
	ll l = 1LL<<(h-1), r = (1LL<<h)-1;
	while (nQ--) {
		int i, q;
		ll x, y;
		scanf("%d %lld %lld %d", &i, &x, &y, &q);
		for (int k = 0; k < h-i; ++k) {
			x <<= 1;
			y = (y<<1)+1;
		}
		if (q == 1) {
			l = max(l, x);
			r = min(r, y);
		}
		else a.push_back(pll(x, y));
	}
	if (l > r) return -1;

	a.push_back(pll(r+1, 1LL<<60));
	sort(a.begin(), a.end());
	int n = a.size();
	ll c = 0, ans = -1;
	for (int i = 0; i < n; ++i) {
		if (l > r) break;
		ll x = a[i].first, y = a[i].second;
		if (l < x) {
			ans = l;
			c += x-l;
		}
		l = max(l, y+1);
	}
	if (l <= r) {
		ans = l;
		c += r-l+1;
	}
	if (c == 0) return -1;
	if (c == 1) return ans;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("558D.in", "r", stdin);
	freopen("558D.out", "w", stdout);
#endif
	scanf("%d%d", &h, &nQ);
	ll ans = solve();
	if (ans == -1) printf("Game cheated!\n");
	else if (ans == 0) printf("Data not sufficient!\n");
	else printf("%lld\n", ans);
	return 0;
}