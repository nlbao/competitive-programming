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


int main() {
#ifdef DEBUG
	freopen("100523A.in", "r", stdin);
	freopen("100523A.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		ans = 0;

		int t = 0;
		for (int row = 1; row <= n; ++row) {
			int tt = 1-t;
			for (int col = 1; col <= m; ++col) {
				a[tt][col] = read();
				// height
				h[tt][col] = 1;
				dh[tt][col] = a[tt][col] - a[t][col];
				if (row > 2) h[tt][col] = 1 + (dh[tt][col] == dh[t][col] ? h[t][col] : 1);
				else if (row > 1) h[tt][col] = 2;
				// left
				dl[col] = a[tt][col] - a[tt][col-1];
				if (col > 2) l[col] = 1 + (dh[tt][col] == dh[t][col] ? h[t][col] : 1);
			}
			// right
			for (int col = m; col >= 1; --col)
				dr[col] = a[tt][col] - a[tt][col+1];

			t = tt;
		}
		printf("%d\n", ans);
	}
	return 0;
}