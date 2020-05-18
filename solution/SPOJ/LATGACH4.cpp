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


const ll N = 2;
const ll MODULE = 111539786;

ll a[N][N], tmp[N][N], tmp2[N][N];


ll mmod(ll x) {
	return x%MODULE;
}


void matCopy(ll a[N][N], ll b[N][N]) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			b[i][j] = a[i][j];
}


void matMultiply(ll a[N][N], ll b[N][N], ll c[N][N]) {
	// fill(c, 0);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) c[i][j] = 0;
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			for (int j = 0; j < N; ++j)
				c[i][j] = mmod(c[i][j] + mmod(a[i][k]*b[k][j]));
}


void matPow(ll a[N][N], ll x) {
	if (x <= 1) {
		matCopy(a, tmp);
		return;
	}
	matPow(a, x>>1);
	matMultiply(tmp, tmp, tmp2);
	if (x&1) matMultiply(tmp2, a, tmp);
	else matCopy(tmp2, tmp);
}


int main() {
#ifdef DEBUG
	freopen("LATGACH4.in", "r", stdin);
	freopen("LATGACH4.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest) {
		--nTest;
		int n = read();
		if (n < 4) {
			printf("%d\n", n);
			continue;
		}
		a[0][0] = 0;	a[0][1] = 1;
		a[1][0] = 1;	a[1][1] = 1;
		matPow(a, n-1);
		printf("%d\n", int(mmod(tmp[0][1] + tmp[1][1])));
	}
	return 0;
}