#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


struct Errtree {
	#define check(i, x) (i >= 0 && a[i] == x)

	static const int MAX_N = 2e5 + 5;
	static const int MAX_C = 28;

	int nNode, last;
	char a[MAX_N];
	int len[MAX_N], link[MAX_N];
	ll cnt[MAX_N];
	int nexts[MAX_N][MAX_C];

	inline bool hasNext(int i, int x) {
		return nexts[i][x] > -1;
	}

	inline void newNode(int i, int l, int k) {
		len[i] = l;
		link[i] = k;
		for (int x = 0; x < MAX_C; ++x)
			nexts[i][x] = -1;
		cnt[i] = 0;
	}

	void init() {
		nNode = 2;
		last = 1;
		newNode(0, -1, 0);
		newNode(1, 0, 0);
	}

	void add(int i, int x) {
		a[i] = x;
		int p = last;
		while (!check(i-1-len[p], x))
			p = link[p];
		if (hasNext(p, x)) {
			last = nexts[p][x];
			++cnt[last];
			return;
		}
		last = nNode++;
		newNode(last, len[p]+2, 1);
		++cnt[last];
		nexts[p][x] = last;
		if (p) {
			do {
				p = link[p];
			} while (!check(i-1-len[p], x));
			link[last] = nexts[p][x];
		}
	}

	void buildCnt() {
		for (int i = nNode-1; i > 0; --i)
			cnt[link[i]] += cnt[i];
	}
};


int n, m;
string a, b;
Errtree treeA, treeB;


int solve_1(int x, int y) {
	if (x < 0) return 0;
	int ans = 0;
	if (x > 1 && (y < 0 || treeA.cnt[x] > treeB.cnt[y]))
		++ans;
	for (int i = 0; i < Errtree::MAX_C; ++i) {
		if (!treeA.hasNext(x, i)) continue;
		if (y < 0 || !treeB.hasNext(y, i))
			ans += solve_1(treeA.nexts[x][i], -1);
		else
			ans += solve_1(treeA.nexts[x][i], treeB.nexts[y][i]);
	}
	return ans;
}


int solve_2(int x, int y) {
	if (x < 0 || y < 0) return 0;
	int ans = 0;
	if (x > 1 && treeA.cnt[x] == treeB.cnt[y])
		++ans;
	for (int i = 0; i < Errtree::MAX_C; ++i) {
		if (!treeA.hasNext(x, i)) continue;
		if (y < 0 || !treeB.hasNext(y, i))
			continue;
		ans += solve_2(treeA.nexts[x][i], treeB.nexts[y][i]);
	}
	return ans;
}


int solve_3(int x, int y) {
	if (y < 0) return 0;
	int ans = 0;
	if (y > 1 && (x < 0 || treeA.cnt[x] < treeB.cnt[y]))
		++ans;
	for (int i = 0; i < Errtree::MAX_C; ++i) {
		if (!treeB.hasNext(y, i)) continue;
		if (x < 0 || !treeA.hasNext(x, i))
			ans += solve_3(-1, treeB.nexts[y][i]);
		else
			ans += solve_3(treeA.nexts[x][i], treeB.nexts[y][i]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("2059.in", "r", stdin);
	freopen("2059.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		treeA.init();
		treeB.init();
		cin >> a >> b;
		n = a.size();
		m = b.size();
		for (int i = 0; i < n; ++i)
			treeA.add(i, a[i]-'a');
		for (int i = 0; i < m; ++i)
			treeB.add(i, b[i]-'a');
		treeA.buildCnt();
		treeB.buildCnt();
		int ans1 = solve_1(0, 0) + solve_1(1, 1);
		int ans2 = solve_2(0, 0) + solve_2(1, 1);
		int ans3 = solve_3(0, 0) + solve_3(1, 1);
		cout << "Case #" << testid << ": " << ans1 << " " << ans2 << " " << ans3 << endl;
	}

	return 0;
}