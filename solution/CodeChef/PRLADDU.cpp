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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;

int d[MAX_N];


int main() {
#ifdef DEBUG
	freopen("PRLADDU.in", "r", stdin);
	freopen("PRLADDU.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0; i < n; ++i)
			d[i] = read();
		int i = 0, j = 0;
		ll ans = 0;
		while (i < n && j < n) {
			while (i < n && d[i] < 0) ++i;
			while (j < n && d[j] > 0) ++j;
			if (i >= n || j >= n) break;
			ll t = min(d[i], -d[j]);
			ans += ll(abs(i-j))*t;
			d[i] -= t;
			d[j] += t;
			if (d[i] == 0) ++i;
			if (d[j] == 0) ++j;
		}
		printf("%lld\n", ans);
	}
	return 0;
}