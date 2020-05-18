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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const int MAX_P = int(1e6)+6;

int nPrime = 0;
int d[MAX_P], c[MAX_P], t[MAX_P], f[MAX_P];
int prime[MAX_P];


int main() {
#ifdef DEBUG
	freopen("CHEFB.in", "r", stdin);
	freopen("CHEFB.out", "w", stdout);
#endif
	filla(d, 0);
	for (int x = 2; x < MAX_P; ++x) {
		if (d[x] == 0) {
			d[x] = t[x] = x;
			c[x] = 1;
			prime[nPrime++] = x;
		}
		int limit = min(d[x], (MAX_P-1)/x);
		for (int i = 0; i < nPrime && prime[i] <= limit; ++i) {
			int y = prime[i] * x;
			d[y] = t[y] = prime[i];
			c[y] = 1;
			if (prime[i] == d[x]) {
				c[y] += c[x];
				t[y] *= t[x];
			}
		}
	}

	int nTest = read();
	while (nTest--) {
		int n = read();
		filla(f, 0);
		for (int i = 0; i < n; ++i) {
			int x = read();
			while (x > 1) {
				int p = d[x];
				f[p] = max(f[p], c[x]);
				x /= t[x];
			}
		}
		ll ans = 0;
		for (int i = 0; i < MAX_P; ++i)
			ans += ll(f[i]);
		printf("%lld\n", ans);
	}
	return 0;
}