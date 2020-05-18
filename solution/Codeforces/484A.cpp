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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_BIT = 64;


bool check(ll x) {
	for (int i = 0; i < MAX_BIT; ++i)
		if ((1LL<<i)-1 == x)
			return true;
	return false;
}


ll solve(ll x, ll y) {
	if (x == y) return x;
	if (check(y)) return y;
	ll ans = 0;
	for (int i = MAX_BIT-1; i >= 0; --i) {
		ll a = (x>>i)&1, b = (y>>i)&1;
		if (a && b) {
			ll t = 1LL<<i;
			ans += t;
			x -= t;
			y -= t;
		}
		else if (b) {
			if (check(y)) ans += y;
			else if (i == 0) ++ans;
			else ans += (1LL<<i) - 1LL;
			break;
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("484A.in", "r", stdin);
	freopen("484A.out", "w", stdout);
#endif
	ll l, r;
	int nTest = read();
	while (nTest--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(l, r));
	}
	return 0;
}