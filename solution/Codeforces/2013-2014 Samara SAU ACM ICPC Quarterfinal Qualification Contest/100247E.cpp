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


const int MAX_N = 2*int(1e5) + 5;

int n;
int color[MAX_N], nChild[MAX_N], par[MAX_N];
bool isAns[MAX_N], visited[MAX_N], ok[MAX_N];
char s[MAX_N];
vector<int> e[MAX_N];


void dfs_0(int u) {
	nChild[u] = 1;
	for_each(it, e[u]) {
		int v = *it;
		if (color[v] == 0)
			color[v] = color[u];
		par[v] = u;
		dfs_0(v);
		nChild[u] += nChild[v];
	}
}


void dfs_1(int u) {
	visited[u] = true;
	for_each(it, e[u]) {
		int v = *it;
		if (!ok[v] || visited[v])
			continue;
		dfs_1(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("100247E.in", "r", stdin);
	freopen("100247E.out", "w", stdout);
#endif
	int n = readln();
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '+') color[i+1] = 2;
		else if (s[i] == '-') color[i+1] = 1;
		else color[i+1] = 0;
	}

	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
	}

	if (color[1] == 0)
		color[1] = 1;
	par[1] = -1;
	dfs_0(1);

	filla(ok, true);
	for (int u = 1; u <= n; ++u)
		if (nChild[u] == 1 && color[u] == 1) {
			ok[u] = false;
			int v = par[u];
			while (v > 0 && ok[v]) {
				ok[v] = false;
				v = par[v];
			}
		}

	int nAns = 0;
	filla(isAns, false);
	filla(visited, false);
	for (int u = 1; u <= n; ++u)
		if (ok[u] && !visited[u] && (par[u] < 1 || !ok[par[u]])) {
			isAns[u] = true;
			++nAns;
			dfs_1(u);
		}

	printf("%d\n", nAns);
	for (int i = 1; i <= n; ++i)
		if (isAns[i])
			printf("%d ", i);
	return 0;
}