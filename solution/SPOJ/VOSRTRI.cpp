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

int x[MAX_N], y[MAX_N];
map<int, int> a, b;


int main() {
#ifdef DEBUG
	freopen("VOSRTRI.in", "r", stdin);
	freopen("VOSRTRI.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		if (a.find(x[i]) == a.end()) a[x[i]] = 1;
		else ++a[x[i]];
		if (b.find(y[i]) == b.end()) b[y[i]] = 1;
		else ++b[y[i]];
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll cx = a[x[i]]-1;
		ll cy = b[y[i]]-1;
		ans += cx*cy;
	}
	printf("%lld\n", ans);
	return 0;
}