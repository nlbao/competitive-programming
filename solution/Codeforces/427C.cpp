#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = int(1e5+5);
const int MAX_M = 3*int(1e5+5);
const ll oo = ll(1e9);
const ll MODULE = ll(1e9)+7;


int n, m, top, nNum;
ll resCost, resCount;
vecint e[MAX_N];
int status[MAX_N], cost[MAX_N];
int low[MAX_N], num[MAX_N], stack[MAX_N];


void dfs(int u) {
	stack[++top] = u;
	status[u] = 0;
	num[u] = low[u] = ++nNum;
	for (int i = 0, sz = e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (status[v] < 1) {
			if (status[v] == -1) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] < num[u]) return;

	ll minCost = oo, nMin = 0;
	while (top && num[stack[top]] >= low[u]) {
		int v = stack[top--];
		status[v] = 1;
		if (cost[v] == minCost) ++nMin;
		else if (cost[v] < minCost) {
			minCost = cost[v];
			nMin = 1;
		}
	}

	resCost += minCost;
	resCount = (resCount*nMin)%MODULE;
}



int main() {
#ifdef DEBUG
	freopen("427C.in", "r", stdin);
	freopen("427C.out", "w", stdout);
#endif
	read(n);
	for (int i = 0; i < n; ++i)
		cost[i] = read();
	read(m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		e[x].push_back(y);
	}

	top = nNum = 0;
	resCost = 0;
	resCount = 1;
	for (int i = 0; i < n; ++i) status[i] = -1;
	for (int i = 0; i < n; ++i)
		if (status[i] == -1) {
			top = 0;
			dfs(i);
		}
	cout << resCost << " " << resCount << endl;

	return 0;
}