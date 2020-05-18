#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> node;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 222;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const char DIRECTION[4] = {'R', 'F', 'L', 'B'};
const int ROTATE[4][4] = {
	{1, 0, 3, 2},
	{2, 1, 0, 3},
	{3, 2, 1, 0},
	{0, 3, 2, 1}
};


string s;
int len, ans[MAX_N][MAX_N];
set<pii> a, b;


inline int find(char x) {
	for (int i = 0; i < 4; ++i)
		if (DIRECTION[i] == x)
			return i;
	return -1;
}


void solve() {
	a.clear();
	b.clear();
	int x = 0, y = 0, d = 1;
	a.insert(pii(x, y));
	for (int i = 0; i < len; ++i) {
		int t = find(s[i]);
		for (int j = 0; j <= t; ++j) {
			int k = ROTATE[d][t];
			int xx = x + dx[k], yy = y + dy[k];
			if (j < t) b.insert(pii(xx, yy));
			else {
				a.insert(pii(xx, yy));
				x = xx, y = yy;
				d = k;
			}
		}
	}

	foreach(it, a) {
		int x = it->first, y = it->second;
		if (x == 0 && y == 0) continue;
		for (int k = 0; k < 4; ++k) {
			int xx = x + dx[k], yy = y + dy[k];
			pii u(xx, yy);
			if (a.find(u) == a.end() && b.find(u) == b.end())
				b.insert(u);
		}
	}

	int minX = 1e9, minY = 1e9;
	int maxX = -minX, maxY = -minY;
	foreach(it, a) {
		int x = it->first, y = it->second;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	foreach(it, b) {
		int x = it->first, y = it->second;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}

	int h = maxX - minX + 1, w = maxY - minY + 1;
	filla(ans, 0);
	foreach(it, a) {
		int x = it->first - minX;
		int y = it->second - minY;
		ans[x][y] = 1;
	}

	printf("%d %d\n", h, w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			if (ans[i][j]) printf(".");
			else printf("#");
		printf("\n");
	}
}


int main() {
#ifdef DEBUG
	freopen("100526J.in", "r", stdin);
	freopen("100526J.out", "w", stdout);
#endif
	int nTest = read();
	printf("%d\n", nTest);
	getline(cin, s);
	while (nTest--) {
		getline(cin, s);
		len = s.length();
		solve();
	}
	return 0;
}