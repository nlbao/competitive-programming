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


const int MAX_N = 505;
const int MAX_W = int(1e5)+5;

int n, sumW;
int w[MAX_N];
bool mark[MAX_W];
int c[MAX_W];
vector<int> e[MAX_N];


void dfs(int u) {
	vector<int> tmp;
	for (int i = sumW-w[u]; i >= 0; --i)
		if (c[i] > 0) {
			int x = i+w[u];
			tmp.push_back(x);
			mark[x] = true;
			c[x] = 1;
			c[i] = 0;
		}

	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i)
		dfs(e[u][i]);

	for (int i = (int)tmp.size()-1; i >= 0; --i) {
		c[tmp[i] - w[u]] = 1;
		c[tmp[i]] = 0;
	}
}


int main() {
#ifdef DEBUG
	freopen("RRTREE2.in", "r", stdin);
	freopen("RRTREE2.out", "w", stdout);
#endif
	n = read();
	sumW = 0;
	for (int i = 1; i <= n; ++i) {
		w[i] = read();
		sumW += w[i];
	}

	for (int i = 2; i <= n; ++i)
		e[read()].push_back(i);

	fill(c, 0);
	fill(mark, false);
	mark[0] = true;
	c[0] = 1;
	dfs(1);

	for (int i = 1; i <= sumW; ++i)
		printf("%d", int(mark[i]));
	return 0;
}