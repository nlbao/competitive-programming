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


ll mMul(ll a, ll b, ll mod) {
	if (!a || !b) return 0;
	if (b==1) return a % mod;
	ll t=mMul(a,b>>1,mod);
	t = (t+t)%mod;
	if (b&1) return (t+a)%mod;
	return t;
}

ll mPow(ll a, ll n, ll mod) {
	if (n < 1) return 1;
	if (n == 1) return a%mod;
	ll result = mPow(a, n>>1, mod);
	result = mMul(result, result, mod);
	if (n&1) result = mMul(result, a, mod);
	return result;
}


bool suspect(ll a, ll s, ll d, ll n) {
	ll x = mPow(a, d, n);
	if (x == 1) return true;
	for (int r = 0; r < s; ++r) {
		if (x == n - 1) return true;
		x = mMul(x, x, n);
	}
	return false;
}

// {2,7,61,-1} is for n < 4759123 141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
	if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
	ll test[] = {2,3,5,7,11,13,17,19,23,-1};
	ll d = n - 1, s = 0;
	while (d % 2 == 0) ++s, d /= 2;
	for (int i = 0; test[i] < n && test[i] != -1; ++i)
		if (!suspect(test[i], s, d, n)) return false;
	return true;
}


bool isSquare(ll val){
	ll x=sqrt(val);
	x=min(x, val/x);
	return x*x == val;
}


int main() {
#ifdef DEBUG
	freopen("GCPC2015_F.in", "r", stdin);
	freopen("GCPC2015_F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll n, ans=1;
	cin >> n;
	ll limit=pow(n, 1/3.0);
	limit=min(limit+3, n);
	for (ll i=2; i<=min(limit, n); ++i) {
		ll c=1;
		while (n%i==0) {
			n /= i;
			++c;
		}
		ans *= c;
	}
	if (n>1) {
		if (isPrime(n)) ans *= 2;
		else if (isSquare(n)) ans *= 3;
		else ans *= 4;
	}
	cout << ans << endl;

	return 0;
}