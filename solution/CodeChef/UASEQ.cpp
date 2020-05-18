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

const int MAX_N = int(1e5) + 5;
const ll oo = 2*ll(1e9);

ll a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("UASEQ.in", "r", stdin);
	freopen("UASEQ.out", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	pair<ll, ll> ans = make_pair(oo, oo);
	for (int x = 1; x <= k+1; ++x) {
		int r = k-(x-1);
		for (int y = max(x+1, n-r); y <= n; ++y) {
			if ((a[y]-a[x])%(y-x) != 0) continue;
			ll d = (a[y]-a[x])/(y-x);
			ll a0 = a[x] - ll(x-1)*d, s = a0;
			if (make_pair(a0, d) >= ans) continue;
			int c = 0;
			for (int i = 1; i <= n; ++i) {
				c += int(s != a[i]);
				s += d;
			}
			if (c <= k) ans = make_pair(a0, d);
		}
	}
	a[1] = ans.first;
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", a[i]);
		a[i+1] = a[i] + ans.second;
	}
	return 0;
}