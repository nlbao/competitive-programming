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


const int MAX_N = 2*int(1e5) + 4;
const int MAX_SAM = 2 * MAX_N;
const int MAX_CHAR = 30;


struct State {
	int len, link, id;
	int nexts[MAX_CHAR];

	State() {
		id = -1;
		len = 0;
		link = -1;
		fill(nexts, 0);
	}

	void operator = (const State &other) {
		id = other.id;
		len = other.len;
		link = other.link;
		memcpy(nexts, other.nexts, sizeof(nexts));
	}

	bool hasNext(int x) {
		return nexts[x] > 0;
	}
};


int nSAM, last;
char s[MAX_N];
State sam[MAX_SAM];
int c[MAX_N], id[MAX_SAM];
ll g[MAX_SAM];
int mask[MAX_SAM];
// vector<int> e[MAX_SAM];


void sam_init() {
	nSAM = 1;
	last = 0;
	mask[0] = 0;
}


void sam_extend(int x, int id) {
	int cur = nSAM++;
	sam[cur].len = sam[last].len + 1;
	sam[cur].id = id;

	int p = last;
	for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
		sam[p].nexts[x] = cur;

	if (p == -1) sam[cur].link = 0;
	else {
		int q = sam[p].nexts[x];
		if (sam[q].len == sam[p].len + 1) sam[cur].link = q;
		else {
			int clone = nSAM++;
			sam[clone] = sam[q];
			sam[clone].len = sam[p].len + 1;
			mask[clone] = mask[q];
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	last = cur;
}


// void dfs(int u) {
// 	if (sam[u].id < 0) mask[u] = 0;
// 	else mask[u] = 1 << sam[u].id;
// 	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
// 		int v = e[u][i];
// 		dfs(v);
// 		mask[u] |= mask[v];
// 	}
// }


int main() {
#ifdef DEBUG
	freopen("TASTR.in", "r", stdin);
	freopen("TASTR.out", "w", stdout);
#endif
	sam_init();
	int special[2] = {'z'-'a'+1, 'z'-'a'+2};
	int m = 0;
	for (int t = 0; t < 2; ++t) {
		scanf("%s\n", s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			sam_extend(s[i] - 'a', t);
		sam_extend(special[t], -1);
		m += n+1;
	}

	for (int i = 0; i <= m; ++i) c[i] = 0;
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= m; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

	// for (int i = nSAM-1; i >= 1; --i) {
	// 	int u = id[i];
	// 	e[sam[u].link].push_back(u);
	// }
	// dfs(0);
	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i];
		mask[u] = 0;
		for (int x = 0; x < 26; ++x) {
			if (!sam[u].hasNext(x)) continue;
			mask[u] |= mask[sam[u].nexts[x]];
		}
		for (int k = 0; k < 2; ++k)
			if (sam[u].hasNext(special[k]))
				mask[u] |= (1<<k);
	}

	ll ans = 0;
	fill(g, 0);
	g[0] = 1;
	for (int i = 0; i < nSAM; ++i) {
		int u = id[i];
		for (int x = 0; x < 26; ++x) {
			if (!sam[u].hasNext(x)) continue;
			g[sam[u].nexts[x]] += g[u];
		}
		if (u > 0 && mask[u] > 0 && mask[u] < 3)
			ans += g[u];
	}
	printf("%lld\n", ans);
	return 0;
}