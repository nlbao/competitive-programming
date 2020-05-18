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
	#define check(i, x) (i > 0 && a[i] == x)
	#define getLink(p, i) while (!check(i-1-len[p], a[i])) p = link[p]

	static const int MAX_N = 2e3 + 33;
	static const int MAX_X = 28;
	static const int oo = 1e9;

	char a[MAX_N];
	int nNode, last;
	int nexts[MAX_N][MAX_X];
	int len[MAX_N], link[MAX_N], diff[MAX_N], sLink[MAX_N];
	int f[MAX_N], sF[MAX_N];

	inline bool hasNext(int i, int x) {
		return nexts[i][x] >= 0;
	}

	inline void newNode(int l, int k) {
		last = nNode++;
		len[last] = l;
		link[last] = k;
		filla(nexts[last], -1);
	}

	void init() {
		nNode = last = 0;
		newNode(-1, 0);
		newNode(0, 0);
		diff[0] = diff[1] = 0;
		for (int i = 0; i < MAX_N; ++i)
			f[i] = oo;
		f[0] = 0;
	}

	void add(int i, int x) {	// i: 1..n
		a[i] = x;
		int p = last;
		getLink(p, i);
		if (hasNext(p, x)) {
			last = nexts[p][x];
			return;
		}
		newNode(len[p]+2, 1);
		nexts[p][x] = last;
		if (p) {
			p = link[p];
			getLink(p, i);
			link[last] = nexts[p][x];
		}
		// build diff, sLink
		int k = link[last];
		diff[last] = len[last] - len[k];
		if (diff[last] == diff[k])
			sLink[last] = sLink[k];
		else
			sLink[last] = k;
	}

	void calF(int i) {
		for (int u = last; len[u] > 0; u = sLink[u]) {
			sF[u] = f[i - (len[sLink[u]] + diff[u])];
			int k = link[u];
			if (diff[u] == diff[k])
				sF[u] = min(sF[u], sF[k]);
			f[i] = min(f[i], sF[u]+1);
		}
	}
};


string s;
Errtree tree;


int main() {
#ifdef DEBUG
	freopen("IITKWPCE.in", "r", stdin);
	freopen("IITKWPCE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		tree.init();
		cin >> s;
		int n = s.size();
		for (int i = 1; i <= n; ++i) {
			tree.add(i, s[i-1]-'a');
			tree.calF(i);
		}
		cout << tree.f[n] << endl;
	}

	return 0;
}