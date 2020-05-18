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

const int MAX_N = int(1e6) + 6;

ll n, m, module;
vector<ll> p;


inline ll mmod(ll x) {
	x %= module;
	if (x < 0) x += module;
	return x;
}


inline ll sum(ll n) {
	n %= module;
	return mmod(mmod(n*(n+1))*mmod(mmod((2*n+1)*mmod(3*n*n + 3*n - 1))));
}


int main() {
#ifdef DEBUG
	freopen("FLOORI4.in", "r", stdin);
	freopen("FLOORI4.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%lld %lld", &n, &m);
		module = m*30LL;

		p.clear();
		ll sqrt_n = sqrt(n);
		for (ll i = 1; i <= sqrt_n; ++i) {
			p.push_back(i);
			ll t = n/i;
			if (t != i) p.push_back(t);
		}
		sort(p.begin(), p.end());

		ll ans = 0;
		for (int i = 0, sz = (int)p.size(); i < sz; ++i) {
			ll x = p[i];
			ll r = n/x, l = i == sz-1 ? 1 : n / (p[i+1]) + 1;
			if (l > r) continue;
			ll t = mmod(sum(r) - sum(l-1));
			t /= 30LL;
			t = (t*x)%m;
			ans = (ans + t)%m;
		}
		printf("%lld\n", ans);
	}
	return 0;
}