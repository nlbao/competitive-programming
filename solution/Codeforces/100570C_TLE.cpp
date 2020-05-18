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
const int MAX_F = 4*MAX_N;
const int oo = 2e9;


int n, m, nQ, minF, maxG, u, v;
int a[MAX_N][MAX_N], b[MAX_N], c[MAX_N];
int f[MAX_F], g[MAX_F];


void build(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		f[k] = b[l];
		g[k] = c[l];
		return;
	}
	int mid = (l+r)>>1;
	int kl = k<<1, kr = kl+1;
	build(kl, l, mid);
	build(kr, mid+1, r);
	f[k] = min(f[kl], f[kr]);
	g[k] = max(g[kl], g[kr]);
}


void get(int k, int l, int r) {
	if (l > r || l > v || r < u) return;
	if (u <= l && r <= v) {
		minF = min(minF, f[k]);
		maxG = max(maxG, g[k]);
		return;
	}
	int mid = (l+r)>>1;
	int kl = k<<1, kr = kl+1;
	get(kl, l, mid);
	get(kr, mid+1, r);
}


inline ll sub_solve(ll limit) {
	ll ans = 0;
	build(1, 1, m);
	for (int i = 1, j = 1; i <= m; ++i) {
		while (j <= i) {
			minF = oo, maxG = -oo;
			u = j, v = i;
			get(1, 1, m);
			if (maxG-minF <= limit) break;
			++j;
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