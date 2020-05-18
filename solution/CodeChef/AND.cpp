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

const int MAX_LOG = 30;

ll c[MAX_LOG];


int main() {
#ifdef DEBUG
	freopen("AND.in", "r", stdin);
	freopen("AND.out", "w", stdout);
#endif
	filla(c, 0);
	int n = read();
	for (int i = 0; i < n; ++i) {
		int x = read();
		for (int k = 0; k < MAX_LOG; ++k)
			c[k] += ((x >> k) & 1);
	}

	ll ans = 0;
	for (int i = 0; i < MAX_LOG; ++i) if (c[i]) {
		ll x = c[i];
		ans += x*(x-1)/2 * (1LL<<i);
	}
	printf("%lld\n", ans);
	return 0;
}