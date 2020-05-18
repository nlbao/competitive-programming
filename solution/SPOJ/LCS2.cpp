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
// #include <ext/pb_ds/tree_policy.hpp>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;
const int MAX_SA = 2*MAX_N;
const int MAX_CHAR = 27;


struct State {
	int len, link;
	int nexts[MAX_CHAR];

	State() {
		len = 0;
		link = -1;
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = -1;
	}

	void operator = (const State& other) {
		len = other.len;
		link = other.link;
		for (int i = 0; i < MAX_CHAR; ++i)
			nexts[i] = other.nexts[i];
	}
};


int n, nSA, last;
char s[MAX_N];
State sa[MAX_SA];
int f[MAX_SA], g[MAX_SA], id[MAX_SA];
int c[MAX_N];


void sa_init() {
	nSA = 1;
	last = 0;
}


void sa_extend(char ch) {
	int cur = nSA++;
	sa[cur].len = sa[last].len + 1;

	int p = last, x = ch - 'a';
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
	freopen("LCS2.in", "r", stdin);
	freopen("LCS2.out", "w", stdout);
#endif
	scanf("%s\n", s);
	n = strlen(s);
	sa_init();
	for (int i = 0; i < n; ++i)
		sa_extend(s[i]);

	fill(c, 0);
	for (int i = 0; i < nSA; ++i) ++c[sa[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSA; ++i)
		id[--c[sa[i].len]] = i;

	for (int i = 0; i < nSA; ++i)
		f[i] = sa[i].len;
	while (scanf("%s\n", s) != EOF) {
		n = strlen(s);
		for (int i = 0; i < nSA; ++i)
			g[i] = 0;
		int p = 0, l = 0;
		for (int i = 0; i < n; ++i) {
			int x = s[i] - 'a';
			while (p > 0 && sa[p].nexts[x] == -1) {
				p = sa[p].link;
				l = sa[p].len;
			}
			int v = sa[p].nexts[x];
			if (v != -1) {
				g[v] = max(g[v], ++l);
				p = v;
			}
		}

		for (int i = 0; i < nSA; ++i) {
			int u = id[i], v = sa[u].link;
			g[v] = max(g[v], min(g[u], sa[v].len));
		}

		for (int i = 0; i < nSA; ++i)
			f[i] = min(f[i], g[i]);
	}

	int ans = 0;
	for (int i = 0; i < nSA; ++i)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}