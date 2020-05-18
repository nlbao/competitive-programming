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
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


int main() {
#ifdef DEBUG
	freopen("100623K.in", "r", stdin);
	freopen("100623K.out", "w", stdout);
#else
	freopen("key.in", "r", stdin);
	freopen("key.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	vector<ll> ans;
	int n, m;
	ll s=0, a[33];
	cin >> n >> m;
	fori(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	fori(i,1,n) {
		if (m<1) break;
		ll x=a[i];
		while (x>s+1 && m>0) {
			ll t=s+1;
			ans.pb(t);
			s+=t;
			--m;
		}
		s=max(s, s+x);
	}
	while (m>0) {
		ll t=s+1;
		ans.pb(t);
		s+=t;
		--m;
	}
	sort(ans.begin(), ans.end());
	foreach(it, ans) cout << *it << " ";

	return 0;
}