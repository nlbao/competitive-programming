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

const int MAX_N = 2*int(1e5)+5;
const int MAX_SAM = 2 * MAX_N;
const int MAX_P = 5*int(1e5)+5;

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
int id[MAX_SAM], c[MAX_SAM];
State sam[MAX_SAM];
int f[MAX_SAM];

vector<pii> p[MAX_P];
vector<int> sum[MAX_P];
int sz[MAX_P];


void sam_init() {
	nSAM = 1;
	last = 0;
	sam[0] = State();
}


void sam_extend(int x) {
	int cur = nSAM++;
	sam[cur] = State();
	sam[cur].len = sam[last].len + 1;
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


int solve(int len, int x) {
	int l = 0, r = sz[x]-1, t = 0;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (p[x][mid].first <= len) {
			t = sum[x][mid];
			l = mid+1;
		}
		else r = mid-1;
	}
	return t;
}


int main() {
#ifdef DEBUG
	freopen("SUBQUERY.in", "r", stdin);
	freopen("SUBQUERY.out", "w", stdout);
#endif
	scanf("%s\n", s);
	sam_init();
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		sam_extend(s[i]-'a');

	fill(c, 0);
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;


	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i], v = sam[u].link;
		f[v] += f[u];
		if (f[u] < MAX_P) {
			p[f[u]].push_back(make_pair(sam[v].len+1, 1));
			p[f[u]].push_back(make_pair(sam[u].len+1, -1));
		}
	}

	for (int u = 0; u < MAX_P; ++u) {
		sort(p[u].begin(), p[u].end());
		sz[u] = (int)p[u].size();
		if (sz[u] == 0) continue;
		sum[u].resize(sz[u]);
		sum[u][0] = p[u][0].second;
		for (int i = 1; i < sz[u]; ++i)
			sum[u][i] = sum[u][i-1] + p[u][i].second;
	}

	int nQ = read();
	while (nQ--) {
		int len, x;
		scanf("%d%d", &len, &x);
		printf("%d\n", solve(len, x));
	}
	return 0;
}