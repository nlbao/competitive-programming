#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


ll MODULE;
ll n, k;
int l;


inline ll mmod(ll x) {
	x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


inline ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x % MODULE;
	ll t = mpow(x, d >> 1);
	t = (t*t) % MODULE;
	if (d&1) t = (t*x) % MODULE;
	return t;
}


// Matrix Exponentiation
typedef vector < vector<ll> > Matrix;

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
	Matrix t = pow(a, n >> 1);
	t = mul(t, t);
	if (n & 1) t = mul(t, a);
	return t;
}


int main() {
#ifdef DEBUG
	freopen("551D.in", "r", stdin);
	freopen("551D.out", "w", stdout);
#endif
	scanf("%lld %lld %d %lld", &n, &k, &l, &MODULE);

	for (int i = l; i < 63; ++i)
		if ((k>>i) & 1) {
			printf("0");
			return 0;
		}

	ll fn, gn;
	if (n == 0) {
		fn = gn = 0;
	}
	else if (n == 1) {
		fn = 2;
		gn = 0;
	}
	if (n > 1) {
		Matrix base = create(2, 2);
		base[0][0] = base[0][1] = base[1][0] = 1;
		base[1][1] = 0;
		Matrix tmp = pow(base, n-1);
		fn = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				fn = mmod(fn + tmp[i][j]);
		gn = mmod(mpow(2, n) - fn);
	}

	ll ans = mmod(1);
	for (int i = 0; i < l; ++i)
		if ((k>>i) & 1)
			ans = mmod(ans * gn);
		else
			ans = mmod(ans * fn);
	cout << ans << endl;
	return 0;
}