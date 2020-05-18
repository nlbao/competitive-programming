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

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;
const int oo = int(1e8)+8;

int sum, res;
bool ok[MAX_N];
int a[MAX_N], f[MAX_N];
vector<int> e[MAX_N];

void dfs(int u) {
	ok[u] = false;
	f[u] = a[u];
	for (int i = 0, sz = e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			dfs(v);
			f[u] += f[v];
			res = min(res, abs(sum - 2*f[v]));
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("cut-the-tree.in", "r", stdin);
	freopen("cut-the-tree.out", "w", stdout);
#endif
	int n = read();
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	res = oo;
	fill(ok, true);
	dfs(1);
	printf("%d\n", res);
	return 0;
}