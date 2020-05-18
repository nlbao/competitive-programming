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


const int MAX_N = 111;

int n;
bool ok[MAX_N];
int a[MAX_N], b[MAX_N];

bool edge(int x, int y) {
	return (a[y] < a[x] && a[x] < b[y]) || (a[y] < b[x] && b[x] < b[y]);
}

void dfs(int u) {
	ok[u] = false;
	for (int i = 1; i <= n; ++i)
		if (ok[i] && edge(u, i))
			dfs(i);
}


int main() {
#ifdef DEBUG
	freopen("320B.in", "r", stdin);
	freopen("320B.out", "w", stdout);
#endif
	int m = read();
	n = 0;
	for (int qid = 0; qid < m; ++qid) {
		int qtype, x, y;
		scanf("%d%d%d", &qtype, &x, &y);
		if (qtype == 1) {
			a[++n] = x;
			b[n] = y;
		}
		else {
			fill(ok, true);
			dfs(x);
			if (ok[y]) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}