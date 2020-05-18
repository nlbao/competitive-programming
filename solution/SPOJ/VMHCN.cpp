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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 2003;
const int MAX_IT = 4*MAX_N;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m, u, v, value;
char a[MAX_N][MAX_N];
int f[MAX_IT], sum[MAX_IT];
queue<pair<int, int> > q;
vector<pair<int, int> > start[MAX_N], finish[MAX_N];
bool ok[MAX_N][MAX_N];


void bfs(int u, int v) {
	int maxX = u, minX = u, maxY = v, minY = v;
	while (!q.empty()) q.pop();
	q.push(make_pair(u, v));
	ok[u][v] = false;
	while (!q.empty()) {
		u = q.front().first;
		v = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int x = u + dx[k], y = v + dy[k];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (ok[x][y] && a[x][y] == 'o') {
				q.push(make_pair(x, y));
				ok[x][y] = false;
				maxX = max(maxX, x);
				minX = min(minX, x);
				maxY = max(maxY, y);
				minY = min(minY, y);
			}
		}
	}
	start[minY].push_back(make_pair(minX, maxX));
	finish[maxY].push_back(make_pair(minX, maxX));
}


void update(int k, int l, int r) {
	if (l > r || l > v || r < u) return;
	if (u <= l && r <= v) {
		sum[k] += value;
		f[k] += value;
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid);
	update(right, mid+1, r);
	f[k] = max(f[left], f[right]) + sum[k];
}


int main() {
#ifdef DEBUG
	freopen("VMHCN.in", "r", stdin);
	freopen("VMHCN.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		scanf("%d%d\n", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s\n", a[i]);

		fill(ok, true);
		for (int i = 0; i < m; ++i) {
			start[i].clear();
			finish[i].clear();
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (ok[i][j] && a[i][j] == 'o')
					bfs(i, j);

		int res = 0;
		fill(f, 0);
		fill(sum, 0);
		for (int id = 0; id < m; ++id) {
			for (int i = 0, sz = start[id].size(); i < sz; ++i) {
				u = start[id][i].first + 1;
				v = start[id][i].second + 1;
				value = 1;
				update(1, 1, m);
			}
			res = max(res, f[1]);
			for (int i = 0, sz = finish[id].size(); i < sz; ++i) {
				u = finish[id][i].first + 1;
				v = finish[id][i].second + 1;
				value = -1;
				update(1, 1, m);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}