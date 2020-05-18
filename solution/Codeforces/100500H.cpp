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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e3)+3;

int f[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("100500H.in", "r", stdin);
	freopen("100500H.out", "w", stdout);
#endif
	int nTest = read(), n, m;
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				f[i][j] = read();
		for (int i = 2; i <= n; ++i)
			f[i][1] += f[i-1][1];
		for (int i = 2; i <= m; ++i)
			f[1][i] += f[1][i-1];
		for (int i = 2; i <= n; ++i)
			for (int j = 2; j <= m; ++j)
				f[i][j] += max(f[i-1][j], f[i][j-1]);
		printf("Case %d: %d\n", test_id, f[n][m]);
	}
	return 0;
}