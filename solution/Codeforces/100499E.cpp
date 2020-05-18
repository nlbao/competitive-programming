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

const int MAX_N = int(1e5)+5;


int n, ans;
int leftC[MAX_N], rightC[MAX_N], par[MAX_N];
int value[MAX_N], minV[MAX_N], maxV[MAX_N], f[MAX_N];
bool ok[MAX_N];


int remove(int u) {
	if (u == 0 || !ok[u]) return 0;
	ok[u] = false;
	return 1 + remove(leftC[u]) + remove(rightC[u]);
}


void dfs(int u) {
	if (u == 0) return;
	dfs(leftC[u]);
	dfs(rightC[u]);

	minV[u] = maxV[u] = u;
	f[u] = 1;

	int v = leftC[u];
	if (v != 0) {
		f[u] += f[v];
		int x = minV[v];
		while (x != u && value[x] >= value[u]) {
			f[u] -= remove(x);
			x = par[x];
		}
		minV[u] = x;

		x = maxV[v];
		while (x != u && value[x] >= value[u]) {
			f[u] -= remove(x);
			x = par[x];
		}
	}

	v = rightC[u];
	if (v != 0) {
		f[u] += f[v];
		int x = minV[v];
		while (x != u && value[x] <= value[u]) {
			f[u] -= remove(x);
			x = par[x];
		}

		x = maxV[v];
		while (x != u && value[x] <= value[u]) {
			f[u] -= remove(x);
			x = par[x];
		}
		maxV[u] = x;
	}

	ans = max(ans, f[u]);
}


int main() {
#ifdef DEBUG
	freopen("100499E.in", "r", stdin);
	freopen("100499E.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		par[1] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &leftC[i], &rightC[i], &value[i]);
			par[leftC[i]] = par[rightC[i]] = i;
		}
		ans = 0;
		filla(ok, true);
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}