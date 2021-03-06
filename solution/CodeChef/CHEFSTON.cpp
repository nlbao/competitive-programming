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

int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("CHEFSTON.in", "r", stdin);
	freopen("CHEFSTON.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		ll k = read();
		for (int i = 0; i < n; ++i) a[i] = read();
		for (int i = 0; i < n; ++i) b[i] = read();
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, (k/ll(a[i]))*ll(b[i]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}