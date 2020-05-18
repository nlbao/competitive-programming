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

const int MAX_N = 1044;

int n, m, sX, sY, sumX;
char a[MAX_N][MAX_N];
int row[MAX_N][MAX_N], col[MAX_N][MAX_N];


bool check(int h, int w) {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (a[sX+i][sY+j] == '.')
				return false;
	int c = h*w;
	// cout << h << " " << w << endl;
	while (true) {
		int lenX = 0, lenY = 0;
		if (sX+h < n) lenX = row[sX+h][sY] - sY + 1;
		if (sY+w < m) lenY = col[sX][sY+w] - sX + 1;
		// cout << "	" << sX << " " << sY << endl;
		if (lenX != 0 && lenX < w) return false;
		if (lenY != 0 && lenY < h) return false;
		// if (lenX != 0 && lenY != 0) {
		// 	return
		// }
		if (lenX != 0) {
			++sX;
			c += w;
		}
		else if (lenY != 0) {
			++sY;
			c += h;
		}
		else break;
	}
	return (c == sumX);
}


int solve() {
	if (sX < 0) return 0;
	int minW = MAX_N, minH = MAX_N;
	for (int i = 0; i < n; ++i) {
		row[i][m] = m-1;
		for (int j = m-1; j >= 0; --j)
			if (a[i][j] == 'X') row[i][j] = row[i][j+1];
			else row[i][j] = j-1;
		for (int j = 0, k = 0; j < m; j = k+1) {
			while (j < m && a[i][j] == '.') ++j;
			if (j >= m) break;
			k = j;
			while (k < m && a[i][k] == 'X') ++k;
			minW = min(minW, k-j);
		}
	}
	for (int i = 0; i < m; ++i) {
		col[n][i] = n-1;
		for (int j = n-1; j >= 0; --j)
			if (a[j][i] == 'X') col[j][i] = col[j+1][i];
			else col[j][i] = j-1;
		for (int j = 0, k = 0; j < n; j = k+1) {
			while (j < n && a[j][i] == '.') ++j;
			if (j >= n) break;
			k = j;
			while (k < n && a[k][i] == 'X') ++k;
			minH = min(minH, k-j);
		}
	}

	int tsx = sX, tsy = sY;
	int h = -1, w = -1;

	int l = 1, r = minW;
	while (l <= r) {
		sX = tsx, sY = tsy;
		int mid = (l+r)>>1;
		if (check(minH, mid)) {
			if (h < 0 || minH*mid < h*w) {
				h = minH;
				w = mid;
			}
			r = mid-1;
		}
		else l = mid+1;
	}

	l = 1, r = minH;
	while (l <= r) {
		sX = tsx, sY = tsy;
		int mid = (l+r)>>1;
		if (check(mid, minW)) {
			if (h < 0 || mid*minW < h*w) {
				h = mid;
				w = minW;
			}
			r = mid-1;
		}
		else l = mid+1;
	}

	sX = tsx, sY = tsy;
	if (check(1, minW) && (h < 0 || minW < h*w)) h = 1, w = minW;
	sX = tsx, sY = tsy;
	if (check(minH, 1) && (h < 0 || minH < h*w)) h = minH, w = 1;

	l = 1, r = minW;
	while (l <= r) {
		sX = tsx, sY = tsy;
		int mid = (l+r)>>1;
		if (check(minH, mid)) {
			if (h < 0 || minH*mid < h*w) {
				h = minH;
				w = mid;
			}
			l = mid+1;
		}
		else r = mid-1;
	}

	l = 1, r = minH;
	while (l <= r) {
		sX = tsx, sY = tsy;
		int mid = (l+r)>>1;
		if (check(mid, minW)) {
			if (h < 0 || mid*minW < h*w) {
				h = mid;
				w = minW;
			}
			l = mid+1;
		}
		else r = mid-1;
	}

	if (h < 0) return -1;
	return h*w;
}


int main() {
#ifdef DEBUG
	freopen("475C.in", "r", stdin);
	freopen("475C.out", "w", stdout);
#endif
	scanf("%d%d\n", &n, &m);
	sX = sY = -1;
	sumX = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s\n", a[i]);
		for (int j = 0; j < m; ++j)
			if (a[i][j] == 'X') {
				if (sX < 0)
					sX = i, sY = j;
				++sumX;
			}
	}

	// if (n == 30) {
	// 	for (int i = 15; i < n; ++i) {
	// 		for (int j = 0; j < m; ++j)
	// 			printf("%c", a[i][j]);
	// 		printf("\n");
	// 	}
	// }

	printf("%d\n", solve());
	return 0;
}