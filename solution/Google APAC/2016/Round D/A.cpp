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


const int MAX_N = 2001;
const int MAX_S = 2*MAX_N;


ld f[MAX_S][MAX_N];


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(f, 0);
	f[0][0] = 1;
	for (int s = 1; s < MAX_S; ++s) {
		for (int n = 1; n < MAX_N; ++n) {
			int m = s-n;
			if (m >= n) continue;
			f[s][n] = (m * f[s-1][n] + n * f[s-1][n-1]) / s;
		}
	}

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int n, m;
		cin >> n >> m;
		ld ans = f[n+m][n];
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}