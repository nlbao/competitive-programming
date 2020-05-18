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


const int MAX_N = 2022;


int n;
ll x[MAX_N], y[MAX_N];
map<ll, ll> q;


int main() {
#ifdef DEBUG
	freopen("boomerangConstellations.in", "r", stdin);
	freopen("boomerangConstellations.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) cin >> x[i] >> y[i];
		ll ans=0;
		fori(i,1,n) {
			q.clear();
			fori(j,1,n) if (j!=i) {
				ll d=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
				++q[d];
			}
			foreach(it, q) {
				ll x=it->sc;
				ans += x*(x-1)/2;
			}
		}
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}