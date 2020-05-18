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

const int MAX_N = 250000+10;
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


int nSAM;
char s[MAX_N];
int pos[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];
queue<int> q;

int id[MAX_SAM], c[MAX_SAM];
State sam[MAX_SAM];
ll f[MAX_SAM];


void sam_init() {
	nSAM = 1;
}


int sam_extend(int x, int last) {
	int cur = nSAM++;
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
	return cur;
}


int main() {
#ifdef DEBUG
	freopen("TSUBSTR.in", "r", stdin);
	freopen("TSUBSTR.out", "w", stdout);
#endif
	int n, nQ;
	scanf("%d%d\n", &n, &nQ);
	scanf("%s\n", s);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d\n", &x, &y);
		--x;	--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	sam_init();
	fill(ok, true);
	pos[0] = sam_extend(s[0]-'a', 0);
	while (!q.empty()) q.pop();
	q.push(0);
	ok[0] = false;
	while (!q.empty()) {
		int u = q.front();	q.pop();
		for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
			int v = e[u][i];
			if (ok[v]) {
				ok[v] = false;
				q.push(v);
				pos[v] = sam_extend(s[v]-'a', pos[u]);
			}
		}
	}

	fill(c, 0);
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i];
		f[u] = 1;
		for (int x = 0; x < MAX_CHAR; ++x)
			if (sam[u].hasNext(x))
				f[u] += f[sam[u].nexts[x]];
	}
	printf("%lld\n", f[0]);

	while (nQ--) {
		ll k;
		scanf("%s", s);
		scanf("%lld\n", &k);
		if (k > f[0]) {
			printf("-1\n");
			continue;
		}
		if (k == 1) {
			printf("\n");
			continue;
		}

		--k;
		int u = 0;
		while (k > 0) {
			for (int i = 0; i < 26; ++i) {
				int x = s[i]-'a';
				if (!sam[u].hasNext(x)) continue;
				int v = sam[u].nexts[x];
				if (f[v] < k) k -= f[v];
				else {
					printf("%c", s[i]);
					u = v;
					break;
				}
			}
			--k;
		}
		printf("\n");
	}
	return 0;
}