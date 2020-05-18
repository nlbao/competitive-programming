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


ll gcd(ll a, ll b) {
	return a ? gcd(b%a, a) : b;
}


ll mpow(ll a, ll n, ll module) {
	if (n < 1) return 1;
	a %= module;
	if (n == 1) return a;
	ll t = mpow(a, n>>1, module);
	t = (t*t)%module;
	if (n&1) return (t*a)%module;
	return t;
}


ll phi(ll n) {
	ll ans = n;
	for (ll i = 2; i*i <= n; ++i)
		if (n%i == 0) {
			ans -= ans/i;
			while (n%i == 0) n /= i;
		}
	if (n > 1) ans -= ans/n;
	return ans;
}


// find minimum k such that 2^k*a == a (mod 2n+1) (1)
// let m = 2*n+1, g = gcd(a, m), and a' = a/g, m' = m/g
// so (1) <=> 2^k*a' == a' (mod m) <=> 2^k == 1 (mod m)
int find(ll n, ll a) {
	ll m = 2*n + 1;
	a += m;
	m = m/gcd(a, m);
	ll limit = phi(m), ans = limit;
	for (ll i = 1; i*i <= limit; ++i)
		if (limit%i == 0) {
			if (mpow(2, i, m) == 1)
				return i;
			ll j = limit/i;
			if (mpow(2, j, m) == 1)
				ans = min(ans, j);
		}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("ichigo-and-rooms.in", "r", stdin);
	freopen("ichigo-and-rooms.out", "w", stdout);
#endif
	int nTest = read();
	for (int tid = 0; tid < nTest; ++tid) {
		ll n = read();
		ll a = read();
		printf("%d\n", int(2*n - find(n, a)));
	}
	return 0;
}