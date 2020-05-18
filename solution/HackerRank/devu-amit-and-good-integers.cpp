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


const int MAX_N = 1e5 + 11;

int n, minV, maxV;
int a[MAX_N];
ll ans[MAX_N];


int main() {
#ifdef DEBUG
	freopen("devu-amit-and-good-integers.in", "r", stdin);
	freopen("devu-amit-and-good-integers.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d%d", &n, &minV, &maxV);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a+n);
		ll c = 0;
		int k = n, i = 0, j = n-1;
		while (i < n && a[i] < minV) ++i;
		while (j >= 0 && a[j] > maxV) --j;
		--i, ++j;
		while (k > 0) {
			while (i >= 0 && i+1 >= k) {
				c += ll(minV - a[i]);
				--i;
			}
			while (j < n && n-j >= k) {
				c += ll(a[j] - maxV);
				++j;
			}
			while (i >= 0 && j < n && (i+1) + (n-j) >= k) {
				ll t1 = ll(minV - a[i]), t2 = ll(a[j] - maxV);
				if (t1 > t2) {
					c += t2;
					++j;
				}
				else {
					c += t1;
					--i;
				}
			}
			ans[k] = c;
			--k;
		}
		for (int i = 1; i <= n; ++i)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}