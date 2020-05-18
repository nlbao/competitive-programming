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


const int MAX_N = 414;
const int oo = 2e9;


int n, m, nQ;
int a[MAX_N][MAX_N], b[MAX_N], c[MAX_N];
int qmax[MAX_N], qmin[MAX_N];


inline ll sub_solve(ll limit) {
	ll ans = 0;
	int lmin = 1, rmin = 0;
	int lmax = 1, rmax = 0;
	for (int i = 1, j = 1; i <= m; ++i) {
		while (lmin <= rmin && b[i] < b[qmin[rmin]]) --rmin;
		while (lmax <= rmax && c[i] > c[qmax[rmax]]) --rmax;
		qmin[++rmin] = i;
		qmax[++rmax] = i;
		while (j <= i) {
			while (lmin <= rmin && qmin[lmin] < j) ++lmin;
			while (lmax <= rmax && qmax[lmax] < j) ++lmax;
			if (lmin > rmin || lmax > rmax) break;
			if (c[qmax[lmax]] - b[qmin[lmin]] <= limit) break;
			++j;
		}
		if (lmin > rmin || lmax > rmax) {
			lmin = 1, rmin = 0;
			lmax = 1, rmax = 0;
			j = i+1;
			continue;
		}
		ans += i-j+1;
	}
	return ans;
}


ll solve(int limit) {
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k <= m; ++k)
			b[k] = oo, c[k] = -oo;
		for (int j = i; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				b[k] = min(b[k], a[j][k]);
				c[k] = max(c[k], a[j][k]);
			}
			ans += sub_solve(limit);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100570C.in", "r", stdin);
	freopen("100570C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> nQ;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	while (nQ--) {
		int k;
		cin >> k;
		cout << solve(k) << endl;
	}

	return 0;
}