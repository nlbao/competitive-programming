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


const int MAX_N = 111;
const double oo = 1e9;

int N;
double P;
double w[MAX_N], h[MAX_N], d[MAX_N];


double solve_visible() {
	double d = 2*sqrt(1.0 * (sqr(w[0]) + sqr(h[0])));
	double m = 2*min(h[0], w[0]);
	cout << (d-m) << endl;
	double remain = P - 2.0 * N * (h[0] + w[0]), ans = remain;
	for (int i = 1; i <= N; ++i) {
		double g = m*i;
		if (g > remain) break;
		double r = remain - g;
		// cout << i << ": " << g << " " <<  r << " " << ans << endl;
		r = max(0.0, r - (d-m)*i);
		ans = min(ans, r);
	}
	return P - ans;
}


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> N >> P;
		for (int i = 0; i < N; ++i)
			cin >> w[i] >> h[i];
		double ans = solve_visible();
		cout << "Case #" << tid << ": " << ans << endl;
	}

	return 0;

}