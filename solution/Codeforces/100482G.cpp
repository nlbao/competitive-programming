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
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const ll MOD = 1000000007;


ll mpow(ll x, ll n) {
	if (n<1) return 1;
	if (n==1) return x;
	ll t=mpow(x,n>>1);
	t=(t*t)%MOD;
	if (n&1) return (t*x)%MOD;
	return t;
}


map<ll, ll> q;


int main() {
#ifdef DEBUG
	freopen("100482G.in", "r", stdin);
	freopen("100482G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		q.clear();
		int n;
		cin >> n;
		fori(i,1,n) {
			ll x;
			cin >> x;
			if (q.find(x)==q.end()) q[x]=1;
			else ++q[x];
		}
		ll ans=0;
		foreach(it, q) {
			ll x=it->fr;
			ll y=mpow(x,MOD-2);
			if (y>x) continue;
			if (y==x) ans += it->sc/2;
			else {
				map<ll,ll>::iterator p=q.find(y);
				if (p!=q.end()) {
					ans+=min(it->sc, p->sc);
				}
			}
		}
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}