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

const int MAX_N = 2*int(1e3) + 3;
const int MAX_M = MAX_N*MAX_N;

int n, m;
int value[MAX_N][MAX_N], p[MAX_N];
pair<int, pii> a[MAX_M];
vector<pii> e[MAX_N];
bool ok[MAX_N];
ll d[MAX_N];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


void dfs(int u) {
	ok[u] = false;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i].second;
		if (ok[v]) {
			d[v] = d[u] + ll(e[u][i].first);
			dfs(v);
		}
	}
}


bool solve() {
	for (int i = 1; i <= n; ++i) p[i] = -1;
	for (int i = 0; i < m; ++i) {
		int x = a[i].second.first, y = a[i].second.second;
		ll w = a[i].first;
		if (x == y && w != 0) return false;
		if (x != y && w == 0) return false;
		int px = getRoot(x), py = getRoot(y);
		if (px != py) {
			e[x].push_back(make_pair(w, y));
			e[y].push_back(make_pair(w, x));
			if (p[px] < p[py]) swap(px, py);
			p[px] = py;
		}
	}

	for (int u = 1; u <= n; ++u) {
		filla(ok, true);
		d[u] = 0;
		dfs(u);
		for (int v = 1; v <= n; ++v) {
			// cout << u << " " << v << ": " << d[v] << " " << value[u][v] << endl;
			if (d[v] != value[u][v])
				return false;
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("472D.in", "r", stdin);
	freopen("472D.out", "w", stdout);
#endif
	m = 0;
	n = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int x = read();
			a[m++] = make_pair(x, make_pair(i, j));
			value[i][j] = x;
		}

	sort(a, a+m);

	if (solve()) printf("YES");
	else printf("NO");
	return 0;
}