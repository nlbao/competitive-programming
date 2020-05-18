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

const int MAX_N = 150005;
const int MAX_M = 300005;

int n, m, nCnt, nC, top;
vector<int> e[MAX_N], e2[MAX_N];
int num[MAX_N], low[MAX_N], stack[MAX_N], state[MAX_N];
int a[MAX_N], b[MAX_N], nChild[MAX_N], id[MAX_N];
queue<int> q;


void dfs(int u) {
	state[u] = 1;
	num[u] = low[u] = ++nCnt;
	stack[++top] = u;
	for_each(it, e[u]) {
		int v = *it;
		if (state[v] > 1) continue;
		if (state[v] == 0) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		++nC;
		int v = -1;
		while (v != u) {
			v = stack[top--];
			id[v] = nC;
			state[v] = 2;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("TPCPPLAR.in", "r", stdin);
	freopen("TPCPPLAR.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	filla(a, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		++a[y];
	}

	nC = nCnt = top = 0;
	filla(state, 0);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 0)
			dfs(i);

	filla(a, 0);
	filla(b, 0);
	filla(nChild, 0);
	for (int u = 1; u <= n; ++u) {
		++nChild[id[u]];
		for_each(it, e[u]) {
			int v = *it;
			if (id[v] != id[u]) {
				++a[id[v]];	// in
				++b[id[u]];	// out
				e2[id[u]].push_back(id[v]);
			}
		}
	}

	// topo sort
	m = 0;
	for (int i = 1; i <= nC; ++i)
		if (a[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int u = q.front();	q.pop();
		num[++m] = u;
		for_each(it, e2[u]) {
			int v = *it;
			--a[v];
			if (a[v] == 0) q.push(v);
		}
	}
	for (int u = 1; u <= nC; ++u)
		for_each(it, e2[u])
			++a[*it];

	// solve
	int ans = 0, nZeroIn = 0, nZeroOut = 0;
	for (int i = 1; i <= nC; ++i) {
		if (a[i] == 0) ++nZeroIn;
		state[i] = 0;
		e[i].clear();
	}
	for (int i = 1; i <= nC; ++i) {
		int u = num[i];
		if (a[u] == 0)
			--nZeroIn;
		for_each(it, e[u]) {
			int v = *it;
			++b[v];
			if (b[v] == 1) --nZeroOut;
		}

		if (nZeroIn == 0 && nZeroOut == 0) {
			ans += nChild[u];
			state[u] = 1;
		}

		if (b[u] == 0) ++nZeroOut;
		for_each(it, e2[u]) {
			int v = *it;
			--a[v];
			--b[u];
			if (a[v] == 0) ++nZeroIn;
			if (b[u] == 0) ++nZeroOut;
			e[v].push_back(u);
		}
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		if (state[id[i]] == 1)
			printf("%d ", i);

	return 0;
}