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


map<pii, int> q;
set<pair<pii, int> > s;


int main() {
#ifdef DEBUG
	freopen("PLANEDIV.in", "r", stdin);
	freopen("PLANEDIV.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		q.clear();
		s.clear();
		int n, a, b, c;
		cin >> n;
		while (n--) {
			cin >> a >> b >> c;
			if (a==0 && b==0) continue;
			int d =__gcd(__gcd(abs(a), abs(b)), abs(c));
			if (a<0) d=-d;
			a /= d;
			b /= d;
			c /= d;
			pair<pii, int> p = mp(mp(a, b), c);
			if (s.find(p) != s.end()) continue;
			s.insert(p);

			int g = __gcd(abs(a), abs(b));
			// if (a<0) g=-g;
			a/=g;
			b/=g;
			// ++q[mp(-b,a)];
			pair<int, int> t=mp(-b, a);
			if (q.find(t)==q.end()) q[t]=1;
			else ++q[t];
		}
		int ans=0;
		foreach(it, q) ans=max(ans, it->sc);
		cout << ans << endl;
	}

	return 0;
}