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


const double EPS = 1e-7;

double len, v1, v2;
int n, k;


bool solve(double T, double len, int n) {
	// cout << T << " " << len << " " << n << endl;
	if (T < 0) return false;
	if (n <= 0 || len < EPS) return true;
	if (v1*T >= len) return true;
	double t = (len - v1*T) / (v2 - v1);
	double x = 0, y = v2*t;
	double t2 = (y-x) / (v1+v2);
	double m = v1*t + x;
	if (n == k && T-t >= 0) return true;
	// cout << "!!! " << " " << t << " " << t2 << endl;
	return solve(T-t-t2, len-m, n-k);
}


int main() {
#ifdef DEBUG
	freopen("701D.in", "r", stdin);
	freopen("701D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> len >> v1 >> v2 >> k;

	// cout << solve(4.7142857143, len, n) << endl;
	// return 0;

	double l = 0, r = len, ans = len;
	for (int i = 0; i < 1000; ++i) {
		double mid = (l+r) / 2;
		// cout << mid << endl;
		if (solve(mid, len, n)) {
			// cout << "		ok!" << endl;
			ans = mid;
			r = mid;
		}
		else l = mid;
	}
	cout << ans << endl;

	return 0;
}