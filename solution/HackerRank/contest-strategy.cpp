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


const int MAX_N = 3*int(1e3) + 4;


int n;
ll D;
ll t[MAX_N];
int nChild[MAX_N], h[MAX_N];
bool ok[MAX_N];


ll cal(int i) {
	return ll(nChild[i] + h[i]) * D + t[i];
}


bool check(ll limit) {
	filla(nChild, 0);
	filla(h, 0);
	filla(ok, false);
	ok[1] = true;
	int pos = 2;
	for (int i = 1; i < n; ++i) {
		if (!ok[i]) return false;
		while (pos <= n && ok[pos]) ++pos;
		if (pos > n) break;
		while (pos <= n) {
			++nChild[i];
			if (cal(i) > limit) {
				--nChild[i];
				break;
			}
			h[pos] = h[i] + nChild[i];
			ok[pos] = true;
			++pos;
		}
	}
	ll maxF = 0;
	for (int i = 1; i <= n; ++i)
		if (!ok[i]) return false;
		else maxF = max(maxF, cal(i));
	return maxF <= limit;
}


ll solve() {
	sort(t+1, t+1+n);
	for (int i = 1; i <= n; ++i)
		t[i] = -t[i];
	ll ans = 2LL*ll(1e18);
	ll l = 0, r = ans;
	while (l <= r) {
		ll mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("contest-strategy.in", "r", stdin);
	freopen("contest-strategy.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		D = read();
		for (int i = 1; i <= n; ++i)
			t[i] = -read();
		cout << solve() << endl;
	}
	return 0;
}