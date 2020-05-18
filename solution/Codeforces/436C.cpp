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

const int MAX_K = 1003;
const int MAX_N = 12;
const int oo = int(1e9)+9;

int n, m, k, w;
int d[MAX_K], pre[MAX_K];
char s[MAX_K][MAX_N][MAX_N];
vector<pair<int, int> > res;
bool ok[MAX_K];


int calCost(int u, int v) {
	if (u == 0) return n*m;
	int c = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			c += (s[u][i][j] != s[v][i][j]);
	return c*w;
}


void push(int u) {
	ok[u] = false;
	for (int v = 1; v <= k; ++v) {
		if (!ok[v]) continue;
		int t = calCost(u, v);
		if (t < d[v]) {
			d[v] = t;
			pre[v] = u;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("436C.in", "r", stdin);
	freopen("436C.out", "w", stdout);
#endif
	scanf("%d%d%d%d\n", &n, &m, &k, &w);
	for (int t = 1; t <= k; ++t)
		for (int i = 0; i < n; ++i)
			scanf("%s\n", s[t][i]);

	int cost = 0;
	fill(ok, true);
	for (int i = 1; i <= k; ++i) d[i] = oo;
	push(0);
	for (int t = 0; t < k; ++t) {
		int minD = oo, u = -1;
		for (int x = 1; x <= k; ++x)
			if (ok[x] && d[x] < minD) {
				minD = d[x];
				u = x;
			}
		res.push_back(make_pair(u, pre[u]));
		cost += minD;
		push(u);
	}

	printf("%d\n", cost);
	for (int i = 0, sz = res.size(); i < sz; ++i)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}