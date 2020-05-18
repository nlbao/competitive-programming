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


const int MAX_N = 1e6+66;


int L, N, M;
ll D, w[MAX_N];
set<pll> h1, h2;


ll solve() {
	ll ans=0;
	M = min(M, L);
	h1.clear();
	h2.clear();
	fori(i,1,N) h1.insert(mp(w[i], i));
	fori(i,1,M) h2.insert(mp(0, i));
	fori(i,1,L) {
		// wash
		pll p = *h1.begin();
		h1.erase(h1.begin());
		ll t = p.fr;
		p.fr += w[p.sc];
		h1.insert(p);
		// dry
		p = *h2.begin();
		h2.erase(h2.begin());
		t = max(t, p.fr) + D;
		p.fr = t;
		h2.insert(p);
		// update
		ans = max(ans, t);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("laundro_matt_example.in", "r", stdin);
	freopen("laundro_matt_example.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> L >> N >> M >> D;
		fori(i,1,N) cin >> w[i];
		ll ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}