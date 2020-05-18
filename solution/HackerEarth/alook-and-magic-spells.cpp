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


const int N = 3;
const ll MODULE = ll(1e9)+7;


struct mat {
	ll a[N][N];
	mat() {
		filla(a, 0);
	}
	mat(const mat& o) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				a[i][j] = o.a[i][j];
	}
	mat& operator = (const mat& o) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				a[i][j] = o.a[i][j];
		return *this;
	}
	mat operator * (const mat& o) {
		mat c;
		for (int k = 0; k < N; ++k)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					c.a[i][j] = (c.a[i][j] + (a[i][k] * o.a[k][j]) % MODULE) % MODULE;
		return c;
	}
};


mat mpow(const mat &a, int n) {
	if (n == 1) return a;
	mat t = mpow(a, n>>1);
	t = t*t;
	if (n&1) return t*a;
	return t;
}


mat base;
ll f[2] = {2, 12};


int solve(int n) {
	if (n == 1) return 2;
	if (n == 2) return 14;
	mat t = mpow(base, n-2);
	ll ans = (f[0] * t.a[0][2] + f[1] * t.a[1][2]) % MODULE;
	ans = (ans + 14LL * t.a[2][2]) % MODULE;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("alook-and-magic-spells.in", "r", stdin);
	freopen("alook-and-magic-spells.out", "w", stdout);
#endif
	base.a[0][0] = 0;	base.a[0][1] = 4;	base.a[0][2] = 4;
	base.a[1][0] = 1;	base.a[1][1] = 2;	base.a[1][2] = 2;
	base.a[2][0] = 0;	base.a[2][1] = 0;	base.a[2][2] = 1;
	int nTest = read();
	while (nTest--) {
		int n = read();
		printf("%d\n", solve(n));
	}
	return 0;
}