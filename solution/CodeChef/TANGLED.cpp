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

const int MAX_N = 2*2*int(1e5)+5;
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


int nSAM, last = 0;
char s[MAX_N];
int id[MAX_SAM], c[MAX_SAM];
State sam[MAX_SAM];
ll f[MAX_SAM][2];
ll sum[MAX_SAM];


void sam_init() {
	nSAM = 1;
	last = 0;
	sam[0] = State();
	f[0][0] = f[0][1] = 0;
}


void sam_extend(int x, int id) {
	int cur = nSAM++;
	sam[cur] = State();
	sam[cur].len = sam[last].len + 1;
	f[cur][id] = 1;
	f[cur][1-id] = 0;

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
			f[clone][0] = f[clone][1] = 0;
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
			sam[cur].link = sam[q].link = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("TANGLED.in", "r", stdin);
	freopen("TANGLED.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		sam_init();
		scanf("%s\n", s);
		int m = strlen(s), n = m;
		for (int i = 0; i < m; ++i)
			sam_extend(s[i]-'a', 0);
		sam_extend('z'-'a'+1, 0);

		scanf("%s\n", s);
		m = strlen(s);
		for (int i = 0; i < m; ++i)
			sam_extend(s[i]-'a', 1);
		n += m+1;

		for (int i = 0; i <= n; ++i) c[i] = 0;
		for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
		for (int i = 1; i <= n; ++i) c[i] += c[i-1];
		for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

		for (int i = nSAM-1; i >= 0; --i) {
			int u = id[i];
			for (int x = 0; x < 2; ++x)
				f[sam[u].link][x] += f[u][x];
		}

		int len;
		scanf("%d\n", &len);
		for (int i = 0; i <= len; ++i) sum[i] = 0;
		for (int i = 0; i < nSAM; ++i) {
			int u = id[i];
			int l = sam[sam[u].link].len+1, r = sam[u].len+1;
			r = min(r, len+1);
			ll tmp = f[u][0] * f[u][1];
			sum[l] += tmp;
			sum[r] -= tmp;
		}

		ll ans = 0;
		for (int i = 1; i <= len; ++i) {
			ans += sum[i];
			printf("%lld ", ans);
		}
		printf("\n");
	}
	return 0;
}