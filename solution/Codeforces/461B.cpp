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
const ll MODULE = ll(1e9) + 7;


int n;
vector<int> e[MAX_N];
int sz[MAX_N], parent[MAX_N], id[MAX_N];
bool ok[MAX_N], isBlack[MAX_N];
ll f[MAX_N], g[MAX_N], l[MAX_N], r[MAX_N];



inline ll mmod(ll x) {
	return x%MODULE;
}


void dfs(int u) {
	ok[u] = false;
	f[u] = g[u] = 0;
	int c = 0;
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			++c;
			parent[v] = u;
			dfs(v);
		}
	}

	if (c == 0) {
		if (isBlack[u]) g[u] = 1;
		else f[u] = 1;
		return;
	}

	c = 0;
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i];
		if (parent[v] == u)
			id[c++] = v;
	}

	l[0] = mmod(f[id[0]] + g[id[0]]);
	for (int i = 1; i < c; ++i) {
		l[i] = mmod(f[id[i]] + g[id[i]]);
		l[i] = mmod(l[i-1] * l[i]);
	}
	r[c] = 1;
	for (int i = c-1; i >= 0; --i) {
		r[i] = mmod(f[id[i]] + g[id[i]]);
		r[i] = mmod(r[i+1] * r[i]);
	}

	if (isBlack[u]) {
		g[u] = r[0];
	}
	else {
		f[u] = r[0];
		g[u] = mmod(g[id[0]] * r[1]);
		if (c > 1)
			g[u] = mmod(g[u] + mmod(g[id[c-1]] * l[c-2]));
		for (int i = 1; i < c-1; ++i)
			g[u] = mmod(g[u] + mmod(g[id[i]] * mmod(l[i-1] * r[i+1])));
	}
}


int main() {
#ifdef DEBUG
	freopen("461B.in", "r", stdin);
	freopen("461B.out", "w", stdout);
#endif
	n = read();
	for (int i = 2; i <= n; ++i) {
		int x = read() + 1;
		e[x].push_back(i);
		e[i].push_back(x);
	}

	for (int i = 1; i <= n; ++i) {
		ok[i] = true;
		sz[i] = (int)e[i].size();
		int x = read();
		isBlack[i] = (x > 0);
	}

	dfs(1);
	cout << g[1];
	return 0;
}