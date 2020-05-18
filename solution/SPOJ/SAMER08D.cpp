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
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 1004;


char a[MAX_N], b[MAX_N];
int c[MAX_N][MAX_N], f[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("SAMER08D.in", "r", stdin);
	freopen("SAMER08D.out", "w", stdout);
#endif
	int k;
	while (1) {
		scanf("%d\n", &k);
		if (k == 0) break;
		scanf("%s\n", a);
		scanf("%s\n", b);
		int n = strlen(a), m = strlen(b);
		for (int i = 0; i < m; ++i) c[0][i] = (a[0] == b[i]);
		for (int i = 0; i < n; ++i) c[i][0] = (a[i] == b[0]);
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				if (a[i] != b[j]) c[i][j] = 0;
				else c[i][j] = c[i-1][j-1] + 1;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				f[i][j] = 0;
				if (c[i][j] >= k) {
					f[i][j] = c[i][j];
					int limit = min(c[i][j], min(i, j));
					for (int d = k; d <= limit; ++d)
						f[i][j] = max(f[i][j], d + f[i-d][j-d]);
				}
				if (i > 0) f[i][j] = max(f[i][j], f[i-1][j]);
				if (j > 0) f[i][j] = max(f[i][j], f[i][j-1]);
			}
		printf("%d\n", f[n-1][m-1]);
	}
	return 0;
}