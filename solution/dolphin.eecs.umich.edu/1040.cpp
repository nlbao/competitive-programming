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

const int MAX_M = int(1e2)+4;
const int MAX_N = MAX_M*MAX_M + 4;
const int oo = int(1e9);
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};

int n, m;
int h[MAX_N], w[MAX_N], d[MAX_N], id[MAX_M][MAX_M];
vector<int> e[MAX_N];
set<pii> heap;


inline bool ok(int x, int y) {
	return (x >= 0) && (x < m) && (y >= 0) && (y < n);
}


int dijkstra(int s, int t) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[s] = w[s];
	heap.erase(heap.begin(), heap.end());
	heap.insert(make_pair(d[s], s));
	while (!heap.empty()) {
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		if (u == t) break;
		for_each(it, e[u]) {
			int v = *it;
			int tmp = d[u] + w[v];
			if (tmp < d[v]) {
				set<pii>::iterator pos = heap.find(make_pair(d[v], v));
				if (pos != heap.end())
					heap.erase(pos);
				heap.insert(make_pair(tmp, v));
				d[v] = tmp;
			}
		}
	}
	return d[t];
}




int main() {
#ifdef DEBUG
	freopen("1040.in", "r", stdin);
	freopen("1040.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	int c = 0, maxH = -1;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			id[i][j] = ++c;
			h[c] = read();
			maxH = max(maxH, h[c]);
		}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k], y = j + dy[k];
				if (ok(x, y)) {
					e[id[i][j]].push_back(id[x][y]);
					e[id[x][y]].push_back(id[i][j]);
				}
			}

	n = c;
	int ans = oo;
	for (int x = 1; x <= maxH; ++x) {
		for (int i = 1; i <= n; ++i)
			w[i] = abs(h[i] - x);
		ans = min(ans, dijkstra(1, n));
	}
	printf("%d\n", ans);

	return 0;
}