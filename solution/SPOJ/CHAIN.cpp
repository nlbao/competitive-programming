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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 5*int(1e4) + 4;

int p[MAX_N], d[MAX_N];

int getRoot(int u) {
	if (p[u] == u) return u;
	int v = p[u];
	p[u] = getRoot(p[u]);
	d[u] = (d[u] + d[v])%3;
	return p[u];
}


int main() {
#ifdef DEBUG
	freopen("CHAIN.in", "r", stdin);
	freopen("CHAIN.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
			d[i] = 0;
		}
		int ans = 0;
		while (m--) {
			int types, x, y;
			scanf("%d%d%d", &types, &x, &y);
			if (x > n || y > n) {
				++ans;
				continue;
			}
			--types;
			int rx = getRoot(x), ry = getRoot(y);
			if (rx == ry) ans += (d[x]-d[y]+3)%3 != types;
			else {
				p[rx] = ry;
				d[rx] = (types - d[x] + d[y] + 3) % 3;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}