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


const int MAX_N = 111;


int n, m;
int a[MAX_N], b[MAX_N];


bool solve() {
	if (n < 3 || (n == 3 && m == 3)) {
		printf("0 0\n");
		return true;
	}
	if (n == 3 && m == 2) {
		int d[4];
		filla(d, 0);
		for (int i = 0; i < m; ++i) {
			++d[a[i]];
			++d[b[i]];
		}
		int u = -1;
		for (int i = 1; i <= n; ++i)
			if (d[i] == 2) {
				u = i - 1;
				break;
			}
		printf("2 3\n");
		printf("%d %d\n", 4, u + 1);
		printf("%d %d\n", 5, (u+1)%3 + 1);
		printf("%d %d\n", 5, (u+2)%3 + 1);
		return true;
	}
	int a = n+1, b = n+2, c = n+3, d = n+4;
	printf("%d %d\n", 4, 2*n + 2);
	printf("%d %d\n", a, b);
	printf("%d %d\n", c, d);
	for (int i = 1; i <= n; ++i) {
		printf("%d %d\n", i, a);
		printf("%d %d\n", i, c);
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("HISTJUNK.in", "r", stdin);
	freopen("HISTJUNK.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (m < 4) a[i] = u, b[i] = v;
		}
		if (!solve())
			printf("-1 -1\n");
	}
	return 0;
}