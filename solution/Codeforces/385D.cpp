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

const int MAX_N = 22;
const double PI = M_PI;
const double EPS = 1e-7;


double a[2][MAX_N], b[2][MAX_N], degree[MAX_N];
pair<double, double> p[MAX_N];


int main() {
#ifdef DEBUG
	freopen("385D.in", "r", stdin);
	freopen("385D.out", "w", stdout);
#endif
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; ++i) {
		double x = read(), y = read();
		degree[i] = double(read())*PI/180.0;
		a[0][i] = x - y*tan(degree[i]);
		b[0][i] = a[1][i] = x;
		b[1][i] = x + y*tan(degree[i]);

		printf("%.4lf %.4lf %.4lf = %.4lf\n", x, y, degree[i], tan(degree[i]));
		for (int k = 0; k < 2; ++k)
			printf("	%d %d: %.4lf %.4lf\n", i, k, a[k][i], b[k][i]);
	}

	int limit = (1<<n);
	double ans = 0;
	for (int mask = 0; mask < limit; ++mask) {
		for (int i = 0; i < n; ++i) {
			int k = mask & (1<<i);
			p[i] = make_pair(a[k][i], b[k][i]);
		}
		sort(p, p+n);
		double x = l;
		for (int i = 0; i < n; ++i) {
			while (i < n && p[i].second + EPS < x)
				++i;
			if (i >= n || x + EPS < p[i].first) break;
			x = p[i].second;
			ans = max(ans, x-l);
		}
	}
	printf("%.6lf\n", ans);
	return 0;
}