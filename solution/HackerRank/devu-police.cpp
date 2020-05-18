#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


ll mpow(ll a, ll n, ll module) {
	if (n < 1) return 1;
	a %= module;
	if (n == 1) return a;
	ll t = mpow(a, n>>1, module);
	t = (t*t)%module;
	if (n&1) return (t*a)%module;
	return t;
}


int phi(int n) {
	int ans = n;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0) {
			ans -= ans/i;
			do {
				n /= i;
			} while (n%i == 0);
		}
	if (n > 1) ans -= ans/n;
	return ans;
}


ll solve(ll n1, ll k1, ll n2, ll k2, ll n) {
	if (n < 2) return 0;
	ll x = mpow(n1, k1, n);
	if (n2 == 1 || k2 == 0) return x;
	if (n2 == 0) return 1;
	if (x <= 1) return x;
	ll y = 1, i = 0;
	while (i < k2 && y < n) {
		++i;
		y *= n2;
	}
	if (i == k2 && y <= n)
		return mpow(x, y, n);
	else {
		ll p = phi(n);
		y = mpow(n2, k2, p);
		return mpow(x, y + p, n);
	}
}


int main() {
#ifdef DEBUG
	freopen("devu-police.in", "r", stdin);
	freopen("devu-police.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		ll n1, n2, k1, k2, n;
		cin >> n1 >> k1 >> n2 >> k2 >> n;
		cout << solve(n1, k1, n2, k2, n) << endl;
	}
	return 0;
}