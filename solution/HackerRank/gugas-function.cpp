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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6+6;
const ll MOD = 1e9+9;

int f[MAX_N];


ll mmod(ll x) {
	x%=MOD;
	if (x<0) x+=MOD;
	return x;
}

ll mpow(ll x, ll n) {
	if (n<1) return 1;
	if (n==1) return mmod(x);
	ll t=mpow(x,n>>1);
	t=mmod(t*t);
	if (n&1) t=mmod(t*x);
	return t;
}


int main() {
#ifdef DEBUG
	freopen("gugas-function.in", "r", stdin);
	freopen("gugas-function.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=read(), ans=0;
	filla(f, 0);
	f[3]=1;
	if (n>=3) ans=1;
	int j=1, s = mpow(2, 0);
	fori(i,4,n) {
		++j;
		s = mmod(1LL*s + f[j] + mpow(2, j-1));
		f[i] = mmod(1LL*f[i-1] + s);
		ans = mmod(ans + f[i]);
	}
	cout << ans << endl;

	return 0;
}