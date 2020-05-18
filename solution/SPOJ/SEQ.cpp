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


const ll N = 10;
const ll MODULE = ll(1e9);


ll b[N], c[N], base[N][N];
ll tmp[N][N], tmp2[N][N];


ll mmod(ll x) {
	return x%MODULE;
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


int main() {
#ifdef DEBUG
	freopen("SEQ.in", "r", stdin);
	freopen("SEQ.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest) {
		--nTest;
		int k = read();
		for (int i = 0; i < k; ++i) b[i] = read();
		for (int i = 0; i < k; ++i) c[i] = read();

		int n = read() - 1;
		if (n < k) {
			printf("%d\n", (int)b[n]);
			continue;
		}

		for (int i = 0; i < k-1; ++i)
			for (int j = 0; j < k; ++j)
				base[i][j] = 0;
		for (int i = 0; i < k-1; ++i) base[i+1][i] = 1;
		for (int i = 0; i < k; ++i) base[i][k-1] = c[k-1-i];

		matPow(base, n - k + 1, k);

		ll res = 0;
		for (int i = 0; i < k; ++i)
			res = mmod(res + mmod(b[i]*tmp[i][k-1]));
		printf("%d\n", int(res));
	}
	return 0;
}