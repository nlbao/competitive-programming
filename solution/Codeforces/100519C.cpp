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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


pair<ll, ll> solve(ll a, ll b, ll c) {
	ll t = b/a, w = 0;
	if (t == 0) {
		t = 1;
		w = b;
	}
	else w = t*a;
	ll y = c / w;
	ll x = y * t;
	ll r = c%w;
	if (r != 0) {
		++y;
		x += (r/a) + ll(r%a > 0);
	}

	// kt <= (y-k)
	// ---> k(t+1) <= y ---> k <= y / (t+1)
	// x*a - kw + kt*(b-w) >= c
	// ---> k(bt - wt - w) >= c - xa
	// ---> k <= (xa - c) / (w + wt - bt)
	ll tmp = (w + w*t - b*t), k = 0;
	if (b > w && tmp > 0)
		k = min(y / (t+1), (x*a-c) / tmp);
	y -= k;
	return make_pair(x, y);
}


int main() {
#ifdef DEBUG
	freopen("100519.in", "r", stdin);
	freopen("100519.out", "w", stdout);
#endif
	ll a, b, c;
	cin >> a >> b >> c;
	pair<ll, ll> p = solve(a, b, c);
	cout << p.first << " " << p.second << endl;
	return 0;
}