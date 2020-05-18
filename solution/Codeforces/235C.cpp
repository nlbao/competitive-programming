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
#include <ext/hash_map>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef pair<int, int> pii;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }

const int MAX_N = int(1e6)+6;
const int MAX_SAM = 2*MAX_N;
const int MAX_CHAR = 27;
const ll BASE = 10007;

struct State
{
	int len, link;
	// map<int, int> nexts;
	int nexts[MAX_CHAR];

	State() {
		len = 0;
		link = -1;
		fill(nexts, 0);
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		// nexts = other.nexts;
		memcpy(nexts, other.nexts, sizeof(nexts));
	}

	bool hasNext(int x) const {
		// return nexts.find(x) != nexts.end();
		return nexts[x] > 0;
	}
};

int nSAM, last;
char s[MAX_N];
State sam[MAX_SAM];
int c[MAX_N], id[MAX_SAM], f[MAX_SAM];
map<ll, bool> q;
hash_map<pii, int> index;


void sam_init() {
	nSAM = 1;
	last = 0;
	f[0] = 0;
}


void sam_extend(int x) {
	int cur = nSAM++;
	sam[cur].len = sam[last].len + 1;
	f[cur] = 1;

	int p = last;
	for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link) {
		sam[p].nexts[x] = cur;
	}

	if (p == -1) sam[cur].link = 0;
	else {
		int q = sam[p].nexts[x];
		if (sam[q].len == sam[p].len+1) sam[cur].link = q;
		else {
			int clone = nSAM++;
			sam[clone] = sam[q];
			sam[clone].len = sam[p].len+1;
			f[clone] = 0;
			sam[cur].link = sam[q].link = clone;
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
		}
	}
	last = cur;
}


int main() {
#ifdef DEBUG
	freopen("235C.in", "r", stdin);
	freopen("235C.out", "w", stdout);
#endif
	scanf("%s\n", s);
	int n = strlen(s);
	sam_init();
	for (int i = 0; i < n; ++i)
		sam_extend(s[i] - 'a');

	// topo sort
	fill(c, 0);
	for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
	for (int i = 1; i <= n; ++i) c[i] += c[i-1];
	for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

	// calulate f
	for (int i = nSAM-1; i >= 0; --i) {
		int u = id[i];
		int v = sam[u].link;
		f[v] += f[u];
	}

	// queries
	int nQ;
	scanf("%d\n", &nQ);
	while (nQ--) {
		scanf("%s\n", s);
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			s[n+i] = s[i];
		int m = 2*n - 1;

		ll pn = 1;
		for (int i = 0; i < n-1; ++i)
			pn *= BASE;

		// calculate
		ll ans = 0, hl = s[0], hr = 0;
		q.clear();
		int u = 0, len = 0;
		for (int i = 0; i < m; ++i) {
			int x = s[i] - 'a';
			while (u > 0 && !sam[u].hasNext(x)) {
				u = sam[u].link;
				len = sam[u].len;
			}
			if (sam[u].hasNext(x)) {
				u = sam[u].nexts[x];
				++len;
			}

			if (i > n-1) {
				hr = hr - pn * hl;
				hl = s[i-n+1];
			}
			hr = hr*BASE + ll(s[i]);

			if (i >= n-1 && len >= n && q.find(hr) == q.end()) {
				ans += f[u];
				q[hr] = true;
			}

			if (len >= n) {
				while (u > 0 && sam[sam[u].link].len >= n-1) {
					u = sam[u].link;
					len = sam[u].len;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}