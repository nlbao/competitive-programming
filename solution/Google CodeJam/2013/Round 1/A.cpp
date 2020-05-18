#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


ll f(ll n, ll r) {
	if (n < 1) return 0;
	ll k = n/2;
	ll sum_even = 2*k*(k+1)*(2*k+1)/3;
	k = (n-2)/2;
	ll sum_odd = 2*k*(k+1)*(2*k+1)/3 + 4*k*(k+1)/2 + k + 1;
	// cout << "		" << sum_even << " " << sum_odd << "		, " << r << endl;
	ll ans = sum_even - sum_odd;
	if (r == 1) return ans;
	// ans += r*r;
	ans -= f(r-1, 1);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	printf("%lld\n", f(2, 1));
	printf("%lld\n", f(4, 1));
	printf("%lld\n", f(6, 1));
	printf("%lld\n", f(6, 3));
	printf("%lld\n", f(8, 3));
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		ll radius, limit;
		scanf("%lld %lld", &radius, &limit);
		ll l = 2, r = 1e9, ans = -1;
		while (l <= r) {
			ll mid = (l+r)>>1;
			if (mid&1LL) {
				++mid;
				if (mid > r) mid-=2;
			}
			if (mid < l) break;
			if (f(mid, radius) <= limit) {
				ans = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		ans = ans/2 - (radius/2);
		printf("Case #%d: %lld\n", testid, ans);
	}
	return 0;
}