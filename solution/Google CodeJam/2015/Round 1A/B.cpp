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


const int MAX_N = int(1e3) + 3;
const ll MAX_POS = ll(1e9);


int n, pos;
ll a[MAX_N];


bool check(int k) {
	ll l = 0, r = min(MAX_POS, ll(pos));
	while (l <= r) {
		ll mid = (l+r)>>1;
		ll t = a[k] * mid;
		ll sum = mid;
		for (int i = 0; i < n; ++i) if (i != k) {
			ll x = t / a[i];
			if (i > k) {
				if (x*a[i] < t)
					++x;
			}
			else ++x;
			sum += x;
		}
		if (sum == pos-1)
			return true;
		if (sum < pos-1) l = mid+1;
		else r = mid-1;
	}
	return false;
}


int solve() {
	int ans = -1;
	for (int i = 0; i < n; ++i)
		if (check(i)) {
			ans = i;
			break;
		}
	return ans+1;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-practice.in", "r", stdin);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid	<= nTest; ++testid) {
		n = read();
		pos = read();
		for (int i = 0; i < n; ++i)
			a[i] = read();
		int ans = solve();
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}