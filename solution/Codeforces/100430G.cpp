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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


struct Node {
	int x, y, c;
	Node() {	x = y = c = 0;	}
	Node(int xx, int yy, int cc) : x(xx), y(yy), c(cc) {
		if (x > y) swap(x, y);
	}
	bool operator < (const Node &o) const {
		return x != o.x ? x < o.x : y != o.y ? y < o.y : c > o.c;
	}
};


const int MAX_N = 1e5 + 55;


int n;
int a[MAX_N];
vector<Node> ans, tmp;


int main() {
#ifdef DEBUG
	freopen("100430G.in", "r", stdin);
	freopen("100430G.out", "w", stdout);
#else
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int k = 1;
	for (int i = 1; i <= n; ++i) {
		while (k < i && a[k] == 0) ++k;
		while (k < i && a[i]) {
			int c = min(a[k], a[i]);
			ans.pb(Node(k, i, c));
			a[k] -= c;
			a[i] -= c;
			while (k < i && a[k] == 0) ++k;
		}
	}

	if (k <= n) {
		while (a[k] > 1 && !ans.empty()) {
			Node last = ans.back();
			ans.pop_back();
			if (last.x == k || last.y == k) {
				tmp.pb(last);
				continue;
			}
			int c = min(last.c, a[k] >> 1);
			a[k] -= 2*c;
			last.c -= c;
			if (last.c) ans.pb(last);
			tmp.pb(Node(last.x, k, c));
			tmp.pb(Node(last.y, k, c));
		}
		sort(tmp.begin(), tmp.end());
		int m = tmp.size();
		for (int i = 0, j = 0; i < m; i = j) {
			int s = 0;
			while (tmp[j].x == tmp[i].x && tmp[j].y == tmp[i].y) {
				s += tmp[j].c;
				++j;
			}
			ans.pb(Node(tmp[i].x, tmp[i].y, s));
		}
	}

	sort(ans.begin(), ans.end());
	int n = ans.size();
	cout << n << endl;
	for (int i = 0; i < n; ++i)
		cout << ans[i].x << " " << ans[i].y << " " << ans[i].c << endl;

	return 0;
}