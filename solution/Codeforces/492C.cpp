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


const int MAX_N = int(1e5)+5;


pair<ll, ll> a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("492C.in", "r", stdin);
	freopen("492C.out", "w", stdout);
#endif
	ll n = read(), s = 0;
	ll r = read(), avg = read();
	for (int i = 0; i < n; ++i) {
		ll x = read(), y = read();
		s += x;
		a[i] = make_pair(y, x);
	}

	ll ans = 0, x = n*avg - s;
	sort(a, a+n);
	for (int i = 0; i < n; ++i) {
		if (x < 1) break;
		ll t = min(x, r-a[i].second);
		ans += a[i].first * t;
		x -= t;
	}
	cout << ans;
	return 0;
}