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


const int MAX_N = int(1e3)+4;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("492B.in", "r", stdin);
	freopen("492B.out", "w", stdout);
#endif
	int n = read();
	int l = read();
	a[0] = 0, a[n+1] = l;
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	sort(a+1, a+1+n);

	double ans = 0;
	for (int i = 1; i <= n+1; ++i)
		ans = max(ans, (a[i]-a[i-1])/2.0);
	if (a[1] != 0) ans = max(ans, double(a[1]));
	if (a[n] != l) ans = max(ans, double(l-a[n]));
	printf("%.9lf\n", ans);
	return 0;
}