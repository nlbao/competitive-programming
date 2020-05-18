#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const ll MODULE2 = 1e9 + 7;
const ll oo = 2*MODULE2;
const ll MODULE = 99991;


inline ll mmod(ll x) {
	if (abs(x) >= MODULE) x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x % MODULE;
	ll t = mpow(x, d<<1);
	t = (t*t) % MODULE;
	if (d&1) return (t*x) % MODULE;
	return t;
}


ll gauss(vector<vector<ll> > &a, vector<ll> &ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (abs(a[i][col]) > abs(a[k][col]))
				k = i;
		if (a[k][col] == 0) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				ll c = a[i][col] * mpow(a[row][col], MODULE-2);
				for (int j = col+1; j <= m; ++j)
					a[i][j] = mmod(a[i][j] - a[row][j] * c);
				a[i][col] = 0;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j] != 0) {
				zero = false;
				break;
			}
		if (zero && a[i][m] != 0)
			return 0;
	}

	int rank = 0;
	ans.assign(m, 0);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j] != 0) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) {
		ll ans = 1;
		for (int i = 0; i < m-rank; ++i)
			ans = (ans * MODULE) % MODULE2;
		return ans;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("a-birthday-party.in", "r", stdin);
	freopen("a-birthday-party.out", "w", stdout);
#endif
	int n = read();
	vector<vector<ll> > a;
	vector<ll> b;
	a.resize(n, vector<ll>(n+1, 0));
	for (int i = 0; i < n; ++i) {
		a[i][i] = -1;
		int m = read();
		for (int k = 0; k < m; ++k) {
			int j = read() - 1;
			a[i][j] = 1;
		}
	}

	ll ans = gauss(a, b);
	cout << ans << endl;

	return 0;
}