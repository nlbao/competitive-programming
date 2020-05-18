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
const int oo = int(1e9);

int n, m;
vector<int> e[MAX_N][2];
int d[MAX_N];
queue<int> q;
bool inQ[MAX_N];


int main() {
#ifdef DEBUG
	freopen("REVERSE.in", "r", stdin);
	freopen("REVERSE.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) continue;
		e[x][0].push_back(y);
		e[y][1].push_back(x);
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = oo;
		inQ[i] = false;
	}
	d[1] = 0;
	q.push(1);
	inQ[1] = true;

	while (!q.empty()) {
		int u = q.front();	q.pop();
		inQ[u] = false;
		for (int k = 0; k < 2; ++k)
			for (int i = 0, sz = (int)e[u][k].size(); i < sz; ++i) {
				int v = e[u][k][i];
				int t = d[u] + k;
				if (t < d[v]) {
					d[v] = t;
					if (!inQ[v]) {
						inQ[v] = true;
						q.push(v);
					}
				}
			}
	}
	if (d[n] >= oo) d[n] = -1;
	printf("%d\n", d[n]);
	return 0;
}