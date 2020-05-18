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

const int MAX_N = 155;
const ll MODULE = ll(1e9+9);

ll n, alpha, beta;
ll a[MAX_N];
ll f[MAX_N][MAX_N][2];			//0: even, 1: odd
ll c[MAX_N][MAX_N];


ll mmod(ll x) {
	x %= MODULE;
	while (x < 0) x += MODULE;
	while (x > MODULE) x -= MODULE;
	return x;
}


void mAdd(ll &x, ll y) {
	x = (x + y%MODULE)%MODULE;
}


int solve() {
	sort(a, a+n);
	// init for len = 1, 2
	fill(c, 0);
	fill(f, 0);
	for(int i = 0; i < n; ++i) {
		c[i][i] = 1;
		c[i][i+1] = 2;
		if (i) c[i][i-1] = 1;
		f[i][i][0] = a[i];
		f[i][i][1] = 0;
		f[i][i+1][0] = f[i][i+1][1] = mmod(a[i] + a[i+1]);
	}
	c[n][n-1] = c[n+1][n] = 1;
	// len >= 2
	for (int len = 2; len < n; ++len) {
		for (int i = 0; i+len < n; ++i) {
			int j = i+len;
			// if a[i] is the root
			c[i][j] = c[i+1][j];
			f[i][j][0] = mmod(mmod(a[i]*c[i+1][j]) + f[i+1][j][1]);
			f[i][j][1] = f[i+1][j][0];
			// if a[k] is the root
			for (int k = i+1; k <= j; ++k) {
				ll t = mmod(c[i][k-1]*c[k+1][j]);
				mAdd(c[i][j], t);
				// even
				mAdd(f[i][j][0], a[k]*t);
				mAdd(f[i][j][0], f[i][k-1][1]*c[k+1][j]);
				mAdd(f[i][j][0], f[k+1][j][1]*c[i][k-1]);
				// odd
				mAdd(f[i][j][1], f[i][k-1][0]*c[k+1][j]);
				mAdd(f[i][j][1], f[k+1][j][0]*c[i][k-1]);
			}
		}
	}
	return mmod(mmod(f[0][n-1][0]*alpha) - mmod(f[0][n-1][1]*beta));
}


int main() {
#ifdef DEBUG
	freopen("roy-and-alpha-beta-trees.in", "r", stdin);
	freopen("roy-and-alpha-beta-trees.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		n = read();
		alpha = read();
		beta = read();
		fill(a, 0);
		for (int i = 0; i < n; ++i)
			a[i] = read();
		printf("%d\n", solve());
	}
	return 0;
}