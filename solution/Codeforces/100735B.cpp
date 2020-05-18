// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {  ll x;   cin >> x;   return x;   }


const ll MODULE=1000000009;

#define mmod(x) ((x)%MODULE)

typedef vector < vector<ll> > Matrix;

Matrix create(int m, int n) {
    return Matrix(m, vector<ll>(n, 0));
}

Matrix mul(const Matrix &a, const Matrix &b) {
	int m=a.size(), n=a[0].size(), p=b[0].size();
	Matrix c = create(m, p);
	fori(i,0,m-1) fori(j,0,p-1) fori(k,0,n-1) {
		c[i][j] = mmod(c[i][j] + a[i][k] * b[k][j]);
	}
    return c;
}

Matrix pow(Matrix &a, ll n) {
	int k=a.size();
	Matrix t = create(k, k);
	fori(i,0,k-1) t[i][i]=1;
	while (n>0) {
		if (n&1) t=mul(t, a);
		a=mul(a, a);
		n >>= 1;
	}
	return t;
}


int main() {
#ifdef DEBUG
    freopen("100735B.in", "r", stdin);
    freopen("100735B.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed, ios::floatfield);

    ll n, pos, nC;
    cin >> n >> pos >> nC;
    Matrix a = create(n, 1);
    Matrix base = create(n, n);
    fori(i,1,n) cin >> a[i-1][0];
    fori(i,1,nC) {
        int x;
        cin >> x;
        base[n-1][n-x]=1;
    }
    fori(i,0,n-2) base[i][i+1]=1;
    if (pos<=n) {
        cout << a[pos-1][0] << endl;
        return 0;
    }

    Matrix t = pow(base, pos-n);
    ll ans=0;
    fori(i,0,n-1) ans = mmod(ans + mmod(a[i][0] * t[n-1][i]));
    cout << ans << endl;

    return 0;
}