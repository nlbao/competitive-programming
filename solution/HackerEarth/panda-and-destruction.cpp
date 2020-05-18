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


const int MAX_N = 1e5 + 5;


int n, m;
int d[MAX_N];
vector<int> e[MAX_N];


class cmp {
public:
	bool operator() (const pii& a, const pii& b) const {
		// max d, min index
		if (a.second != b.second)
			return a.second < b.second;
		return a.first > b.first;
	}
};
priority_queue<pii, vector<pii>, cmp> heap;



int main() {
#ifdef DEBUG
	freopen("panda-and-destruction.in", "r", stdin);
	freopen("panda-and-destruction.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	filla(d, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		++d[x], ++d[y];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		heap.push(make_pair(i, d[i]));
	while (true) {
		int u = heap.top().first, t = heap.top().second;
		heap.pop();
		if (t != d[u]) continue;
		if (t == 0) break;
		++ans;
		d[u] = 0;
		foreach(it, e[u]) {
			int v = *it;
			if (d[v] == 0) continue;
			--d[v];
			heap.push(make_pair(v, d[v]));
		}
	}
	printf("%d\n", ans);
	return 0;
}