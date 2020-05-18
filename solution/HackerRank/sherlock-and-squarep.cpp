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

const ll MODULE = ll(1e9)+7;


ll mpow(ll a, ll n) {
	if (n == 0) return 1;
	if (n == 1) return a;
	a %= MODULE;
	ll t = mpow(a, n>>1);
	t = (t*t)%MODULE;
	if (n&1) t = (t*a)%MODULE;
	return t;
}


int solve(int n) {
	if (n == 0) return 4;
	ll ans = 4;
	ans = (ans + mpow(2, n+1) - 2)%MODULE;
	if (ans < 0) ans += MODULE;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("sherlock-and-square.in", "r", stdin);
	freopen("sherlock-and-square.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		printf("%d\n", solve(n));
	}
	return 0;
}