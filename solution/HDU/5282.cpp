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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e3 + 33;
const int MAX_A = 33;
const ll MODULE = 1e9 + 7;


int n, m;
char s[MAX_N];
int a[MAX_N], b[MAX_N];
int d[MAX_N][MAX_N], f[MAX_N][MAX_N];
int pre[MAX_N][MAX_A];


int main() {
#ifdef DEBUG
	freopen("5282.in", "r", stdin);
	freopen("5282.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'a';
		scanf("%s", s);
		m = strlen(s);
		for (int i = 1; i <= m; ++i) b[i] = s[i-1]-'a';

		filla(d, 0);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				d[i][j] = max(d[i-1][j], d[i][j-1]);
				if (a[i] == b[j])
					d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
			}

		if (d[n][m] == 0) {
			printf("1\n");
			continue;
		}

		for (int i = 0; i < MAX_A; ++i)
			pre[0][i] = -1;
		for (int i = 1; i <= m; ++i) {
			for(int x = 0; x < MAX_A; ++x)
				pre[i][x] = pre[i-1][x];
			pre[i][b[i]] = i;
		}

		filla(f, 0);
		for (int i = 0; i <= max(m, n); ++i)
			f[0][i] = f[i][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (d[i][j] == 0) {
					f[i][j] = 1;
					continue;
				}
				if (d[i-1][j] == d[i][j])
					f[i][j] = f[i-1][j];
				int k = pre[j][a[i]];
				if (k < 1) continue;
				if (d[i-1][k-1] + 1 == d[i][j])
					f[i][j] = (f[i][j] + f[i-1][k-1]) % MODULE;
			}

		printf("%d\n", f[n][m]);
	}
	return 0;
}