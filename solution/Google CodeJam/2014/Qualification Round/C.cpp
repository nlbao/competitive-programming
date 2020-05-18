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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }



const int MAX_N = 11;
const int dx[8] = {-1, -1, -1, 0, +1, +1, +1, 0};
const int dy[8] = {-1, 0, +1, +1, +1, 0, -1, -1};



int m, n, nMine;
int a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];


bool onBoard(int x, int y) {
	return (x >= 0) && (x < m) && (y >= 0) && (y < n);
}



int dfs(int i, int j) {
	visited[i][j] = true;
	int c = 1;
	if (a[i][j] == 0)
		for (int k = 0; k < 8; ++k) {
			int x = i+dx[k];
			int y = j+dy[k];
			if (onBoard(x, y) && a[x][y] != -1 && !visited[x][y])
				c += dfs(x, y);
		}
	return c;
}



int calA(int &sx, int &sy) {
	int c = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) if (a[i][j] != -1) {
			++c;
			for (int k = 0; k < 8; ++k) {
				int x = i+dx[k];
				int y = j+dy[k];
				if (onBoard(x, y) && a[x][y] == -1) ++a[i][j];
			}
			if (a[i][j] == 0) sx = i, sy = j;
		}
	if (sx == -1)
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] != -1) {
					sx = i;
					sy = j;
				}
	return c;
}



void print_result(int sx, int sy) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			if (a[i][j] == -1) printf("*");
			else if (i == sx && j == sy) printf("c");
			else printf(".");
		printf("\n");
	}
}



bool check() {
	int sx = -1, sy = -1;
	int c = calA(sx, sy);
	fill(visited, false);
	if (c && sx >= 0 && dfs(sx, sy) == c) {
		print_result(sx, sy);
		return true;
	}
	return false;
}



bool solve() {
	if (nMine >= m*n)
		return false;
	for (int sx = 0; sx < m; ++sx) {
		for (int sy = 0; sy < n; ++sy) {
			fill(a, 0);
			fill(visited, false);
			queue<ppi> q;
			q.push(make_pair(sx, sy));
			visited[sx][sy] = true;

			int nEmpty = m*n - nMine - 1;
			while (!q.empty() && nEmpty > 0) {
				int i = q.front().first, j = q.front().second;
				q.pop();
				//cout << "		" << i << " " << j << endl;
				for (int k = 0; k < 8; ++k) {
					int x = i+dx[k];
					int y = j+dy[k];
					if (onBoard(x, y) && !visited[x][y]) {
						q.push(make_pair(x, y));
						visited[x][y] = true;
						--nEmpty;
					}
				}
			}

			//cout << nEmpty << endl;

			if (nEmpty != 0) continue;

			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					if (!visited[i][j])
						a[i][j] = -1;
			if (check()) return true;
		}
	}
// ////////////////////////////////////////////////////////////////////////////
	fill(a, 0);
	int k = nMine;
	for (int j = n-1; j >= 0; --j)
		for (int i = m-1; i >= 0; --i)
			if (k) a[i][j] = -1, --k;
	if (check()) return true;
// ////////////////////////////////////////////////////////////////////////////
	if (m >= n) {
		fill(a, 0);
		k = nMine;
		int d = min(m-2, n);
		for (int i = m-1; i >= m-d; --i)
			for (int j = n-1; j >= 0; --j)
				if (k) a[i][j] = -1, --k;
		for (int j = n-1; j >= 0; --j)
			for (int i = 0; i < m-d; ++i)
				if (k) a[i][j] = -1, --k;
		if (check()) return true;
	}
// ////////////////////////////////////////////////////////////////////////////
	if (n >= m) {
		fill(a, 0);
		k = nMine;
		int d = min(m, n-2);
		for (int j = n-1; j >= n-d; --j)
			for (int i = m-1; i >= 0; --i)
				if (k) a[i][j] = -1, --k;
		for (int i = m-1; i >= 0; --i)
			for (int j = 0; j < n-d; ++j)
				if (k) a[i][j] = -1, --k;
		if (check()) return true;
	}
// ////////////////////////////////////////////////////////////////////////////
	fill(a, 0);
	k = nMine;
	for (int d = 0; d <= max(m-1, n-1); ++d) {
		if (k <= 0) break;
		for (int i = m-1; i >= 0; --i) if (k)
			for (int j = n-1; j >= 0; --j)
				if (k && max(m-1-i, n-1-j) == d)
					a[i][j] = -1, --k;
	}
	if (check()) return true;
// ////////////////////////////////////////////////////////////////////////////
	fill(a, 0);
	k = nMine;
	for (int d = 0; d <= max(m-1, n-1); ++d) {
		if (k <= 0) break;
		for (int i = 0; i < m; ++i) if (k)
			for (int j = 0; j < n; ++j) if (k) {
				int t = min(min(i, j), min(m-1-i, n-1-j));
				if (t == d)
					a[i][j] = -1, --k;
			}
	}
	if (check()) return true;
//////////////////////////////////////////////////////////////////////////
	return false;
}



int main() {
#ifdef DEBUG
	freopen("C-large-practice.in", "r", stdin);
	// freopen("C-small-practice.in", "r", stdin);
	// freopen("C-small-attempt4.in", "r", stdin);
	// freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%d%d%d", &m, &n, &nMine);
		printf("Case #%d:\n", test_id);
		if (!solve())
			printf("Impossible\n");
	}
	return 0;
}