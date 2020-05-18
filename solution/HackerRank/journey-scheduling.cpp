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


const int MAX_N = int(1e5)+5;


int n;
vector<int> e[MAX_N];
pii l[MAX_N], r[MAX_N];
int p[MAX_N], a[MAX_N];
int f[MAX_N], d[MAX_N], f2[MAX_N], d2[MAX_N];


void dfs_1(int u) {
	f[u] = u;
	d[u] = 0;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] == 0) {
			p[v] = u;
			dfs_1(v);
			if (d[v]+1 > d[u]) {
				d[u] = d[v]+1;
				f[u] = f[v];
			}
		}
	}
}


void dfs_2(int u) {
	int m = 0;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] == u)
			a[++m] = v;
	}
	l[0] = make_pair(0, 0);
	for (int i = 1; i <= m; ++i) {
		int v = a[i];
		l[i] = l[i-1];
		if (d[v]+1 > l[i-1].second) l[i] = make_pair(f[v], d[v]+1);
	}
	r[m+1] = make_pair(0, 0);
	for (int i = m; i >= 1; --i) {
		int v = a[i];
		r[i] = r[i+1];
		if (d[v]+1 > r[i+1].second) r[i] = make_pair(f[v], d[v]+1);
	}
	for (int i = 1; i <= m; ++i) {
		int v = a[i];
		d2[v] = d2[u], f2[v] = f2[u];
		if (l[i-1].second > d2[v])
			d2[v] = l[i-1].second, f2[v] = l[i-1].first;
		if (r[i+1].second > d2[v])
			d2[v] = r[i+1].second, f2[v] = r[i+1].first;
		++d2[v];
	}
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] == u)
			dfs_2(v);
	}

	if (d2[u] > d[u])
		d[u] = d2[u], f[u] = f2[u];
}


ll solve(int u, ll k) {
	ll ans = d[u];
	u = f[u];
	ans = ans + (k-1) * ll(d[u]);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("journey-scheduling.in", "r", stdin);
	freopen("journey-scheduling.out", "w", stdout);
#endif
	int nQ;
	scanf("%d%d", &n, &nQ);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	filla(p, 0);
	p[1] = -1;
	dfs_1(1);
	f2[1] = 1;
	d2[1] = 0;
	dfs_2(1);

	while (nQ--) {
		int x, k;
		scanf("%d%d", &x, &k);
		printf("%lld\n", solve(x, k));
	}
	return 0;
}