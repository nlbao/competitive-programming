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

const int MAX_N = 1e5 + 5;

ll a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("panda-and-maximum-product.in", "r", stdin);
	freopen("panda-and-maximum-product.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	sort(a, a+n);
	ll ans = a[0] * a[1];
	ans = max(ans, a[n-1] * a[n-2]);
	printf("%lld\n", ans);
	return 0;
}