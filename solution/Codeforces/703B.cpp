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


const int MAX_N = 1e5+55;

ll a[MAX_N];
bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("703B.in", "r", stdin);
	freopen("703B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n, k;
	cin >> n >> k;
	ll ans = 0, s = 0, s0 = 0, ans0=0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	a[0] = 0;

	filla(ok, true);
	while (k--) {
		int x = read();
		ok[x] = false;
		s -= a[x];
		s0 += a[x];
	}

	for (int i = 1; i <= n; ++i) {
		if (ok[i]) {
			if (ok[i-1]) ans += a[i]*a[i-1];
		}
		else {
			ans += a[i]*s;
			ans0 += a[i] * (s0-a[i]);
		}
	}
	if (ok[n] && ok[1]) ans += a[n]*a[1];
	ans += ans0/2;
	cout << ans << endl;

	return 0;
}