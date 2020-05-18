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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


int n, m;
int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("608_1002.in", "r", stdin);
	freopen("608_1002.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			a[i] = read();
		for (int i = 0; i < m; ++i)
			b[i] = read();
		sort(a, a+n);
		sort(b, b+m);
		ll ans = 0;
		for (int i = n-1, j = 0; i >= 0 && j < m; --i, ++j) {
			if (b[j] >= a[i]) break;
			ans += a[i] - b[j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}