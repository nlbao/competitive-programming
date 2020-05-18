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
char a[MAX_N][MAX_N];
int col[MAX_N], s[MAX_N];


int solve() {
	int ans = 0;
	filla(col, 0);
	for (int i = m-1; i >= 0; --i) {
		int row = 0;
		for (int j = 0; j <= n; ++j) s[j] = 0;
		for (int j = n-1; j >= 0; --j) {
			int tmp = a[i][j] == 'W' ? 1 : -1;
			int k = tmp - (col[j] + row);
			if (k == 0) continue;
			s[j] = k;
			row += k;
			++ans;
		}
		for (int j = n-1; j >= 0; --j) {
			s[j] += s[j+1];
			col[j] += s[j];
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("549D.in", "r", stdin);
	freopen("549D.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		scanf("%s", a[i]);
	printf("%d\n", solve());
	return 0;
}