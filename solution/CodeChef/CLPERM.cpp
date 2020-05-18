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


const int MAX_K = int(1e5) + 5;

int a[MAX_K];


int main() {
#ifdef DEBUG
	freopen("CLPERM.in", "r", stdin);
	freopen("CLPERM.out", "w", stdout);
#endif
	int nTest = read(), n, k;
	while (nTest--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; ++i)
			scanf("%d", &a[i]);
		sort(a, a+k);
		a[k++] = n;
		ll s = 0, pre = 1;
		for (int i = 0; i < k; ++i) {
			ll limit = a[i]-1;
			if (i == k-1) ++limit;
			if (limit >= pre) {
				if (pre <= s+1) {
					ll c = limit - pre + 1;
					s += c*(c+1)/2LL;
					s += (pre-1)*c;
				}
				else break;
			}
			pre = a[i]+1;
		}
		if (s&1LL) printf("Mom\n");
		else printf("Chef\n");
	}
	return 0;
}