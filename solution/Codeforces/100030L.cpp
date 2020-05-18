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
// const ll oo = 1e9 + 7;


// set<ll, greater<ll> > heap;
set<ll> heap;

pair<pii, ll> a[2*MAX_N];


int main() {
#ifdef DEBUG
	freopen("100030L.in", "r", stdin);
	freopen("100030L.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = read(), m = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[m++] = make_pair(make_pair(x, 0), y);
		a[m++] = make_pair(make_pair(y, 1), x);
		sum += ll(x);
	}
	sort(a, a+m);

	ll ans = 0, minP = 0, c = 0, d = 0;
	for (int i = 0; i < m; ++i) {
		ll value = a[i].first.first;
		int types = a[i].first.second;
		if (types == 0) {
			++c;
			sum -= value;
		}
		ll p = value;
		ll tmp = sum + c * p;
		if (tmp > ans) {
			ans = tmp;
			minP = p;
		}
		else if (tmp == ans)
			minP = min(minP, p);
		if (types == 1) {
			++d;
			if (i < m-1 && a[i+1].first.first > p) {
				c -= d;
				d = 0;
			}
		}
	}
	cout << minP << " " << ans << endl;
	return 0;
}