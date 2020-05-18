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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5) + 5;
const int MAX_P = 2*int(1e6) + 6;

int n, nQ, root, nP = 0;
vector<int> list[MAX_P];
vector<int> e[MAX_N], divisors[MAX_N];
int ans[MAX_N], d[MAX_N], parent[MAX_N], sz[MAX_N], a[MAX_N];
int p[MAX_P];
bool ok[MAX_P];


int gcd(int x, int y) {
	if (x == 0 || y == 0) return x+y;
	return gcd(y, x%y);
}


void dfs(int u) {
	ok[u] = false;
	sz[u] = (int)e[u].size();
	ans[u] = -1;

	if (root == -1 || root == u) {
		ll t = a[u];
		divisors[u].clear();
		for (int i = 0; i < nP; ++i) {
			ll x = p[i];
			if (x*x > t) break;
			if (t%x == 0) {
				divisors[u].push_back(x);
				while (t%x == 0) t /= x;
			}
		}
		if (t > 1) divisors[u].push_back(t);
	}

	int m = (int)divisors[u].size();
	for (int i = 0; i < m; ++i) {
		int x = divisors[u][i];
		if (list[x].size() > 0) {
			int v = list[x][(int)list[x].size()-1];
			if (ans[u] == -1 || d[v] > d[ans[u]])
				ans[u] = v;
		}
		list[x].push_back(u);
	}

	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			parent[v] = u;
			d[v] = d[u]+1;
			dfs(v);
		}
	}

	for (int i = 0; i < m; ++i)
		list[divisors[u][i]].pop_back();
}


int main() {
#ifdef DEBUG
	freopen("463E.in", "r", stdin);
	freopen("463E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	nP = 0;
	fill(ok, true);
	for (ll i = 2; i < MAX_P; ++i) {
		if (!ok[i]) continue;
		p[nP++] = i;
		for (ll j = i*i; j < MAX_P; j += i)
			ok[j] = false;
	}

	fill(ok, true);
	parent[1] = d[1] = 0;
	root = -1;
	dfs(1);

	while (nQ--) {
		int t, v, w;
		scanf("%d%d", &t, &v);
		if (t == 1) {
			printf("%d\n", ans[v]);
		}
		else {
			scanf("%d", &w);
			root = v;
			a[v] = w;
			fill(ok, true);
			parent[1] = d[1] = 0;
			dfs(1);
		}
	}
	return 0;
}