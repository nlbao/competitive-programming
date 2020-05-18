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

const int MAX_N = 5*int(1e4)+5;


int nX, nY, m;
vector<int> e[MAX_N];
int d[MAX_N], matchX[MAX_N], matchY[MAX_N], q[MAX_N];

bool bfs_matching() {
	int l = 0, r = -1;
	for (int i = 1; i <= nX; ++i)
		if (matchX[i]) d[i] = 0;
		else {
			d[i] = 1;
			q[++r] = i;
		}
	d[0] = 0;

	while (l <= r) {
		int u = q[l++];
		for_each(it, e[u]) {
			int v = matchY[*it];
			if (!d[v]) {
				d[v] = d[u]+1;
				if (!v) return true;
				q[++r] = v;
			}
		}
	}
	return false;
}


bool dfs_matching(int u) {
	if (u == 0) return true;
	for_each(it, e[u]) {
		int v = matchY[*it];
		if (d[v] == d[u]+1 && dfs_matching(v)) {
			matchX[u] = *it;
			matchY[*it] = u;
			return true;
		}
	}
	d[u] = 0;
	return false;
}


int main() {
#ifdef DEBUG
	freopen("22011.in", "r", stdin);
	freopen("22011.out", "w", stdout);
#endif
	scanf("%d%d%d", &nX, &nY, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
	}

	int ans = 0;
	filla(matchX, 0);
	filla(matchY, 0);
	while (bfs_matching())
		for (int i = 1; i <= nX; ++i)
			if (!matchX[i] && dfs_matching(i))
				++ans;
	printf("%d\n", ans);
	return 0;
}