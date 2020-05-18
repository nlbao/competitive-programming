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


const int MAX_N = 3033;


int n, m;
int a[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int k, x, y;
		cin >> m >> n >> k;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j] = 1;
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			a[x][y] = 0;
		}

		ll ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) if (a[i][j]) {
				if (i > 0 && j > 0) {
					a[i][j] = a[i-1][j]+1;
					a[i][j] = min(a[i][j], a[i][j-1]+1);
					a[i][j] = min(a[i][j], a[i-1][j-1]+1);
				}
				ans += a[i][j];
			}
		}

		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}