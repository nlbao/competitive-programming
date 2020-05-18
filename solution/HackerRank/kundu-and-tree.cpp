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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;
const ll MODULE = int(1e9)+7;


int n;
int res;
vector<pair<int, int> > e[MAX_N];
bool ok[MAX_N];
int c[MAX_N];


ll mmod(ll x) {
	return x%MODULE;
}


void dfs(int u) {
	ok[u] = false;
	c[u] = 0;
	for (int i = 0, sz = e[u].size(); i < sz; ++i) {
		int v = e[u][i].second;
		if (!ok[v]) continue;
		dfs(v);
		if (!e[u][i].first)		// black edge
			c[u] += c[v] + 1;
		else {
			ll x = c[v] + 1;
			res = mmod(res + n-x-1);				// for v
			res = mmod(res + mmod((x-1)*(n-x)));	// for v's childrens
		}
	}

	cout << u << " " << res << endl;
}


int main() {
#ifdef DEBUG
	freopen("kundu-and-tree.in", "r", stdin);
	freopen("kundu-and-tree.out", "w", stdout);
#endif
	scanf("%d\n", &n);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		char c;
		scanf("%d%d %c\n", &x, &y, &c);
		int w = (c == 'r');
		e[x].push_back(make_pair(w, y));
		e[y].push_back(make_pair(w, x));
	}

	res = 0;
	fill(ok, true);
	dfs(1);
	printf("%d\n", res);
	return 0;
}