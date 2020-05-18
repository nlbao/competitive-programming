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


const int MAX_N = 2525;
const ll MOD = 1e9+7;


int n, m;
int a[MAX_N][MAX_N], f[MAX_N][MAX_N];


inline ll mmod(ll x) {
	if (x>=MOD) x %= MOD;
	return x;
}


inline void update(int x, int y, ll val) {
	for (int i=x; i<=n; i+=lowbit(i))
		for (int j=y; j<=m; j+=lowbit(j))
			f[i][j] = mmod(f[i][j]+val);
}


inline ll get(int x, int y) {
	ll ans = 0;
	for (int i=x; i>0; i-=lowbit(i))
		for (int j=y; j>0; j-=lowbit(j))
			ans = mmod(ans+f[i][j]);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("travel-in-byteland.in", "r", stdin);
	freopen("travel-in-byteland.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,n) fori(j,1,m) cin >> a[i][j];

	ll ans;
	filla(f, 0);
	fori(i,1,n) fori(j,1,m) {
		if (i==1 && j==1) ans = a[i][j];
		else ans = mmod(get(i, j) * a[i][j]);
		update(i, j, ans);
	}
	cout << ans << endl;

	return 0;
}