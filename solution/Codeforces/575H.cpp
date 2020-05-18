#pragma comment(linker, "/STACK:1024000000")
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

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 2e6 + 6;
const ll MODULE = 1e9+7;


ll f[MAX_N], inv[MAX_N];


// inline ll mmod(ll x) {
// 	if (abs(x) > MODULE) x %= MODULE;
// 	if (x < 0) x += MODULE;
// 	return x;
// }
#define mmod(x) ((x)%MODULE)

ll mpow(ll a, ll n) {
	if (n<1) return 1;
	if (n==1) return mmod(a);
	ll t=mpow(a,n>>1);
	t = mmod(t*t);
	if (n&1) return mmod(t*a);
	return t;
}

inline ll calC(ll n, ll k) {
	if (n<0 || k<0 || k>n) return 0;
	if (k==0 || k==n) return 1;
	ll ans=f[n];
	ans = mmod(ans * inv[k]);
	ans = mmod(ans * inv[n-k]);
	return ans;
}


ll solve_0(ll x, ll y) {
	if (x==0 || y==0) return x+y+1;
	return solve_0(x-1, y) + solve_0(x, y-1) + 1;
}



ll solve_1(ll x, ll y) {
	if (y==0) return x+1;
	if (x==1 && y==1) return 5;
	if (y==1) return mmod(solve_1(x-1, 1) + solve_1(x, 0) + 1);
	return mmod(2LL * solve_1(x, y-1) + 1);
}


int main() {
#ifdef DEBUG
	freopen("575H.in", "r", stdin);
	freopen("575H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll n;
	cin >> n;

	// f[0]=1, inv[0]=1;
	// fori(i,1,MAX_N-1) {
	// 	f[i]=mmod(f[i-1]*i);
	// 	inv[i]=mpow(f[i], MODULE-2);
	// }

	// ll ans=0, p=1;

	// ll x = calC(n*2, n);
	// fori(i,0,n) {
	// 	ans = mmod(ans+p);
	// 	p = mmod(p*2);
	// }
	// fori(i,1,n) ans = mmod(ans+x);
	// cout << ans << endl;
	cout << solve_0(n, n) << endl;
	cout << solve_1(n, n) << endl;

	cout << solve_1(2, 1) << endl;
	cout << solve_1(1, 1) << endl;
	cout << solve_1(2, 0) << endl;

	return 0;
}