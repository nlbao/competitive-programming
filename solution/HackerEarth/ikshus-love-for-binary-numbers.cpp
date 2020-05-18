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


const int MAX_N = 66;

int n, k;
ll p[MAX_N], s[MAX_N], f[MAX_N][MAX_N];


ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}


int main() {
#ifdef DEBUG
	freopen("ikshus-love-for-binary-numbers.in", "r", stdin);
	freopen("ikshus-love-for-binary-numbers.out", "w", stdout);
#endif
	n = read(), k = read();
	p[0] = 1;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i-1] * 2LL;

	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			f[i][j] = 0;
			if (i < k || j+k-1 > i) continue;
			if (j == 1) {
				f[i][j] = p[i-k];
				continue;
			}
			ll tmp = p[j-1] - s[j-2] - p[j-2];
			f[i][j] = p[i - (j+k-1)] * tmp;
		}
		s[i] = 0;
		for (int j = 1; j <= i; ++j)
			s[i] += f[i][j];
	}
	ll x = s[n], y = p[n];
	ll d = gcd(x, y);
	x /= d, y /= d;
	cout << x << "/" << y << "\n";
	return 0;
}