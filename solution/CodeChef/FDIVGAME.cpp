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


const int N_DIV = 5;
const int DIV[N_DIV] = {2, 3, 4, 5, 6};
const ll LIMIT = 1e18 + 1;


map<int, int> g;


int grundy(int x) {
	if (g.find(x) != g.end()) return g[x];
	set<int> q;
	for (int i = 0; i < N_DIV; ++i)
		q.insert(grundy(x / DIV[i]));
	int ans = 0;
	foreach(it, q)
		if (*it > ans) break;
		else ++ans;
	return g[x] = ans;
}


ll grundy_fast(ll x) {
	if (x < 1) return 0;
	ll n0 = 6, n1 = 1;
	while (1) {
		if (x <= n1) return 1;		x -= n1;
		if (x <= 2*n1) return 2;	x -= 2*n1;
		if (x <= 2*n1) return 3;	x -= 2*n1;
		if (x <= n0) return 0;		x -= n0;
		n0 *= 12;
		n1 *= 12;
	}
}


int main() {
#ifdef DEBUG
	freopen("FDIVGAME.in", "r", stdin);
	freopen("FDIVGAME.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	// ll n0 = 6, n1 = 1;
	// while (n0 < LIMIT && n1 < LIMIT) {
	// 	n0 = n0 * 12;
	// 	n1 = n1 * 12;
	// 	cout << n0 << " " << n1 << endl;
	// }

	g[0] = 0;
	// for (int i = 1; i <= 2000; ++i)
	// 	cout << grundy(i) << " ";
	// cout << endl;

	// for (int i = 1; i <= 2000; ++i)
	// 	cout << grundy_fast(i) << " " ;
	// cout << endl;

	// for (int i = 1; i <= 100000; ++i)
	// 	if (grundy(i) != grundy_fast(i))
	// 		cout << i << ": " << grundy(i) << " " << grundy_fast(i) << endl;

	int nTest = read();
	while (nTest--) {
		int n = read();
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ll x = read();
			x = grundy_fast(x);
			ans ^= x;
		}
		if (ans) cout << "Henry" << endl;
		else cout << "Derek" << endl;
	}

	return 0;
}