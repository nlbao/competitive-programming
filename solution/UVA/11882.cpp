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


const int MAX_N = 33;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


struct Node {
	int len;
	char value[MAX_N];

	Node() {
		len = 0;
		filla(value, 0);
	}

	Node(const Node &other) {
		len = other.len;
		filla(value, 0);
		for (int i = 0; i < len; ++i)
			value[i] = other.value[i];
	}

	Node& operator = (const Node &other) {
		len = other.len;
		for (int i = 0; i < len; ++i)
			value[i] = other.value[i];
		return *this;
	}

	void push(char c) {
		value[len++] = c;
	}

	void push(const Node &other) {
		for (int i = other.len-1; i >= 0; --i)
			value[len++] = other.value[i];
	}

	void pop() {
		--len;
	}

	void sortValue() {
		sort(value, value + len);
	}

	bool operator < (const Node &other) const {
		if (len != other.len)
			return len < other.len;
		for (int i = 0; i < len; ++i)
			if (value[i] != other.value[i])
				return value[i] < other.value[i];
		return false;
	}

	void print() {
		for (int i = 0; i < len; ++i)
			printf("%c", value[i]);
	}
};


int n, m;
Node ans, now, tmp;
bool visited[MAX_N][MAX_N], ok[MAX_N][MAX_N];
pii q[MAX_N];
char a[MAX_N][MAX_N];


inline bool onBoard(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}


int getMax(int x, int y) {
	tmp = Node();
	// filla(visited, false);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			visited[i][j] = false;
	int l = 1, r = 1;
	q[1] = make_pair(x, y);
	visited[x][y] = true;

	while (l <= r) {
		x = q[l].first, y = q[l++].second;
		tmp.push(a[x][y]);
		for (int k = 0; k < 4; ++k) {
			int i = x+dx[k], j = y+dy[k];
			if (onBoard(i, j) && ok[i][j] && !visited[i][j] && isdigit(a[i][j])) {
				q[++r] = make_pair(i, j);
				visited[i][j] = true;
			}
		}
	}
	return r;
}


void dfs(int x, int y) {
	now.push(a[x][y]);
	ok[x][y] = false;
	if (ans < now)
		ans = now;

	for (int k = 0; k < 4; ++k) {
		int i = x+dx[k], j = y+dy[k];
		if (onBoard(i, j) && ok[i][j] && isdigit(a[i][j])) {
			int newLen = now.len + getMax(i, j);
			if (newLen < ans.len) continue;
			else if (newLen == ans.len) {
				Node newNode = now;
				tmp.sortValue();
				newNode.push(tmp);
				if (ans < newNode)
					dfs(i, j);
			}
			else dfs(i, j);
		}
	}

	now.pop();
	ok[x][y] = true;
}


int main() {
#ifdef DEBUG
	freopen("11882.in", "r", stdin);
	freopen("11882.out", "w", stdout);
#endif
	while(true) {
		scanf("%d%d\n", &n, &m);
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%s", a[i]);

		ans = Node();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ok[i][j] = true;
		// filla(ok, true);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (isdigit(a[i][j])) {
					now = Node();
					dfs(i, j);
				}
		ans.print();
		printf("\n");
	}
	return 0;
}