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
typedef pair<double, double> pdd;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const double EPS = 1e-18;


ll a, b, c, d;


pdd getRange(double x, double y, double z, double t) {
	double k1 = x*z, k2 = x*t, k3 = y*z, k4 = y*t;
	double mink = min(min(k1,k2), min(k3,k4));
	double maxk = max(max(k1,k2), max(k3,k4));
	return make_pair<double, double>(mink, maxk);
}


bool intersect(pdd x, pdd y) {
	if (fabs(x.first-y.first) < EPS || fabs(x.first-y.second) < EPS) return true;
	if (fabs(x.second-y.first) < EPS || fabs(x.second-y.second) < EPS) return true;
	if (x.first-y.first >= EPS && y.second-x.first >= EPS) return true;
	if (x.second-y.first >= EPS && y.second-x.second >= EPS) return true;
	if (y.first-x.first >= EPS && x.second-y.first >= EPS) return true;
	if (y.second-x.first >= EPS && x.second-y.second >= EPS) return true;
	return false;
}


bool check(double limit) {
	double la = a-limit, ra = a+limit;
	double lb = b-limit, rb = b+limit;
	double lc = c-limit, rc = c+limit;
	double ld = d-limit, rd = d+limit;
	pdd x = getRange(la, ra, ld, rd);
	pdd y = getRange(lb, rb, lc, rc);
	return intersect(x, y);
}


double solve() {
	double l = 0, r = max(max(abs(a), abs(b)), max(abs(c), abs(d)));
	double ans = r;
	for (int i = 0; i < 100000; ++i) {
		double mid = (l+r)/2;
		if (check(mid)) {
			ans = mid;
			r = mid;
		}
		else l = mid;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("549H.in", "r", stdin);
	freopen("549H.out", "w", stdout);
#endif
	a = read();
	b = read();
	c = read();
	d = read();
	printf("%.9lf\n", solve());
	return 0;
}