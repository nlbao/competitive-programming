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
const int MAX_K = int(200)+4;
const ll oo = ll(1e18);


int n, nTime, limit;
vector<int> e[MAX_N];
int w[MAX_N], start[MAX_N], finish[MAX_N], value[MAX_N];
ll s[MAX_N], f[MAX_K][MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	ok[u] = false;
	start[u] = ++nTime;
	finish[nTime] = nTime;
	value[nTime] = u;
	s[nTime] = w[u];
	for_each(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		dfs(v);
		s[start[u]] += s[start[v]];
		finish[start[u]] = finish[start[v]];
	}
}


int main() {
#ifdef DEBUG
	freopen("tree-pruning.in", "r", stdin);
	freopen("tree-pruning.out", "w", stdout);
#endif
	scanf("%d%d", &n, &limit);
	for (int i = 1; i <= n; ++i)
		w[i] = read();
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	nTime = 0;
	filla(ok, true);
	dfs(1);

	for (int i = 0; i <= limit; ++i)
		f[i][n+1] = -oo;
	f[0][n+1] = 0;
	for (int i = n; i >= 1; --i) {
		int j = finish[i];
		f[0][i] = s[i] + f[0][j+1];
		for (int k = 1; k <= limit; ++k) {
			f[k][i] = max(-oo, ll(w[value[i]]) + f[k][i+1]);
			f[k][i] = max(f[k][i], f[k-1][j+1]);
		}
	}

	ll ans = f[0][1];
	for (int i = 1; i <= limit; ++i)
		ans = max(ans, f[i][1]);
	cout << ans;
	return 0;
}