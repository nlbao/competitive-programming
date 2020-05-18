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


const int MAX_N = 3004;
const int MAX_P = (1<<4) + 4;


int n, m, s1, t1, s2, t2, l1, l2;
int d[MAX_N][MAX_N];
int f[MAX_P][MAX_N];
set<pii, int> heap;


void bfs(int s) {
	d[s][s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();	q.pop();
		int tmp = d[s][u]+1;
		for (int v = 1; v <= n; ++v)
			if (d[s][v] == oo) {
				d[s][v] = tmp;
				q.push(v);
			}
	}
}


int bitCount(int x) {
	return __builtin_popcount((unsigned int)x);
}


int contains(int x, int y) {
	return ((~x) & y) == 0;
}


void update(int x, int u, int value) {
	if (value <= f[x][u]) return;
	f[x][u] = value;
	pii p = make_pair(x, u);
	// if (heap.find(p) == heap.end())
		// heap[p] = f[]
	heap[p] = value;
}


int solve() {
	if (d[s1][t1] > l1) return -1;
	if (d[s2][t2] > l2) return -1;
	int nMask = 1<<4;
	for (int x = 0; x < nMask; ++x)
		for (int i = 1; i <= n; ++i) {
			if (x == 0) f[x][i] = 0;
			else f[x][i] = oo;
		}
	f[1<<0][s1] = 0;
	f[1<<1][t1] = 0;
	f[1<<2][s2] = 0;
	f[1<<3][t2] = 0;
	for (int x = 0; x < nMask; ++x)
		for (int i = 1; i <= n; ++i)
			if (f[x][i] == 0)
				heap[make_pair(x, i)] = 0;
	while (!heap.empty()) {
		set<pii, int>::iterator top = heap.begin();
		int x = top->first, u = top->second;
		heap.erase(top);
		for (int y = 0; y < nMask; ++y) if (f[y][u] < oo)
			update(x|y, u, f[x][u] + f[y][u]);
		for (int v = 1; v <= n; ++v) if (v != u && d[u][v] == 1)
			for (int y = 0; y < nMask; ++y) if (f[y][v] < oo) {
				update(x|y, u, f[x][u] + f[y][v] + 1);
				update(x|y, v, f[x][u] + f[y][v] + 1);
			}
	}
	int ans = m;
	for (int u = 1; u <= n; ++u)
		ans = min(ans, f[nMask-1][u]);
	for (int u = 1; u <= n; ++u)
		for (int x = 0; x < nMask; ++x) if (contains(x, 3))
			for (int v = 1; v <= n; ++v) if (v != u)
				for (int y = 0; y < nMask; ++y) if (contains(y, 12))
					ans = min(ans, f[x][u] + f[y][v]);
	return m - ans;
}


int main() {
#ifdef DEBUG
	freopen("543B.in", "r", stdin);
	freopen("543B.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = oo;
	for (int i = 1; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[x][y] = d[y][x] = 1;
	}
	for (int i = 1; i <= n; ++i)
		bfs(i);

	scanf("%d%d%d", &s1, &t1, &l1);
	scanf("%d%d%d", &s2, &t2, &l2);
	printf("%d\n", solve());
	return 0;
}