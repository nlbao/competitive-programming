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

const int MAX_K = 1003;
const ll MODULE = ll(1e9)+7;

int c[MAX_K][MAX_K];
ll s[MAX_K];


ll mmod(ll x) {
	x %= MODULE;
	if (x < 0) x += MODULE;
	return x%MODULE;
}


ll mpow(ll a, ll n) {
	if (n < 1) return 1;
	if (n == 1) return a%MODULE;
	ll tmp = mpow(a, n>>1);
	tmp = mmod(tmp * tmp);
	if (n&1) return mmod(tmp * a);
	return tmp;
}


int main() {
#ifdef DEBUG
	freopen("summing-the-k-n-series.in", "r", stdin);
	freopen("summing-the-k-n-series.out", "w", stdout);
#endif
	for (int i = 0; i < MAX_K; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = mmod(c[i-1][j] + c[i-1][j-1]);
	}

	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		ll n;
		int k;
		scanf("%lld%d", &n, &k);
		n %= MODULE;
		s[0] = n;
		for (int x = 1; x <= k; ++x) {
			s[x] = mmod(mpow(n+1, x+1) - 1);
			ll tmp;
			for (int i = 2; i <= x+1; ++i) {
				tmp = mmod(ll(c[x+1][i]) * s[x-i+1]);
				s[x] = mmod(s[x] - tmp);
			}
			s[x] = mmod(s[x] * mpow(x+1, MODULE - 2));
		}
		printf("%lld\n", s[k]);
	}
	return 0;
}