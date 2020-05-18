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


typedef vector < vector<ll> > Matrix;
const ll MOD = 1E9 + 7;

inline ll mmod(ll x) {
	return x%MOD;
}

Matrix create(int m, int n) {
	return Matrix(m, vector<ll>(n, 0));
}

Matrix mul(const Matrix &a, const Matrix &b) {
	Matrix c = create(a.size(), b[0].size());
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b[0].size(); ++j)
			for (int k = 0; k < (int)a[i].size(); ++k)
				c[i][j] = mmod(c[i][j] + mmod(a[i][k] * b[k][j]));
	return c;
}

Matrix pow(const Matrix &a, ll n) {
	if (n == 1) return a;
	Matrix t = pow(a, n / 2);
	t = mul(t, t);
	if (n & 1) return mul(t, a);
	return t;
}

////////////////////////////////


const int MAX_N = 1e2+2;

int n;
ll K, a[MAX_N];


int bitcounts(ll x) {
	int ans = 0;
	while (x > 0) {
		if (x&1) ++ans;
		x >>= 1;
	}
	return ans;
}


bool check(ll x, ll y) {
	return (bitcounts(x^y) % 3) == 0;
}


int main() {
#ifdef DEBUG
	freopen("691E.in", "r", stdin);
	freopen("691E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> K;
	set<ll> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		q.insert(a[i]);
	}

	if (K == 1) {
		cout << n << endl;
		return 0;
	}

	Matrix base = create(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			base[i][j] = (int)check(a[i], a[j]);

	Matrix tmp = pow(base, K-1);

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans = (ans + tmp[i][j]) % MOD;
	cout << ans << endl;

	return 0;
}