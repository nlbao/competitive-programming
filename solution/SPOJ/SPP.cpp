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

#define fill(a,x) memset((a), (x), sizeof((a)))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const ll N = 17;

int k;
ll b[N], c[N], s[N];
ll base[N][N], tmp[N][N], tmp2[N][N];
ll module;


ll mmod(ll x) {
	x %= module;
	if (x < 0)
		x = (x+module)%module;
	return x;
}


void matCopy(ll a[N][N], ll b[N][N], int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			b[i][j] = a[i][j];
}


void matMultiply(ll a[N][N], ll b[N][N], ll c[N][N], int n) {
	// fill(c, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) c[i][j] = 0;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
			for (int j = 0; j < n; ++j)
				c[i][j] = mmod(c[i][j] + mmod(a[i][k]*b[k][j]));
}


void matPow(ll a[N][N], ll x, int n) {
	if (x <= 1) {
		matCopy(a, tmp, n);
		return;
	}
	matPow(a, x>>1, n);
	matMultiply(tmp, tmp, tmp2, n);
	if (x&1) matMultiply(tmp2, a, tmp, n);
	else matCopy(tmp2, tmp, n);
}


ll solve(ll n) {
	if (n < 0) return 0;
	if (n < k) return s[n];

	for (int i = 0; i < k+1; ++i)
		for (int j = 0; j < k+1; ++j)
			base[i][j] = 0;
	for (int i = 0; i < k-1; ++i) base[i+1][i] = 1;
	for (int i = 0; i < k; ++i)
		base[i][k-1] = base[i][k] = c[k-1-i];
	base[k][k] = 1;

	matPow(base, n - k + 1, k+1);

	ll ans = 0;
	for (int i = 0; i < k+1; ++i)
		ans = mmod(ans + mmod(b[i]*tmp[i][k]));

	return ans;
}


int main() {
#ifdef DEBUG
	freopen("SPP.in", "r", stdin);
	freopen("SPP.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest) {
		--nTest;
		k = read();
		for (int i = 0; i < k; ++i) b[i] = read();
		for (int i = 0; i < k; ++i) c[i] = read();
		ll m, n;
		scanf("%lld%lld%lld", &m, &n, &module);

		b[k] = 0;
		s[0] = b[0];
		for (int i = 1; i <= k; ++i)
			s[i] = mmod(s[i-1] + b[i]);
		b[k] = s[k];

		ll sn = solve(n-1);
		ll sm = solve(m-2);
		printf("%lld\n", mmod(sn - sm));
	}
	return 0;
}