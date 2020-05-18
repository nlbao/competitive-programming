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


const int MAX_N = 1e7+66666;


vector<pll> ans;


int main() {
#ifdef DEBUG
	freopen("599D.in", "r", stdin);
	freopen("599D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll x, s2=0;
	cin >> x;
	fori(i,1,MAX_N-1) {
		ll t = i*i;
		s2 += t;
		ll a=i*(i+1)/2, b=x-s2+t*(i+1)/2;
		if (b>0 && (b%a)==0) {
			ll j=b/a;
			if (j>=i) {
				ans.pb(mp(i, j));
				if (j>i) ans.pb(mp(j, i));
			}
		}
	}

	sort(all(ans));
	int k = sz(ans);
	cout << k << endl;
	foreach(it, ans) cout << it->fr << " " << it->sc << endl;

	return 0;
}