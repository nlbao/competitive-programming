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


pll solve(ll n, ll d) {
	ll h=0;
	while (((1LL<<(h+1))-1) < n) ++h;

	if (d>h) return mp(0, 0);

	// ll nNode = (1LL<<(h+1))-1;
	ll nLeaf1 = n - ((1LL<<h)-1);
	ll nLeaf2 = (nLeaf1 < (1LL<<h)) ? (1LL<<(h-1)) - (nLeaf1+1)/2 : 0;
	// ll nLeaf = nLeaf1 + nLeaf2;

	ll r0, r1;
	if (d==h) r0 = nLeaf1;
	else r0 = 1LL<<d;

	ll s=nLeaf1, c=h;
	fori(i,1,d) {
		if (c==0) break;
		c >>= 1;
		if (s&1LL) ++s;
		s >>= 1;
	}
	r1 = s;

	if (nLeaf2>0) {
		ll s=nLeaf2, c=h-1;
		fori(i,1,d) {
			if (c==0) break;
			c >>= 1;
			if (s&1LL) ++s;
			s >>= 1;
		}
		if (c>0) r1 += s;
	}

	return pll(r0, r1);
}


int main() {
#ifdef DEBUG
	freopen("BTREEKK.in", "r", stdin);
	freopen("BTREEKK.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		ll n, x;
		cin >> n >> x;
		pll ans=solve(n, x);
		cout << ans.fr << " " << ans.sc << endl;
	}

	return 0;
}