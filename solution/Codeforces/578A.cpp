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


double a, b;


double solve() {
	double ans=-10000;
	if (ll(a)==ll(b))
		ans=a;
	//x=(a+b)/2k
	ll t=floor((a+b)/b);
	if ((t%2)!=0) --t;
	if (t>0) {
		if (ans<0) ans=(a+b)/t;
		else ans=min(ans, (a+b)/t);
	}
	//x=(b-a)/2k
	if (b>a) {
		t=floor((b-a)/b);
		if ((t%2)!=0) --t;
		if (t>0) {
			if (ans<0) ans=(b-a)/t;
			else ans=min(ans, (b-a)/t);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("578A.in", "r", stdin);
	freopen("578A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> a >> b;
	double ans=solve();
	if (ans<0) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}