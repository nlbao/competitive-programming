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

const int MAX_N = 110;
const int MAX_K = 110;
const int oo = int(1e9);


int m, n;
string s;
int a[MAX_N][MAX_N], c[MAX_N][MAX_N];
int f[MAX_N][MAX_N][MAX_K];


int main() {
#ifdef DEBUG
	freopen("kth-shortest-path.in", "r", stdin);
	freopen("kth-shortest-path.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d\n", &m, &n);

		for (int i = 0; i < m; ++i) {
			getline(cin, s);
			int len = s.length();
			for (int t = 0, j = 0; j < n; ++j) {
				int k = t, value = 0;
				bool found = false;
				while (k < len && s[k] != ' ') {
					if (s[k] != '#') {
						value = value*10 + s[k]-'0';
						found = true;
					}
					++k;
				}
				t = k + 1;
				if (!found) a[i][j] = oo;
				else a[i][j] = value;
			}
		}

		// init
		c[0][0] = 1;
		f[0][0][1] = a[0][0];
		for (int i = 1; i < m; ++i) {
			if (a[i][0] >= oo || c[i-1][0] == 0) {
				c[i][0] = 0;
				continue;
			}
			c[i][0] = 1;
			f[i][0][1] = f[i-1][0][1] + a[i][0];
		}
		for (int i = 1; i < n; ++i) {
			if (a[0][i] >= oo || c[0][i-1] == 0) {
				c[0][i] = 0;
				continue;
			}
			c[0][i] = 1;
			f[0][i][1] = f[0][i-1][1] + a[0][i];
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				c[i][j] = 0;
				if (a[i][j] >= oo) continue;
				int i1 = i-1, j1 = j-1;
				int x = 1, y = 1;
				while (c[i][j] < MAX_K-2 && x <= c[i1][j] && y <= c[i][j1]) {
					if (f[i1][j][x] < f[i][j1][y])
						f[i][j][++c[i][j]] = f[i1][j][x++];
					else
						f[i][j][++c[i][j]] = f[i][j1][y++];
				}
				while (c[i][j] < MAX_K-2 && x <= c[i1][j])
					f[i][j][++c[i][j]] = f[i1][j][x++];
				while (c[i][j] < MAX_K-2 && y <= c[i][j1])
					f[i][j][++c[i][j]] = f[i][j1][y++];
				for (int t = 1; t <= c[i][j]; ++t)
					f[i][j][t] += a[i][j];
			}
		}

		int nQ = read();
		while (nQ--) {
			int tx, ty, k;
			scanf("%d%d%d", &tx, &ty, &k);
			if (a[tx][ty] >= oo) printf("Obstacle\n");
			else if (c[tx][ty] < k) printf("Not so many paths\n");
			else printf("%d\n", f[tx][ty][k]);
		}
	}
	return 0;
}