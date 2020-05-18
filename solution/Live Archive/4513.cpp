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

const int MAX_N = 4*int(1e4) + 4;
const int MAX_SAM = 2 * MAX_N;


struct State {
	int len, link, firstPos;
	map<int, int> nexts;

	State() {
		len = 0;
		link = -1;
		nexts.clear();
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		firstPos = other.firstPos;
		nexts = other.nexts;
	}

	bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};


int nSAM, last = 0;
char s[MAX_N];
State sam[MAX_SAM];
int c[MAX_N], id[MAX_SAM], f[MAX_SAM];


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
	sam[cur].firstPos = sam[cur].len - 1;
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
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("4513.in", "r", stdin);
	freopen("4513.out", "w", stdout);
#endif
	while (1) {
		int m = read();
		if (m < 1) break;

		scanf("%s\n", s);
		int n = strlen(s);
		sam_init();
		for (int i = n-1; i >= 0; --i)
			sam_extend(s[i]-'a');

		// topo sort (by len)
		for (int i = 0; i <= n; ++i) c[i] = 0;
		for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
		for (int i = 1; i <= n; ++i) c[i] += c[i-1];
		for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

		// find longest substrings which repeats m times
		int maxLen = 0, pos = n+1;
		for (int i = nSAM-1; i >= 0; --i) {
			int u = id[i];
			f[sam[u].link] += f[u];
			if (f[u] >= m) {
				if (sam[u].len > maxLen ||
					(sam[u].len == maxLen && sam[u].firstPos < pos))
				{
					maxLen = sam[u].len;
					pos = sam[u].firstPos;
				}
			}
		}

		if (maxLen < 1) printf("none\n");
		else printf("%d %d\n", maxLen, n-1 - pos);
	}
	return 0;
}