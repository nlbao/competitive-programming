// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 101;


int n, m;
int a[MAX_N][MAX_N];
int f[30][30];


bool isVaild(int x, int y) {
	if (x > 1 && a[x-1][y] && a[x-2][y]) return 0;
	if (x < m-2 && a[x+1][y] && a[x+2][y]) return 0;
	if (x > 0 && x < m-1 && a[x-1][y] && a[x+1][y]) return 0;
	if (y > 1 && a[x][y-1] && a[x][y-2]) return 0;
	if (y < n-2 && a[x][y+1] && a[x][y+2]) return 0;
	if (y > 0 && y < n-1 && a[x][y-1] && a[x][y+1]) return 0;
	return 1;
}


bool check(int mask) {
	filla(a, 0);
	for (int i = 0, pos = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			a[i][j] = (mask>>pos)&1;
			++pos;
		}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] && !isVaild(i, j))
				return 0;
	return 1;
}


int solve() {
	int ans = 0;
	int s = m * n;
	int nMask = 1<<s;
	for (int mask = 0; mask < nMask; ++mask) {
		if (check(mask))
			ans = max(ans, __builtin_popcount(mask));
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j) {
			m = i, n = j;
			f[i][j] = solve();
		}

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> m >> n;
		int ans = f[m][n];
		cout << "Case #" << testid << ": " << ans << endl;

		// for (int i = 0; i < m; ++i) {
		// 	for (int j = 0; j < n; ++j)
		// 		cout << a[i][j] << " ";
		// 	cout << endl;
		// }
	}

	return 0;
}