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

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("CHEFA.in", "r", stdin);
	freopen("CHEFA.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0; i < n; ++i)
			a[i] = -read();
		sort(a, a+n);
		ll ans = 0;
		for (int i = 0; i < n; i += 2)
			ans -= ll(a[i]);
		printf("%lld\n", ans);
	}
	return 0;
}