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


const int MAX_N = int(1e3) + 30;
const int oo = int(1e9);


int n;
int nChild[MAX_N], p[MAX_N], f[MAX_N];
vector<int> e[MAX_N];


int dfs(int u) {
	nChild[u] = 1;
	int x = -1, y = -1;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != 0) continue;
		p[v] = u;
		dfs(v);
		nChild[u] += nChild[v];
		if (x == -1 || f[v] > f[x]) {
			y = x;
			x = v;
		}
		else if (y == -1 || f[v] > f[y])
			y = v;
	}
	if (y == -1) return f[u] = 1;	// no child or 1 direct child
	return f[u] = 1 + f[x] + f[y];
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-practice.in", "r", stdin);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		n = read();
		for (int i = 0; i <= n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = oo;
		for (int i = 1; i <= n; ++i) {
			filla(p, 0);
			p[i] = -1;
			int t = dfs(i);
			// cout << "		" << i <<  " " << t << endl;
			ans = min(ans, n-t);
		}
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}