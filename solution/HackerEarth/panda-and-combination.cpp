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


ll solve(ll n, ll x) {
	if (x == 1) return n;
	ll ans = 0, t = x;
	while (t <= n/x+1LL && t*x <= n) t *= x;
	while (n >= t) {
		ans += n/t;
		n = n%t;
		while (t > 1 && t > n) t /= x;
	}
	ans += n;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("panda-and-combination.in", "r", stdin);
	freopen("panda-and-combination.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		ll n, x;
		scanf("%lld %lld", &n, &x);
		printf("%lld\n", solve(n, x));
	}
	return 0;
}