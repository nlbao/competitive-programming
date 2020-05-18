#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const ll MODULE = ll(1e9)+7;

ll mpow(ll x, ll n) {
	if (n < 1) return 1;
	if (n == 1) return x;
	ll t = mpow(x, n>>1);
	t = (t*t)%MODULE;
	if (n&1) t = (t*x)%MODULE;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("a-chocolate-fiesta.in", "r", stdin);
	freopen("a-chocolate-fiesta.out", "w", stdout);
#endif
	int nTest = 1;
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n = read(), c = 0;
		for (int i = 0; i < n; ++i) {
			int x = read();
			if (x&1) c = 1;
		}
		ll res = mpow(2, n - c) - 1;
		if (res < 0) res += MODULE;
		// printf("%lld\n", res);
		cout << res << endl;
	}
	return 0;
}