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

inline ll read() {	ll x;   cin >> x;   return x;   }


typedef pair<pii, int> Query;


const int MAX_N = 5e5 + 5;
const int oo = 1e9;


int n, nQ;
int f[MAX_N], ans[MAX_N];
pii a[MAX_N];
Query q[MAX_N];
map<int, int> pre;


inline void update(int i, int value) {
	while (i <= n) {
		f[i] = min(f[i], value);
		i += lowbit(i);
	}
}


inline int get(int i) {
	int ans = oo;
	while (i > 0) {
		ans = min(ans, f[i]);
		i -= lowbit(i);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("522D.in", "r", stdin);
	freopen("522D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n >> nQ;
	for (int i = 1; i <= n; ++i) {
		int x = read(), p = 0;
		map<int, int>::iterator it = pre.find(x);
		if (it == pre.end()) pre[x] = i;
		else {
			p = it->second;
			it->second = i;
		}
		if (p) a[i-1] = pii(-p, i);
	}
	sort(a, a+n);

	for (int i = 0; i < nQ; ++i) {
		int x, y;
		cin >> x >> y;
		q[i] = Query(pii(-x, y), i);
	}
	sort(q, q+nQ);

	for (int i = 1; i <= n; ++i)
		f[i] = oo;
	for (int i = 0, j = 0; i < nQ; ++i) {
		int l = -q[i].fr.fr, r = q[i].fr.sc;
		while (j < n && -a[j].fr >= l) {
			update(a[j].sc, a[j].sc + a[j].fr);
			++j;
		}
		int x = get(r);
		ans[q[i].sc] = x < oo ? x : -1;
	}

	for (int i = 0; i < nQ; ++i)
		cout << ans[i] << '\n';

	return 0;
}