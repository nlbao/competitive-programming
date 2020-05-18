#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 3*int(1e4) + 4;
const int MAX_IT = 4*MAX_N;


int n, cnt, lpos, rpos;
bool ok[MAX_N];
pii edges[MAX_N];
vector<pii> e[MAX_N];
int start[MAX_N], finish[MAX_N], h[MAX_N], a[MAX_N];
int f[MAX_IT], temp[MAX_IT];
map<string, int> id;


void dfs(int u, int value) {
	ok[u] = false;
	start[u] = ++cnt;
	a[cnt] = value;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i].first;
		if (!ok[v]) continue;
		h[v] = h[u]+1;
		dfs(v, value ^ e[u][i].second);
	}
	finish[u] = cnt;
}


void build(int k, int l, int r) {
	if (l > r) return;
	temp[k] = 0;
	if (l == r) {
		f[k] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	int kleft = k<<1, kright = kleft+1;
	build(kleft, l, mid);
	build(kright, mid+1, r);
	f[k] = f[kleft] + f[kright];
}


void update(int k, int l, int r) {
	if (l > rpos || r < lpos) return;
	if (lpos <= l && r <= rpos) {
		temp[k] ^= 1;
		f[k] = (r-l+1) - f[k];
		return;
	}
	int mid = (l+r)>>1;
	int kleft = k<<1, kright = kleft+1;
	if (temp[k]) {
		temp[kleft] ^= 1;
		temp[kright] ^= 1;
		f[kleft] = (mid-l+1) - f[kleft];
		f[kright] = (r-mid) - f[kright];
		temp[k] = 0;
	}
	update(kleft, l, mid);
	update(kright, mid+1, r);
	f[k] = f[kleft] + f[kright];
}


int main() {
#ifdef DEBUG
	freopen("5039.in", "r", stdin);
	freopen("5039.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	string s, t;
	int nTest;
	cin >> nTest;
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		int m = 0;
		id.clear();
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			if (id.find(s) == id.end()) {
				id[s] = ++m;
				e[m].clear();
			}
		}
		for (int i = 1; i <= n-1; ++i) {
			int c;
			cin >> s >> t >> c;
			int u = id[s], v = id[t];
			edges[i] = make_pair(u, v);
			e[u].push_back(make_pair(v, c));
			e[v].push_back(make_pair(u, c));
		}

		cnt = 0;
		filla(ok, true);
		h[1] = 1;
		dfs(1, 0);

		build(1, 1, n);

		cout << "Case #" << test_id << ":" << "\n";
		cin >> m;
		while (m--) {
			cin >> s;
			if (s[0] == 'Q') {
				ll ans = ll(f[1]) * ll(n-f[1]) * 2LL;
				cout << ans << "\n";
			}
			else {
				int i;
				cin >> i;
				int u = edges[i].first, v = edges[i].second;
				if (h[u] < h[v]) swap(u, v);
				lpos = start[u], rpos = finish[u];
				update(1, 1, n);
			}
		}
	}
	return 0;
}