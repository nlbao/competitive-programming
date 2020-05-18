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


const int MAX_N = 2e5+5;

int n, m;
ll k, km;
ll a[MAX_N], l[MAX_N], r[MAX_N];


ll solve(int pos) {
	ll ans = a[pos]*km;
	if (pos > 0) ans |= l[pos-1];
	if (pos < n-1) ans |= r[pos+1];
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("SimpleGame.in", "r", stdin);
	freopen("SimpleGame.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	km = 1;
	for (int i = 0; i < m; ++i)
		km *= k;

	l[0] = a[0];
	for (int i = 1; i < n; ++i)
		l[i] = l[i-1] | a[i];
	r[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i)
		r[i] = r[i+1] | a[i];

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, solve(i));
	cout << ans << endl;

	return 0;
}