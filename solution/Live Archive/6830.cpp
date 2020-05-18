#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 505;
const int oo = 1e9;


struct Rectangle {
	int x1, y1, x2, y2;
};


struct RangeTree {	// BIT 2D
	int m, n;
	int cnt[MAX_N][MAX_N];

	void init(int _m, int _n) {
		m = _m, n = _n;
		filla(cnt, 0);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				update(i, j, 1);
	}

	void update(int x, int y, int value) {
		for (; x <= m; x += x&(-x))
			for (int i = y; i <= n; i += i&(-i))
				cnt[x][i] += value;
	}

	int get(int x, int y) {
		int ans = 0;
		for (; x > 0; x -= x&(-x))
			for (int i = y; i > 0; i -= i&(-i))
				ans += cnt[x][i];
		return ans;
	}

	int getRect(int x1, int x2, int y1, int y2) {
		return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
	}
};


int cnt;
int m, n, nQ, value;
int cost[MAX_N][MAX_N], row[MAX_N][MAX_N], col[MAX_N][MAX_N];
Rectangle rec[MAX_N][MAX_N];
RangeTree rangeTree;

typedef pair<int, pii> HeapNode;
set<HeapNode> heap;


void updateRect(int lx, int rx, int ly, int ry, int cnt) {
	if (lx > rx || ly > ry) return;
	if (cnt == -1)
		cnt = rangeTree.getRect(lx, rx, ly, ry);
	if (cnt < 1) return;

	if (lx == rx) {
		if (ly == ry) {
			heap.insert(HeapNode(value + cost[lx][ly], pii(lx, ly)));
			rangeTree.update(lx, ly, -1);
			return;
		}
		int mid = (ly+ry)>>1;
		int c = rangeTree.getRect(lx, rx, ly, mid);
		if (c) updateRect(lx, rx, ly, mid, c);
		if (cnt-c) updateRect(lx, rx, mid+1, ry, cnt-c);
	}
	else {
		int mid = (lx+rx)>>1;
		int c = rangeTree.getRect(lx, mid, ly, ry);
		if (c) updateRect(lx, mid, ly, ry, c);
		if (cnt-c) updateRect(mid+1, rx, ly, ry, cnt-c);
	}
}


int solve(int sx, int sy, int tx, int ty) {
	if (sx == tx && sy == ty) return 0;
	rangeTree.init(m, n);
	rangeTree.update(sx, sy, -1);
	heap.clear();
	heap.insert(HeapNode(cost[sx][sy], pii(sx, sy)));

	while (!heap.empty()) {
		HeapNode u = *heap.begin();
		heap.erase(*heap.begin());
		int x = u.second.first, y = u.second.second, d = u.first;
		if (abs(x-tx) <= row[x][y] && abs(y-ty) <= col[x][y])
			return d;
		value = d;
		updateRect(rec[x][y].x1, rec[x][y].x2, rec[x][y].y1, rec[x][y].y2, -1);
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("6830.in", "r", stdin);
	freopen("6830.out", "w", stdout);
#endif
	while (scanf("%d%d%d", &m, &n, &nQ) == 3) {
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &cost[i][j]);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &row[i][j]);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &col[i][j]);

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) {
				rec[i][j].x1 = max(1, i - row[i][j]);
				rec[i][j].y1 = max(1, j - col[i][j]);
				rec[i][j].x2 = min(m, i + row[i][j]);
				rec[i][j].y2 = min(n, j + col[i][j]);
			}

		for (int i = 0, x1, y1, x2, y2; i < nQ; ++i) {
			scanf("%d%d", &x2, &y2);
			if (i > 0) {
				printf("%d", solve(x1, y1, x2, y2));
				if (i < nQ-1) printf(" ");
			}
			x1 = x2, y1 = y2;
		}
		printf("\n");
	}
	return 0;
}