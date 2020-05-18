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

const int MAX_N = 9*int(1e4)+4;
const int MAX_SAM = 2*MAX_N;
const int MAX_CHAR = 27;
const unsigned int oo = ll(1LL<<31);


struct State {
	int len, link;

	State() {
		len = 0;
		link = -1;
	}
};


int nSAM, last;
char s[MAX_N];
State sam[MAX_SAM];
int c[MAX_N], id[MAX_SAM];
unsigned int f[MAX_SAM];
int nexts[MAX_CHAR][MAX_SAM];


void newNode(int id) {
	sam[id].len = 0;
	sam[id].link = -1;
	for (int i = 0; i < MAX_CHAR; ++i)
		nexts[i][id] = 0;
}

void copyNode(int x, int y) {
	sam[x].len = sam[y].len;
	sam[x].link = sam[y].link;
	for (int i = 0; i < MAX_CHAR; ++i)
		nexts[i][x] = nexts[i][y];
}

bool hasNext(int id, int x) {
	return nexts[x][id] > 0;
}


void sam_init() {
	nSAM = 1;
	last = 0;
	newNode(0);
}


void sam_extend(char ch) {
	int cur = nSAM++;
	newNode(cur);
	sam[cur].len = sam[last].len + 1;

	int p = last, x = ch - 'a';
	for (; p != -1 && !hasNext(p, x); p = sam[p].link)
		nexts[x][p] = cur;

	if (p == -1)
		sam[cur].link = 0;
	else {
		int q = nexts[x][p];
		if (sam[q].len == sam[p].len + 1)
			sam[cur].link = q;
		else {
			int clone = nSAM++;
			copyNode(clone, q);
			sam[clone].len = sam[p].len + 1;
			for (; p != -1 && nexts[x][p] == q; p = sam[p].link)
				nexts[x][p] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("SUBLEX.in", "r", stdin);
	freopen("SUBLEX.out", "w", stdout);
#endif
	scanf("%s\n", s);
	int n = strlen(s);
	sam_init();
	for (int i = 0; i < n; ++i)
		sam_extend(s[i]);

	// topo sort (by len)
	fill(c, 0);
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

	// calculate
	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i];
		f[u] = 1;
		for (int x = 0; x < MAX_CHAR; ++x)
			if (hasNext(u, x)) {
				int v = nexts[x][u];
				if (f[v] == oo) f[u] = oo;
				else {
					f[u] += f[v];
					if (f[u] > oo) {
						f[u] = oo;
						break;
					}
				}
			}
	}

	// queries
	int nQ = read();
	while (nQ--) {
		unsigned int k = read();
		int p = 0;
		while (k > 0) {
			int t = -1;
			for (int x = 0; x < MAX_CHAR; ++x)
				if (hasNext(p, x)) {
					int v = nexts[x][p];
					if (k > f[v]) k -= f[v];
					else {
						t = x;
						p = v;
						break;
					}
				}
			k -= 1;
			if (t < 0) break;
			printf("%c", char('a' + t));
		}
		printf("\n");
	}
	return 0;
}