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

const int MAX_N = int(1e4)+4;
const int MAX_IT = 4*MAX_N;
const int oo = int(1e9);

int n, nColor, nPos;
char s[20];
vector<pii> e[MAX_N];
int c[MAX_N], cost[MAX_N], h[MAX_N], par[MAX_N], color[MAX_N];
int first[MAX_N], last[MAX_N], pos[MAX_N], invPos[MAX_N];
int vID[MAX_N], eID[MAX_N];
bool ok[MAX_N];
int f[MAX_IT], posL, posR, value;


void dfs(int u) {
	ok[u] = false;
	c[u] = 1;
	for_each(it, e[u]) {
		int v = it->second;
		if (!ok[v]) continue;
		par[v] = u;
		eID[v] = it->first;
		vID[it->first] = v;
		h[v] = h[u] + 1;
		dfs(v);
		c[u] += c[v];
	}
}


void HLD(int u) {
	ok[u] = false;
	color[u] = nColor;
	last[nColor] = u;
	pos[u] = ++nPos;
	invPos[nPos] = u;

	int id = -1;
	for_each(it, e[u]) {
		int v = it->second;
		if (ok[v] && (id == -1 || c[v] > c[id]))
			id = v;
	}

	if (id != -1) HLD(id);
	for_each(it, e[u]) {
		int v = it->second;
		if (!ok[v]) continue;
		first[++nColor] = v;
		HLD(v);
	}
}


void buildTree(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		f[k] = cost[eID[invPos[l]]];
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	buildTree(left, l, mid);
	buildTree(right, mid+1, r);
	f[k] = max(f[left], f[right]);
}


void update(int k, int l, int r) {
	if (l > r || l > posL || r < posL) return;
	if (l == r) {
		f[k] = value;
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid);
	update(right, mid+1, r);
	f[k] = max(f[left], f[right]);
}


int get(int k, int l, int r) {
	if (l > r || posL > posR || l > posR || r < posL) return -oo;
	if (posL <= l && r <= posR)
		return f[k];
	int mid = (l+r)>>1;
	return max(get(k<<1, l, mid), get((k<<1)+1, mid+1, r));
}


int maxQuery(int u, int v) {
	int ans = -oo;
	while (color[u] != color[v]) {
		if (h[par[first[color[u]]]] < h[par[first[color[v]]]]) swap(u, v);
		posL = pos[first[color[u]]], posR = pos[u];
		ans = max(ans, get(1, 1, n));
		u = par[first[color[u]]];
	}
	if (u != v) {
		if (h[u] < h[v]) swap(u, v);
		posL = pos[v]+1, posR = pos[u];
		ans = max(ans, get(1, 1, n));
	}
	if (ans == -oo) ans = 0;
	return ans;
}


void changeQuery(int i, int newValue) {
	int u = vID[i];
	posL = pos[u], value = newValue;
	update(1, 1, n);
}


int main() {
#ifdef DEBUG
	freopen("QTREE.in", "r", stdin);
	freopen("QTREE.out", "w", stdout);
#endif
	int nTest = read();
	while(nTest--) {
		scanf("%d\n", &n);
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			ok[i] = true;
		}
		for (int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d%d\n", &a, &b, &cost[i]);
			e[a].push_back(make_pair(i, b));
			e[b].push_back(make_pair(i, a));
		}

		h[1] = 1;
		eID[1] = cost[0] = 0;
		dfs(1);
		for (int i = 1; i <= n; ++i) ok[i] = true;
		nColor = 1;
		nPos = 0;
		first[1] = 1;
		HLD(1);
		for (int i = 0; i <= 4*n; ++i) f[i] = 0;
		buildTree(1, 1, n);

		int a, b;
		while (true) {
			scanf("%s", s);
			if (s[0] == 'Q') {
				scanf("%d%d\n", &a, &b);
				printf("%d\n", maxQuery(a, b));
			}
			else if (s[0] == 'C') {
				scanf("%d%d\n", &a, &b);
				changeQuery(a, b);
			}
			else break;
		}
		printf("\n");
	}
	return 0;
}