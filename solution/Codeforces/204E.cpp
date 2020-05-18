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

const int MAX_N = 2*int(1e5) + 5;
const int MAX_SAM = 2*MAX_N;


struct State {
	int len, link, id;
	map<int, int> nexts;

	State() {
		len = 0;
		link = -1;
		id = -1;
		nexts.clear();
	}

	void operator = (const State &other) {
		len = other.len;
		link = other.link;
		id = other.id;
		nexts = other.nexts;
	}

	bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};


int n, k, nSAM, last;
string s[MAX_N];
State sam[MAX_SAM];
int cnt[MAX_SAM], top[MAX_SAM];
vector<int> e[MAX_SAM];


void sam_init() {
	nSAM = 1;
	last = 0;
}


void sam_extend(int x, int id) {
	int cur = nSAM++;
	sam[cur].len = sam[last].len + 1;
	sam[cur].id = id;

	int p = last;
	for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
		sam[p].nexts[x] = cur;

	if (p == -1) sam[cur].link = 0;
	else {
		int q = sam[p].nexts[x];
		if (sam[q].len == sam[p].len + 1) sam[cur].link = q;
		else {
			int clone = nSAM++;
			sam[clone] = sam[q];
			sam[clone].len = sam[p].len + 1;
			sam[cur].link = sam[q].link = clone;
			for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
				sam[p].nexts[x] = clone;
		}
	}
	last = cur;
}


set<int>* merge(set<int>* &a, set<int>* &b) {
	// if (a->size() > b->size())
	// 	return merge(b, a);
	b->insert(a->begin(), a->end());
	delete a;
	return b;
}


set<int>* dfs(int u) {
	set<int> *list = new set<int>();
	if (sam[u].id > -1) list->insert(sam[u].id);
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		set<int> *tmp = dfs(e[u][i]);
		list = merge(list, tmp);
	}
	// number of original strings which contains the substrings at state u
	cnt[u] = (int)list->size();
	return list;
}


void dfs_2(int u) {
	if (u > 0) {
		// top[u] = the state which has length as long as possible,
		// and cnt[top[u]] >= k
		if (cnt[u] >= k) top[u] = u;
		else top[u] = top[sam[u].link];
	}
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i)
		dfs_2(e[u][i]);
}


ll solve(int id) {
	ll ans = 0;
	for (int i = 0, u = 0, m = s[id].length(); i < m; ++i) {
		int x = s[id][i] - 'a';
		u = sam[u].nexts[x];
		int p = top[u];
		if (p > 0) {
			// ans += number of substrings end at state u (s[i]),
			// and be contained in at least k original strings.
			if (p == u) ans += ll(i+1);
			else ans += ll(sam[p].len);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("204E.in", "r", stdin);
	freopen("204E.out", "w", stdout);
#endif
	sam_init();
	scanf("%d%d\n", &n, &k);
	for (int i = 0; i < n; ++i) {
		getline(cin, s[i]);
		for (int j = 0, m = s[i].length(); j < m; ++j)
			sam_extend(s[i][j] - 'a', i);
		sam_extend('z'-'a'+1, -1);
	}

	for (int i = 1; i < nSAM; ++i)
		e[sam[i].link].push_back(i);

	dfs(0);
	top[0] = 0;
	dfs_2(0);

	for (int i = 0; i < n; ++i)
		printf("%lld ", solve(i));
	return 0;
}