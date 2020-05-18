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


const int MAX_R = 33;
const int MAX_N = 1e4 + 4;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int r, c, n;
bool ok[MAX_R][MAX_R];


int solve_0() {
	int m = r*c, ans = 4*m;
	for (int mask = 0; mask < (1<<m); ++mask) {
		int id = 0, sum = 0;
		for (int i = 0; i < m; ++i)
			if ((1<<i)&mask) ++sum;
		if (sum != n) continue;
		filla(ok, false);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) {
				if ((1<<id)&mask) ok[i][j] = true;
				++id;
			}
		sum = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) if (ok[i][j]) {
				for (int k = 1; k < 3; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < r && y < c && ok[x][y])
						++sum;
				}
			}
		ans = min(ans, sum);
	}
	return ans;
}



int solve_1(int n, int value) {
	vector<vector<bool> > ok;
	ok.resize(r);
	for (int i = 0; i < r; ++i)
		ok[i].resize(c, false);
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (n < 1) break;
			if ((i+j)%2 == value) {
				ok[i][j] = true;
				--n;
			}
		}
	if (n < 1) return 0;
	vector<int> a;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) if (!ok[i][j]) {
			int sum = 0;
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < r && y >= 0 && y < c && ok[x][y])
					++sum;
			}
			a.push_back(sum);
		}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += a[i];
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d%d%d", &r, &c, &n);
		// int ans = solve_0();
		int ans = min(solve_1(n, 0), solve_1(n, 1));
		printf("Case #%d: %d\n", testid, ans);
		// int t = min(solve_1(n, 0), solve_1(n, 1));
		// printf("Case #%d: %d, %d\n", testid, ans, t);
		// printf("Case #%d: %d, %d, %d\n", testid, ans, solve_1(n, 0), solve_1(n, 1));
	}
	return 0;
}