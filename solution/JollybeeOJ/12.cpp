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


int main() {
#ifdef DEBUG
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	map<ll, int> q;
	int nTest=read();
	fori(testid,1,nTest) {
		int n;
		cin >> n;
		q.clear();
		q[0]=1;
		ll ans=0, s=0, x;
		while (n--) {
			cin >> x;
			s ^= x;
			map<ll, int>::iterator it = q.find(s);
			if (it!=q.end()) {
				ans += it->sc;
				++it->sc;
			}
			else q[s]=1;
		}
		cout << "Case #" << testid << ": " << ans;
		if (testid<nTest) cout << endl;
	}

	return 0;
}