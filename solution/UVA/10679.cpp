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
State sam[MAX_SAM];


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
	freopen("10679.in", "r", stdin);
	freopen("10679.out", "w", stdout);
#endif
	int nTest;
	scanf("%d\n", &nTest);
	while (nTest--) {
		scanf("%s\n", s);

		int n = strlen(s);
		sam_init();
		for (int i = 0; i < n; ++i)
			sam_extend(s[i]-'a');

		int nQ;
		scanf("%d\n", &nQ);
		while (nQ--) {
			scanf("%s\n", &s);
			n = strlen(s);
			int u = 0;
			for (int i = 0; i < n; ++i) {
				int x = s[i]-'a';
				if (sam[u].hasNext(x))
					u = sam[u].nexts[x];
				else {
					u = -1;
					break;
				}
			}
			if (u == -1) printf("n\n");
			else printf("y\n");
		}
	}
	return 0;
}