#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const ll MAX_A = ll(1e18)+18;

int n;
vector<ll> a;
set<ll> s;

inline int length(ll x) {
	int ans = 0;
	while (x > 0) {
		x /= 10;
		++ans;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("strange-numbers.in", "r", stdin);
	freopen("strange-numbers.out", "w", stdout);
#endif
	for (int i = 0; i <= 10; ++i) {
		a.push_back(i);
		s.insert(i);
	}
	n = 11;

	for (int i = 1; i < n; ++i) {
		ll x = a[i];
		int len = length(x);
		ll limit = min(19LL, MAX_A/x+1);
		for (ll k = len; k <= limit; ++k) {
			ll y = x * k;
			int t = length(y);
			if (t < k) break;
			if (t == k && s.find(y) == s.end()) {
				a.push_back(y);
				s.insert(y);
				++n;
			}
		}
	}
	a.push_back(MAX_A);
	sort(a.begin(), a.end());

	int nTest = read();
	ll l, r, x, y;
	while (nTest--) {
		scanf("%lld%lld", &l, &r);
		x = lower_bound(a.begin(), a.end(), l) - a.begin();
		y = upper_bound(a.begin(), a.end(), r) - a.begin();
		printf("%lld\n", y-x);
	}
	return 0;
}