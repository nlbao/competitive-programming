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

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100500D.in", "r", stdin);
	freopen("100500D.out", "w", stdout);
#endif
	int nTest = readln();
	ll n, d, c;
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		n = read();
		d = read();
		c = read();
		for (int i = 0; i < n; ++i)
			a[i] = read();
		sort(a, a+n);
		ll ans = d*n;
		for (ll i = 0; i < n; ++i)
			ans = min(ans, (i+1)*c*ll(a[i]) + (n-1-i)*d);
		printf("Case %d: %lld\n", test_id, ans);
	}
	return 0;
}