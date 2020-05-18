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


const ll MODULE = ll(1e9)+7;


ll mpow(ll a, ll n) {
	if (n < 1) return 1;
	if (n == 1) return a;
	ll t = mpow(a, n>>1);
	t = (t*t) % MODULE;
	if (n&1) return (t*a) % MODULE;
	return t;
}


int solve(ll n, ll m) {
	if (n == 1) return m;
	ll ans = (m * (m-1)) % MODULE;
	return (ans * mpow(m-2, n-2)) % MODULE;
}


int main() {
#ifdef DEBUG
	freopen("antipalindromic-strings.in", "r", stdin);
	freopen("antipalindromic-strings.out", "w", stdout);
#endif
	int nTest = readln();
	while (nTest--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", solve(n, m));
	}
	return 0;
}