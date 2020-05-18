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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e6)+6;

int n, m, s, k;
vector<int> e[MAX_N], ans;
int p[MAX_N];
bool isK[MAX_N], hasK[MAX_N], ok[MAX_N];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


void dfs_0(int u) {
	ok[u] = false;
	hasK[u] = isK[u];
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			dfs_0(v);
			hasK[u] |= hasK[v];
		}
	}
}


void dfs_1(int u) {
	ok[u] = false;
	ans.push_back(u);
	int c = 0;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v] && hasK[v]) {
			dfs_1(v);
			++c;
		}
	}
	if (c > 0) ans.push_back(u);
}


int main() {
#ifdef DEBUG
	freopen("VOSTRAVL.in", "r", stdin);
	freopen("VOSTRAVL.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &s, &k);
	for (int i = 1; i <= n; ++i) p[i] = -1;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		x = getRoot(x);
		y = getRoot(y);
		if (x != y)
			p[x] = y;
	}

	filla(isK, false);
	isK[s] = true;
	for (int i = 0; i < k; ++i) {
		int x = read();
		isK[x] = true;
		if (getRoot(x) != getRoot(s)) {
			printf("NIE\n");
			return 0;
		}
	}

	printf("TAK\n");
	filla(ok, true);
	dfs_0(s);
	filla(ok, true);
	dfs_1(s);
	n = (int)ans.size();
	printf("%d ", n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);

	return 0;
}