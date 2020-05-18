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


bool isVaild(int x, int y) {
	if (a[x][y]) return 0;
	if (x > 1 && a[x-1][y] && a[x-2][y]) return 0;
	if (x < m-2 && a[x+1][y] && a[x+2][y]) return 0;
	if (x > 0 && x < m-1 && a[x-1][y] && a[x+1][y]) return 0;
	if (y > 1 && a[x][y-1] && a[x][y-2]) return 0;
	if (y < n-2 && a[x][y+1] && a[x][y+2]) return 0;
	if (y > 0 && y < n-1 && a[x][y-1] && a[x][y+1]) return 0;
	return 1;
}


int solve() {
	if (m < n) swap(m, n);
	int ans = 0;
	filla(a, 0);
	for (int i = 0; i < m; ++i) {
		if (i&1) {
			for (int j = n-1; j >= 0; --j) if (isVaild(i, j)) {
				a[i][j] = 1;
				++ans;
			}
		}
		else {
			for (int j = 0; j < n; ++j) if (isVaild(i, j)) {
				a[i][j] = 1;
				++ans;
			}
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> m >> n;
		int ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;

		// for (int i = 0; i < m; ++i) {
		// 	for (int j = 0; j < n; ++j)
		// 		cout << a[i][j] << " ";
		// 	cout << endl;
		// }
	}

	return 0;
}