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


const int MAX_N = 2*int(1e5+5);
const int MAX_CHAR = 27;
const int oo = int(1e9);


struct State {
	int len, link, firstPos, minNext;
	int nexts[MAX_CHAR];

	State () {
		minNext = oo;
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = -1;
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		firstPos = other.firstPos;
		minNext = other.minNext;
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = other.nexts[i];
	}
};


int n, m, last, nA;
char s[MAX_N];
State a[2*MAX_N];


void sa_init() {
	nA = 1;		last = 0;
	a[0].link = -1;
	a[0].len = 0;
	a[0].firstPos = -1;
}


void sa_extend(char ch) {
	int cur = nA++;
	a[cur].len = a[last].len + 1;
	a[cur].firstPos = a[cur].len - 1;

	int p = last, x = ch - 'a';
	for (; p != -1 && a[p].nexts[x] == -1; p = a[p].link) {
		a[p].nexts[x] = cur;
		a[p].minNext = min(a[p].minNext, x);
	}

	if (p == -1)
		a[cur].link = 0;
	else {
		int q = a[p].nexts[x];
		if (a[q].len == a[p].len + 1)
			a[cur].link = q;
		else {
			int clone = nA++;
			a[clone] = a[q];
			a[clone].len = a[p].len + 1;
			for (; p != -1 && a[p].nexts[x] == q; p = a[p].link)
				a[p].nexts[x] = clone;
			a[q].link = a[cur].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("MINMOVE.in", "r", stdin);
	freopen("MINMOVE.out", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	m = n;
	for (int i = 0; i < n; ++i)
		s[m++] = s[i];
	s[m] = '\0';

	sa_init();
	for (int i = 0; i < m; ++i)
		sa_extend(s[i]);

	int p = 0;
	for (int i = 0; i < n; ++i)
		p = a[p].nexts[a[p].minNext];
	printf("%d\n", a[p].firstPos - n + 1);
	return 0;
}