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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2004;

ll a[MAX_N][MAX_N];
ll c[2*MAX_N], d[2*MAX_N];


int main() {
#ifdef DEBUG
	freopen("463C.in", "r", stdin);
	freopen("463C.out", "w", stdout);
#endif
	int n = read();
	fill(c, 0);
	fill(d, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
			c[i+j] += a[i][j];
			d[i-j+n] += a[i][j];
		}

	ll ans1 = -1, ans2 = -1;
	int x1, x2, y1, y2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ll x = c[i+j] + d[i-j+n] - a[i][j];
			if ((i+j)%2 == 0) {
				if (x > ans1) {
					ans1 = x;
					x1 = i;	y1 = j;
				}
			}
			else if (x > ans2) {
				ans2 = x;
				x2 = i;	y2 = j;
			}
		}
	}
	cout << ans1 + ans2 << endl;
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	return 0;
}