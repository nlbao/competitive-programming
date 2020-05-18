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


const ld EPS = 1e-7;
const int MAX_N = 19;
const int MAX_P = (1<<MAX_N) + 1;


int n;
ld a[MAX_N][MAX_N];
ld f[MAX_P][MAX_N];


inline ld dmax(ld x, ld y) {
	if (x > y) return x;
	return y;
}


ld solve(int mask, int pos) {
	for (int i = 0; i < n; ++i)
		if (mask == (1<<i)) {
			if (i == 0) return 1;
			return 0;
		}
	if (f[mask][pos] > -1) return f[mask][pos];
	ld ans = 0;
	for (int i = 0; i < n; ++i)
		if (mask & (1<<i)) {
			if (i == pos) continue;
			ld t = a[pos][i] * solve(mask-(1<<i), pos) + a[i][pos] * solve(mask-(1<<pos), i);
			ans = dmax(ans, t);
		}
	return f[mask][pos] = ans;
}


int main() {
#ifdef DEBUG
	freopen("678E.in", "r", stdin);
	freopen("678E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	int mask = (1<<n)-1;
	for (int i = 0; i <= mask; ++i)
		for (int j = 0; j < n; ++j)
			f[i][j] = -1;

	ld ans = 0;
	for (int i = 0; i < n; ++i)
		ans = dmax(ans, solve(mask, i));
	cout << ans + EPS << endl;

	return 0;
}