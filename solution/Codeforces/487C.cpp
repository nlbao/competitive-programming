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

const int MAX_N = int(1e5) + 5;


ll mmod(ll x, ll n, ll module) {
	if (n == 0) return 1;
	x %= module;
	if (n == 1) return x;
	ll t = mmod(x, n>>1, module);
	t = (t*t)%module;
	if (n&1) return (t*x)%module;
	return t;
}


int solve(int n) {
	if (n == 1) {
		printf("YES\n1");
		return true;
	}
	if (n == 4) {
		printf("YES\n");
		printf("1 3 2 4");
		return true;
	}

	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)
			return false;

	printf("YES\n");
	printf("1\n");
	for (int i = 2; i < n; ++i) {
		ll x = i, y = mmod(i-1, n-2, n);
		x = (x*y)%n;
		printf("%d\n", (int)x);
	}
	printf("%d", n);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("487C.in", "r", stdin);
	freopen("487C.out", "w", stdout);
#endif
	int n = read();
	if (!solve(n))
		printf("NO");
	return 0;
}