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


const double EPS = 1e-9;

vector<pii> a;


int solve() {
	int n = a.size();
	if (n > 2) return -1;
	if (n < 2) return 0;
	// n == 2
	ll dx = a[0].first, dy = a[1].first;
	ll mx = a[0].second, my = a[1].second;
	if (mx == my) return 0;
	if (mx < my) {
		swap(dx, dy);
		swap(mx, my);
	}
	// mx > my
	double tx = mx + double(360-dx)/mx;
	double ty = double(360-dy)/my;
	// double tx = mx + double(dx)/mx;
	// double ty = double(dy)/my;
	if (tx < ty + EPS)
		return 0;

	// 2nd sol
	tx = double(360-dx)/mx;
	ty = double(360-dy)/my;
	// tx = double(dx)/mx;
	// ty = double(dy)/my;
	if (tx < ty + EPS)
		return 0;

	return 1;
}


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	// freopen("C-small-1-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int n = read();
		a.clear();
		for (int i = 0; i < n; ++i) {
			int d, h, m;
			scanf("%d%d%d", &d, &h, &m);
			for (int k = 0; k < h; ++k)
				a.push_back(make_pair(d, m+k));
		}
		int ans = solve();
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}