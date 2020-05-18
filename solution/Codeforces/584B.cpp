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


const ll MOD = 1e9+7;


ll mpow(ll x, ll n) {
	if (n<1) return 1;
	if (n==1) return x%MOD;
	ll t=mpow(x,n>>1);
	t=(t*t)%MOD;
	if (n&1) return (t*x)%MOD;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("584B.in", "r", stdin);
	freopen("584B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll n;
	cin >> n;
	ll c=0;
	fori(i,1,3) fori(j,1,3) fori(k,1,3) if (i+j+k==6) ++c;
	ll x=mpow(27, n) - mpow(c, n);
	x%=MOD;
	if (x<0) x+=MOD;
	cout << x << endl;

	return 0;
}