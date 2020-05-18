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

const int MAX_N = 20004;

int n;
ll res;
vector<int> e[MAX_N];
bool ok[MAX_N];


int dfs(int u) {
	ok[u] = false;
	ll c = 0, sum = 0;
	for (int i = 0, sz = e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			ll t = dfs(v);
			sum += t*c;
			c += t;
		}
	}
	sum += c*ll(n-c-1);
	res = max(res, sum);
	return c+1;
}


int main() {
#ifdef DEBUG
	freopen("6436.in", "r", stdin);
	freopen("6436.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		n = read();
		for (int i = 0; i < n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		fill(ok, true);
		res = 0;
		dfs(0);
		printf("Case #%d: %d\n", test_id+1, res);
	}
	return 0;
}