#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 2e5+55;


ll a[MAX_N], l[MAX_N], r[MAX_N];


int main() {
#ifdef DEBUG
	freopen("578B.in", "r", stdin);
	freopen("578B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n, k;
	ll x;
	cin >> n >> k >> x;
	fori(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);

	l[0]=r[n+1]=0;
	fori(i,1,n) l[i]=l[i-1]|a[i];
	ford(i,n,1) r[i]=r[i+1]|a[i];

	ll ans=0;
	fori(i,1,n) {
		ll t=a[i];
		fori(i,1,k) t*=x;
		t|=l[i-1];
		t|=r[i+1];
		ans=max(ans, t);
	}
	cout << ans << endl;

	return 0;
}