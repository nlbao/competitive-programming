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


inline bool ok(int x, int y, int z) {
	if (x+y <= z) return 0;
	if (y+z <= x) return 0;
	if (z+x <= y) return 0;
	return 1;
}


int solve(int x0, int x1, int x2, int y) {
	if (x0 == y && x1 == y && x2 == y) return 0;
	cout << x0 << " " << x1 << " " << x2 << endl;

	if (!ok(x0, x1, x2)) {
		cout << "!!!!!!!!!!!!!!!!!!" << endl;
		return 0;
	}

	int x[3];
	x[0] = x0, x[1] = x1, x[2] = x2;
	sort(x, x+3);
	if (x[0] == y && x[1] == y) return 1;

	if (x[1] == x[2] && x[0] == x[1]) {
		int t = x[1] / 3;
		t = max(t, y);
		return solve(x[1], x[2], t, y) + 1;
	}

	int t = x[1] - x[0] + 1;
	t = max(t, y);
	return solve(x[0], x[1], t, y) + 1;
}


int main() {
#ifdef DEBUG
	freopen("712C.in", "r", stdin);
	freopen("712C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int x, y;
	cin >> x >> y;
	cout << solve(x, x, x, y) << endl;

	return 0;
}