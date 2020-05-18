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
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 2*int(1e4+4);

struct State {
	int len, link, firstPos;
	map<char, int> nexts;
};


int n, m, last, nA;
char s[MAX_N];
State a[2*MAX_N];


void suffixAutomatonInit() {
	nA = 1;		last = 0;
	a[0].link = -1;
	a[0].len = 0;
	a[0].firstPos = -1;
	a[0].nexts.clear();
}


void suffixAutomatonExtend(char ch, int pos) {
	int cur = nA++;
	a[cur].len = a[last].len + 1;
	a[cur].firstPos = a[cur].len - 1;
	a[cur].nexts.clear();

	int p = last;
	for (; p != -1 && a[p].nexts.count(ch) == 0; p = a[p].link)
		a[p].nexts[ch] = cur;

	if (p == -1)
		a[cur].link = 0;
	else {
		int q = a[p].nexts[ch];
		if (a[q].len == a[p].len + 1)
			a[cur].link = q;
		else {
			int clone = nA++;
			a[clone] = a[q];
			a[clone].len = a[p].len + 1;
			for (; p != -1 && a[p].nexts[ch] == q; p = a[p].link)
				a[p].nexts[ch] = clone;
			a[q].link = a[cur].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("BEADS.in", "r", stdin);
	freopen("BEADS.out", "w", stdout);
#endif
	int nTest;
	scanf("%d\n", &nTest);
	while (nTest--) {
		scanf("%s\n", s);
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			s[n+i] = s[i];

		suffixAutomatonInit();
		for (int i = 0; i < n+n; ++i)
			suffixAutomatonExtend(s[i], i);

		int p = 0;
		for (int i = 0; i < n; ++i)
			p = a[p].nexts.begin()->second;
		printf("%d\n", a[p].firstPos - n + 2);
	}
	return 0;
}