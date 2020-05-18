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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const int MAX_SAM = 2 * MAX_N;

struct State {
	int len, link;
	map<int, int> nexts;

	State() {
		len = 0;
		link = -1;
		nexts.clear();
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		nexts = other.nexts;
	}

	bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};


int nSAM, last = 0;
char s[MAX_N];
int id[MAX_SAM], c[MAX_SAM];
State sam[MAX_SAM];
ll f[MAX_SAM];

vector<int> e[MAX_N];
int d[MAX_N], pos[MAX_N];
bool ok[MAX_N];
queue<int> q;


void sam_init() {
	nSAM = 1;
	last = 0;
	sam[0] = State();
}


int sam_extend(int x, int last) {
	int cur = nSAM++;
	sam[cur] = State();
	sam[cur].len = sam[last].len + 1;
	f[cur] = 1;

	int p = last;
	for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
		sam[p].nexts[x] = cur;

	if (p == -1)
		sam[cur].link = 0;
	else {
		int q = sam[p].nexts[x];
		if (sam[q].len == sam[p].len + 1)
			sam[cur].link = q;
		else {
			int clone = nSAM++;
			sam[clone] = sam[q];
			sam[clone].len = sam[p].len + 1;
			f[clone] = 0;
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	return cur;
}


int main() {
#ifdef DEBUG
	freopen("DIFTRIP.in", "r", stdin);
	freopen("DIFTRIP.out", "w", stdout);
#endif
	int n = read();
	fill(d, 0);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		++d[x];	++d[y];
	}

	sam_init();
	fill(ok, true);
	pos[1] = sam_extend(d[1], 0);
	q.push(1);
	ok[1] = false;
	while (!q.empty()) {
		int u = q.front();	q.pop();
		for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
			int v = e[u][i];
			if (ok[v]) {
				ok[v] = false;
				q.push(v);
				pos[v] = sam_extend(d[v], pos[u]);
			}
		}
	}

	fill(c, 0);
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i];
		f[u] = 1;
		tr(sam[u].nexts, it)
			f[u] += f[it->second];
	}
	printf("%lld\n", f[0]-1);
	return 0;
}