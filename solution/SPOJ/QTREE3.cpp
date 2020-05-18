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
const int MAX_M = MAX_N;
const int MAX_TREE = 4*MAX_M;
const bool WHITE_COLOR = true;

int n, m, nQuery, pos, startPos, finishPos;
int start[MAX_N], finishIndex[MAX_M], vertex[MAX_M];
int tree[MAX_TREE];
vector<int> e[MAX_N];
bool ok[MAX_N], color[MAX_M];


void dfs(int u) {
	ok[u] = false;
	start[u] = ++m;
	vertex[m] = u;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v])
			dfs(v);
	}
	finishIndex[start[u]] = m;
}


void build(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		color[l] = WHITE_COLOR;
		tree[k] = -1;
		return;
	}
	int mid = (l+r)>>1;
	int leftK = k<<1, rightK = leftK + 1;
	build(leftK, l, mid);
	build(rightK, mid+1, r);
}


void update(int k, int l, int r) {
	if (l > pos || r < pos) return;
	if (l == r) {
		color[l] = !color[l];
		if (color[l] == WHITE_COLOR)
			tree[k] = -1;
		else
			tree[k] = finishIndex[l];
		return;
	}
	int mid = (l+r)>>1;
	int leftK = k<<1, rightK = leftK + 1;
	update(leftK, l, mid);
	update(rightK, mid+1, r);
	tree[k] = max(tree[leftK], tree[rightK]);
}


int get(int k, int l, int r) {
	if (l > startPos) return -1;
	if (l == r)
		return finishIndex[l] >= finishPos ? vertex[l] : -1;
	int mid = (l+r)>>1;
	int leftK = k<<1, rightK = leftK + 1;
	if (tree[leftK] >= finishPos)
		return get(leftK, l, mid);
	if (tree[rightK] >= finishPos)
		return get(rightK, mid+1, r);
	return -1;
}



int main() {
#ifdef DEBUG
	freopen("QTREE3.in", "r", stdin);
	freopen("QTREE3.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQuery);
	for (int i = 1; i <= n; ++i) e[i].clear();
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	m = 0;
	fill(ok, true);
	dfs(1);
	build(1, 1, m);

	for (int id = 0; id < nQuery; ++id) {
		int qType, u;
		scanf("%d%d", &qType, &u);
		if (qType == 0) {
			pos = start[u];
			update(1, 1, m);
		}
		else {
			startPos = start[u];
			finishPos = finishIndex[startPos];
			printf("%d\n", get(1, 1, m));
		}
	}
	return 0;
}