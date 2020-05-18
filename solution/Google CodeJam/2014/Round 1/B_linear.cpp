#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e3) + 30;
const int oo = int(1e9);


class Node {
	int id;
	pair<int, int> children[4];

public:
	Node(int u = -1) {
		id = u;
		for (int i = 0; i < 4; ++i)
			children[i] = make_pair(0, -1);
	}

	Node operator = (const Node &other) {
		id = other.id;
		for (int i = 0; i < 4; ++i)
			children[i] = other.children[i];
		return *this;
	}

	int getValue() {
		if (children[1].first == 0)
			return 1;
		return 1 + children[0].first + children[1].first;
	}

	void add(int u, int f) {
		for (int i = 0; i < 3; ++i)
			if (children[i].second == u) {
				printf ("!!! Error!");
				return;
			}
		for (int i = 0; i < 3; ++i)
			if (f > children[i].first) {
				for (int k = 2; k > i; --k)
					children[k] = children[k-1];
				children[i] = make_pair(f, u);
				break;
			}
	}

	void remove(int u) {
		for (int i = 0; i < 3; ++i)
			if (children[i].second == u) {
				for (int k = i; k < 3; ++k)
					children[k] = children[k+1];
				break;
			}
	}

	void addChild(Node &node) {
		node.remove(id);
		add(node.id, node.getValue());
	}
};


int n, ans;
int p[MAX_N];
Node f[MAX_N];
vector<int> e[MAX_N];


void dfs_init(int u) {
	f[u] = Node(u);
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != 0) continue;
		p[v] = u;
		dfs_init(v);
		f[u].addChild(f[v]);
	}
}


void dfs_solve(int u) {
	Node tmpU, tmpP;
	int parent = p[u];
	if (parent != -1) {
		tmpU = f[u];
		tmpP = f[parent];
		f[u].addChild(f[parent]);
	}
	ans = max(ans, f[u].getValue());
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != u) continue;
		dfs_solve(v);
	}
	if (parent != -1) {
		f[u] = tmpU;
		f[parent] = tmpP;
	}
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-practice.in", "r", stdin);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		n = read();
		for (int i = 0; i <= n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}

		filla(p, 0);
		p[1] = -1;
		dfs_init(1);
		ans = f[1].getValue();
		dfs_solve(1);
		ans = n-ans;
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}