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


const int MAX_N = int(1e5)+5;
const int MAX_CHAR = 27;


struct State {
	int len, link;
	int nexts[MAX_CHAR];

	State () {
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = -1;
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = other.nexts[i];
	}
};


int n, lenS, lenT, nSA, last;
char s[MAX_N], t[MAX_N];
State sa[2*MAX_N];


void sa_init() {
	nSA = 1;	last = 0;
	sa[0].len = 0;
	sa[0].link = -1;
}


void sa_extend(char ch) {
	int cur = nSA++;
	sa[cur].len = sa[last].len + 1;

	int p = last, x = ch-'a';
	for (; p != -1 && sa[p].nexts[x] == -1; p = sa[p].link)
		sa[p].nexts[x] = cur;

	if (p == -1)
		sa[cur].link = 0;
	else {
		int q = sa[p].nexts[x];
		if (sa[q].len == sa[p].len + 1)
			sa[cur].link = q;
		else {
			int clone = nSA++;
			sa[clone] = sa[q];
			sa[clone].len = sa[p].len + 1;
			for (; p != -1 && sa[p].nexts[x] == q; p = sa[p].link)
				sa[p].nexts[x] = clone;
			sa[cur].link = sa[q].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("2774.in", "r", stdin);
	freopen("2774.out", "w", stdout);
#endif
	scanf("%s\n", s);
	scanf("%s\n", t);
	lenS = strlen(s);
	lenT = strlen(t);

	sa_init();
	for (int i = 0; i < lenS; ++i)
		sa_extend(s[i]);

	int ans = 0;
	for (int i = 0, p = 0, l = 0; i < lenT; ++i) {
		int x = t[i] - 'a';
		while (p != 0 && sa[p].nexts[x] == -1) {
			p = sa[p].link;
			l = sa[p].len;
		}
		if (sa[p].nexts[x] != -1) {
			++l;
			p = sa[p].nexts[x];
		}
		ans = max(ans, l);
	}
	printf("%d\n", ans);
	return 0;
}