#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 2002;

char s[MAX_N];
int c[3][MAX_N][MAX_N];


int num(char x) {
	if (x == 'L') return 0;
	if (x == 'R') return 1;
	if (x == 'U') return 2;
	return 3;
}



int main() {
#ifdef DEBUG
	freopen("436B.in", "r", stdin);
	freopen("436B.out", "w", stdout);
#endif
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	fill(c, 0);
	scanf("\n");
	for (int i = 0; i < n; ++i) {
		scanf("%s\n",s);
		for (int j = 0; j < m; ++j) {
			int v = num(s[j]);
			if (v < 3) ++c[v][i][j];
		}
	}

	for (int y = 0; y < m; ++y) {
		int res = 0;
		for (int x = 1; x < n; ++x) {
			if (x+y < m) res += c[0][x][x+y];
			if (y-x >= 0) res += c[1][x][y-x];
			if (2*x < n) res += c[2][2*x][y];
		}
		printf("%d ", res);
	}
	return 0;
}