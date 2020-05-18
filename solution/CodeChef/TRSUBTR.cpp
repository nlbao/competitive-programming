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

const int MAX_N = int(1e5)+5;
const ll BASE = 10007;

int n;
int a[MAX_N], e[MAX_N][2];
ll h[MAX_N], c[MAX_N], p[MAX_N];
bool ok[MAX_N];
set<ll> q;


void dfs(int u) {
	h[u] = a[u];
	c[u] = 1;
	for (int i = 0; i < 2; ++i) {
		int v = e[u][i];
		if (v == -1) {
			h[u] = h[u] * BASE;
			continue;
		}
		dfs(v);
		c[u] += c[v];
		h[u] = h[u] * p[c[v]] + h[v];
	}
}


void enter() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		e[i][0] = e[i][1] = -1;
		ok[i] = true;
	}
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		char ch;
		scanf("%d %d %c\n", &x, &y, &ch);
		e[x][(ch == 'M')] = y;
		ok[y] = false;
	}
}


int main() {
#ifdef DEBUG
	freopen("TRSUBTR.in", "r", stdin);
	freopen("TRSUBTR.out", "w", stdout);
#endif
	enter();
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;
	for (int i = 1; i <= n; ++i)
		if (ok[i]) dfs(i);
	for (int i = 1; i <= n; ++i)
		q.insert(h[i]);

	int nQ = read();
	while (nQ--) {
		enter();
		bool found = false;
		for (int i = 1; i <= n; ++i)
			if (ok[i]) {
				dfs(i);
				found = q.find(h[i]) != q.end();
			}
		if (found) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}