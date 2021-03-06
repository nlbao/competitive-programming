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


const int MAX_N = int(1e5) + 4;
const int MAX_SAM = 2 * MAX_N;
const int MAX_CHAR = 27;


struct State {
	int len, link;
	int nexts[MAX_CHAR];

	State() {
		len = 0;
		link = -1;
		fill(nexts, 0);
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		memcpy(nexts, other.nexts, sizeof(nexts));
	}

	bool hasNext(int x) {
		return nexts[x] > 0;
	}
};


int nSAM, last = 0, L, H;
char s[MAX_N];
State sam[MAX_SAM];
int c[MAX_N], id[MAX_SAM];
ll f[MAX_SAM];


void sam_init() {
	nSAM = 1;
	last = 0;
	sam[0] = State();
	f[0] = 0;
}


void sam_extend(int x) {
	int cur = nSAM++;
	sam[cur] = State();
	sam[cur].len = sam[last].len + 1;
	f[cur] = 1;

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
			f[clone] = 0;
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	last = cur;
}


inline bool isIntersect(int x, int y) {
	if (x > H || y < L) return false;
	return true;
}


inline int maxIntersectPoint(int x, int y) {
	return min(H, y);
}


int main() {
#ifdef DEBUG
	freopen("REPSTR.in", "r", stdin);
	freopen("REPSTR.out", "w", stdout);
#endif
	while (1) {
		scanf("%d%d\n", &L, &H);
		if (L == 0) break;
		scanf("%s\n", s);
		int n = strlen(s);
		sam_init();
		for (int i = 0; i < n; ++i)
			sam_extend(s[i] - 'a');

		for (int i = 0; i <= n; ++i) c[i] = 0;
		for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
		for (int i = 1; i <= n; ++i) c[i] += c[i-1];
		for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

		ll maxF = 0;
		int maxLen;
		for (int i = nSAM-1; i >= 0; --i) {
			int u = id[i];
			int v = sam[u].link;
			f[v] += f[u];
			int l = sam[v].len+1, r = sam[u].len;
			if (isIntersect(l, r)) {
				if (f[u] > maxF) {
					maxF = f[u];
					maxLen = maxIntersectPoint(l, r);
				}
				else if (f[u] == maxF)
					maxLen = max(maxLen, maxIntersectPoint(l, r));
			}
		}
		printf("%lld %d\n", maxF, maxLen);
	}
	return 0;
}