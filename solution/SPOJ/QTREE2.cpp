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

int n, nColor, nPos;
char s[100];
vector<pii> e[MAX_N];
int c[MAX_N], d[MAX_N], h[MAX_N], par[MAX_N], color[MAX_N];
int firstNode[MAX_N], lastNode[MAX_N], pos[MAX_N], invPos[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	ok[u] = false;
	c[u] = 1;
	for_each(it, e[u]) {
		int v = it->second;
		if (!ok[v]) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		d[v] = d[u] + it->first;
		dfs(v);
		c[u] += c[v];
	}
}


void HLD(int u) {
	ok[u] = false;
	color[u] = nColor;
	lastNode[nColor] = u;
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
		firstNode[++nColor] = v;
		HLD(v);
	}
}


int lca(int u, int v) {
	while (color[u] != color[v]) {
		if (h[par[firstNode[color[u]]]] < h[par[firstNode[color[v]]]]) swap(u, v);
		u = par[firstNode[color[u]]];
	}
	return h[u] < h[v] ? u : v;
}


int distQuery(int u, int v) {
	int r = lca(u, v);
	return d[u] + d[v] - 2*d[r];
}


int kthQuery(int u, int v, int k) {
	int r = lca(u, v);
	int lenU = h[u]-h[r]+1, lenV = h[v] - h[r];
	if (k >= lenU) {
		k -= lenU;
		k = lenV - k + 1;
		u = v;
	}
	if (k < 1) return -1;
	while (k > 0) {
		lenU = pos[u] - pos[firstNode[color[u]]] + 1;
		if (lenU < k) {
			k -= lenU;
			u = par[firstNode[color[u]]];
		}
		else {
			u = invPos[pos[u] - k + 1];
			k = 0;
		}
	}
	return u;
}


int main() {
#ifdef DEBUG
	freopen("QTREE2.in", "r", stdin);
	freopen("QTREE2.out", "w", stdout);
#endif
	int nTest = read();
	while(nTest--) {
		scanf("%d\n", &n);
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			ok[i] = true;
		}
		for (int i = 1; i < n; ++i) {
			int a, b, c;
			scanf("%d%d%d\n", &a, &b, &c);
			e[a].push_back(make_pair(c, b));
			e[b].push_back(make_pair(c, a));
		}

		d[1] = 0;
		h[1] = 1;
		dfs(1);
		for (int i = 1; i <= n; ++i) ok[i] = true;
		nColor = 1;
		nPos = 0;
		firstNode[1] = 1;
		HLD(1);

		int a, b, k;
		while (true) {
			scanf("%s", s);
			if (s[0] == 'K') {
				scanf("%d%d%d\n", &a, &b, &k);
				printf("%d\n", kthQuery(a, b, k));
			}
			else if (s[0] == 'D' && s[1] == 'I') {
				scanf("%d%d\n", &a, &b);
				printf("%d\n", distQuery(a, b));
			}
			else break;
		}
		printf("\n");
	}
	return 0;
}