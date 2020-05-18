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




/*

UVA 12863 - Journey through the kingdom
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4728

ref: https://github.com/morris821028/UVa/blob/master/volume128/12863%20-%20Journey%20through%20the%20kingdom%5Bv4%5D.cpp#L54

*/

void updateRect(int lx, int rx, int ly, int ry, int cnt) {
	if (lx > rx || ly > ry) return;
	if (cnt == -1)
		cnt = rangeTree.getRect(lx, rx, ly, ry);
	if (cnt < 1) return;

	if (lx == rx) {
		if (ly == ry) {
			heap.push(HeapNode(lx, ly, value + cost[lx][ly], abs(lx-TX) + abs(ly-TY)));
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