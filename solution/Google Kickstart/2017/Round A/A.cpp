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


const int MAX_N = 1005;
const ll MOD = 1e9+7;


int n, m;
ll cnt[MAX_N][MAX_N];


ll cal(int i, int k) {
	return (ll(n-i+1) * (m-k+1)) % MOD;
}


ll solve() {
	if (n < m) swap(n, m);
	--n, --m;
	filla(cnt, 0);
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= m; ++k) {
			++cnt[i][k];
			int len = i+k;
			if (len <= m) ++cnt[len][len];
		}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
			ll f = cal(i, i);
			f = (f * cnt[i][i]) % MOD;
			ans = (ans + f) % MOD;
		}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> n >> m;
		ll ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}