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

const int MAX_N = int(1e4)+4;

int n, p;
vector<pii> e[MAX_N];
bool ok[MAX_N];
ll a[MAX_N], b[MAX_N], d[MAX_N], f[MAX_N];
ll l[MAX_N], r[MAX_N], w[MAX_N];
int id[MAX_N], parent[MAX_N], sz[MAX_N];
ll value;


void dfs(int u) {
	ok[u] = false;
	f[u] = 0;
	sz[u] = (int)e[u].size();
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].second;
		if (ok[v]) {
			parent[v] = u;
			d[v] = d[u] + ll(e[u][i].first);
			dfs(v);
			f[u] = max(f[u], f[v] + ll(e[u][i].first));
		}
	}
}


void dfs_2(int u) {
	int c = 0;
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].second;
		if (parent[v] == u) {
			w[c] = e[u][i].first;
			a[v] = a[u] + w[c];
			id[c++] = v;
		}
	}
	if (c == 0) return;

	l[0] = f[id[0]] + w[0];
	for (int i = 1; i < c; ++i)
		l[i] = max(l[i-1], f[id[i]] + w[i]);
	r[c] = 0;
	for (int i = c-1; i >= 0; --i)
		r[i] = max(r[i+1], f[id[i]] + w[i]);

	for (int i = 0; i < c; ++i) {
		int v = id[i];
		if (i > 0) a[v] = max(a[v], l[i-1] + w[i]);
		a[v] = max(a[v], r[i+1] + w[i]);
	}

	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].second;
		if (parent[v] == u)
			dfs_2(v);
	}
}


void dfs_3(int u) {
	int c = 0;
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].second;
		if (parent[v] == u) {
			w[c] = ll(e[u][i].first) + d[u];
			b[v] = max(b[u], d[u]);
			id[c++] = v;
		}
	}
	if (c == 0) return;

	l[0] = f[id[0]] + w[0];
	for (int i = 1; i < c; ++i)
		l[i] = max(l[i-1], f[id[i]] + w[i]);
	r[c] = 0;
	for (int i = c-1; i >= 0; --i)
		r[i] = max(r[i+1], f[id[i]] + w[i]);

	for (int i = 0; i < c; ++i) {
		int v = id[i];
		if (i > 0) b[v] = max(b[v], l[i-1]);
		b[v] = max(b[v], r[i+1]);
	}

	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].second;
		if (parent[v] == u)
			dfs_3(v);
	}
}



int main() {
#ifdef DEBUG
	freopen("CAPITAL.in", "r", stdin);
	freopen("CAPITAL.out", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n-1; ++i) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		e[u].push_back(make_pair(x, v));
		e[v].push_back(make_pair(x, u));
	}

	fill(ok, true);
	parent[p] = -1;
	d[p] = 0;
	dfs(p);

	ll k = f[p], newK = k;
	a[p] = b[p] = 0;
	dfs_2(p);
	dfs_3(p);
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		ll tmp = max(b[i], f[i]);
		if (tmp < newK) {
			newK = tmp;
			ans = i;
		}
	}

	printf("%lld\n", k-newK);
	cout << "ans = " << ans << endl;
	cout << k << " " << newK << endl;
	return 0;
}