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

const int MAX_N = 2*int(1e5) + 5;

ll c[2];


int main() {
#ifdef DEBUG
	freopen("384C.in", "r", stdin);
	freopen("384C.out", "w", stdout);
#endif
	int n = read();
	ll ans = 0;
	c[0] = c[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int x = read();
		if (x == 0) ans += c[1];
		++c[x];
	}
	printf("%lld\n", ans);
	return 0;
}