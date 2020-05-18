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

const int MAX_N = int(1e5)+5;
const int MAX_SAM = 2*MAX_N;
const ll MODULE = ll(1e9)+9;


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
int a[MAX_N], id[MAX_SAM], c[MAX_N];
State sam[MAX_SAM];
ll f[MAX_SAM];


void sam_init() {
	nSAM = 1;
	last = 0;
	sam[0] = State();
}


void sam_extend(int x) {
	int cur = nSAM++;
	sam[cur] = State();
	sam[cur].len = sam[last].len + 1;

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
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("MOU1H.in", "r", stdin);
	freopen("MOU1H.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0, pre = 0; i < n; ++i) {
			int x = read();
			if (i) a[i-1] = x-pre;
			pre = x;
		}

		--n;
		sam_init();
		for (int i = 0; i < n; ++i)
			sam_extend(a[i]);

		// topo sort (by len)
		for (int i = 0; i <= n; ++i) c[i] = 0;
		for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
		for (int i = 1; i <= n; ++i) c[i] += c[i-1];
		for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

		// calculate
		for (int i = nSAM-1; i >= 0; --i) {
			int u = id[i];
			f[u] = 1;
			tr(sam[u].nexts, it)
				f[u] = (f[u] + f[it->second])%MODULE;
		}
		printf("%lld\n", (f[0]-1+MODULE)%MODULE);
	}
	return 0;
}