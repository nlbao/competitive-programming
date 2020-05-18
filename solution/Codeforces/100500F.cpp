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
	freopen("100500F.in", "r", stdin);
	freopen("100500F.out", "w", stdout);
#endif
	int nTest = readln();
	ll n, m, k;
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%lld%lld\n", &n, &m);
		ll l = 0, r = n;
		while (l <= r) {
			ll mid = (l+r)>>1;
			if (mid*(mid+1)/2LL <= m) {
				k = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		ll t = k*(k+1)/2LL;
		if (m == t) printf("Case %d: %lld %lld\n", test_id, k-1, k-1);
		else {
			m -= t;
			printf("Case %d: %lld %lld\n", test_id, k, m-1);
		}
	}
	return 0;
}