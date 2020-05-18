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

const int MAX_N = 1003;
const int MAX_M = 2*MAX_N;

int m = MAX_M;
char res[MAX_M][MAX_M];
int a[MAX_M], x[MAX_M], y[MAX_M];


int main() {
#ifdef DEBUG
	freopen("435C.in", "r", stdin);
	freopen("435C.out", "w", stdout);
#endif
	int n = read();
	int ymax = 0, xmax = 0, ymin = 100*MAX_M;
	a[0] = y[0] = x[0] = ymax = xmax = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		x[i] = x[i-1] + a[i];
		if (i&1) y[i] = y[i-1] + a[i];
		else y[i] = y[i-1] - a[i];
		xmax = max(xmax, x[i]);
		ymax = max(ymax, y[i]);
		ymin = min(ymin, y[i]);
	}

	ymax += MAX_N;
	ymin += MAX_N;
	xmax += MAX_N;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			res[i][j] = ' ';
	for (int i = 0; i < n; ++i) {
		int d = 1;
		char ch = '/';
		int xx = x[i] + MAX_N;
		int yy = y[i] + MAX_N;
		if (y[i] > y[i+1]) {
			d = -1;
			ch = '\\';
		}
		else ++yy;
		for (int j = 0; j < a[i+1]; ++j) {
			res[yy][xx++] = ch;
			yy += d;
		}
	}

	for (int i = ymax; i > ymin; --i)
		for (int j = MAX_N; j < xmax; ++j) {
			printf("%c", res[i][j]);
			if (j < xmax-1) printf(" ");
			else printf("\n");
		}
	return 0;
}