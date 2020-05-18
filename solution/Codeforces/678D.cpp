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


// Matrix Exponentiation
typedef vector < vector<ll> > Matrix;
const ll MOD = 1e9 + 7;

inline ll mmod(ll x) {
	return x % MOD;
}

ll add(ll a, ll b) {
	return (a + b) % MOD;
}

ll mul(ll a, ll b) {
	if (b == 0) return 0;
	ll t = mul(a, b / 2);
	t = add(t, t);
	if (b & 1) t = add(t, a);
	return t;
}

Matrix create(int m, int n) {
	return Matrix(m, vector<ll>(n, 0));
}

Matrix mul(const Matrix &a, const Matrix &b) {
	int n = a.size(), m = b[0].size(), p = a[0].size();
	Matrix c = create(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < p; ++k)
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

Matrix pow(const Matrix &a, ll n) {
	if (n == 1) return a;
	Matrix t = pow(a, n / 2);
	t = mul(t, t);
	if (n & 1) return mul(t, a);
	return t;
}


ll solve() {
	ll A, B, n, x;
	cin >> A >> B >> n >> x;
	if (n == 0) return mmod(x);
	if (n == 1) return mmod(A*x + B);
	Matrix a = create(2, 2);
	a[0][0] = a[0][1] = A;
	a[1][0] = 0;
	a[1][1] = 1;
	a = pow(a, n-1);

	// for (int i = 0; i < 2; ++i) {
	// 	for (int j = 0; j < 2; ++j)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }

	ll s0 = mmod(a[0][0] * A);
	ll s1 = mmod(a[0][1] + 1);
	ll ans = mmod(mmod(s0 * x) + s1 * B);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("678D.in", "r", stdin);
	freopen("678D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cout << solve() << endl;

	return 0;
}