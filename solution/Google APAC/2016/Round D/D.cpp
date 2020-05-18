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


const int MAX_N = 1001;
const ll oo = 1e9 + 2;


int N, M, L;
ll a[MAX_N], b[MAX_N], p[MAX_N];


ll solve() {
	ll ans = oo;
	int nMask = 1<<N;
	for (int mask = 0; mask < nMask; ++mask) {
		ll sa = 0, sb = 0, sp = 0;
		for (int i = 0; i < N; ++i)
			if ((mask>>i)&1) {
				sa += a[i], sb += b[i];
				sp += p[i];
			}
		if (sa > L || sb < L || sp > M) continue;
		ans = min(ans, sp);
	}
	return ans >= oo ? -1 : ans;
}


int main() {
#ifdef DEBUG
	// freopen("D.in", "r", stdin);
	freopen("D-small-attempt0.in", "r", stdin);
	// freopen("D-large.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> N >> M >> L;
		for (int i = 0; i < N; ++i)
			cin >> a[i] >> b[i]  >> p[i];
		cout << "Case #" << testid << ": ";
		ll ans = solve();
		if (ans > -1) cout << ans << endl;
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}