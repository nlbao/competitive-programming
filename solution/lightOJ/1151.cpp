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

const int MAX_N = int(1e2)+5;
const int oo = int(1e9);
const double EPS = 1e-9;


vector< vector<double> > a;


int gauss(vector< vector<double> > &a, vector<double> &ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (fabs(a[i][col]) > fabs(a[k][col]))
				k = i;
		if (fabs(a[k][col]) < EPS) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j = col+1; j <= m; ++j)
					a[i][j] -= a[row][j] * c;
				a[i][col] = 0;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (fabs(a[i][j]) >= EPS) {
				zero = false;
				break;
			}
		if (zero && fabs(a[i][m]) >= EPS)
			return 0;
	}

	int rank = 0;
	ans.assign(m, 0);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (fabs(a[i][j]) >= EPS) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) return oo;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("1151.in", "r", stdin);
	freopen("1151.out", "w", stdout);
#endif
	int nTest = read();
	int n = 100;

	for (int test_id = 1; test_id <= nTest; ++test_id) {
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(n, 0);
			a[i][i] = -1;
		}

		int m = read();
		filla(cnt, 0);
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			++cnt[x];
			a[x][y] = 1;
		}

		for (int i = 0; i < n; ++i) {
			for (int )
		}

		ll ans = 0;
		int rank;
		int nSolution = gauss(a, rank);
		if (nSolution > 0) {
			if (nSolution == 1) ans = 1;
			else ans = mpow(K, n-rank, MODULE);
		}
		printf("Case %d: %d\n", test_id, (int)ans);
	}
	return 0;
}