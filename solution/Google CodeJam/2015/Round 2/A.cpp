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
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m;
char a[MAX_N][MAX_N];
int b[MAX_N][MAX_N], id[MAX_N][MAX_N];


bool isImpossible() {
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != '.') {
				bool ck = false;
				for (int k = 0; k < n; ++k)
					if (k != j && a[i][k] != '.') {
						ck = true;
						break;
					}
				for (int k = 0; k < m; ++k)
					if (k != i && a[k][j] != '.') {
						ck = true;
						break;
					}
				if (!ck) return true;
			}
	return false;
}


int findNext(int x, int y, int dir) {
    do {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || y < 0 || x >= m || y >= n) break;
        if (a[x][y] != '.')
            return true;
    } while (true);
    return false;
}


int solve() {
    int ans = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != '.') {
                int dir;
                if (a[i][j] == '^') dir = 0;
                else if (a[i][j] == '>') dir = 1;
                else if (a[i][j] == 'v') dir = 2;
                else if (a[i][j] == '<') dir = 3;
                bool ok = findNext(i, j, dir);
                if (!ok) ++ans;
			}
    return ans;
}


int main() {
#ifdef DEBUG
    // freopen("A.in", "r", stdin);
    // freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; ++i)
			scanf("%s", a[i]);
		// for (int i = 0; i < m; ++i)
		// 	printf("%s\n", a[i]);
		printf("Case #%d: ", testid);
		if (isImpossible()) printf("IMPOSSIBLE\n");
		else printf("%d\n", solve());
	}
	return 0;
}