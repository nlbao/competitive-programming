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


const ll LIMIT = 1e18;


set<ll> q[2];


int main() {
#ifdef DEBUG
	freopen("100796K.in", "r", stdin);
	freopen("100796K.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,1) q[i].clear();
	q[0].insert(1);
	fori(n,1,20) {
		ll x=1;
		fori(i,1,n) x*=i;
		while (1) {
			q[1].clear();
			foreach(it, q[0]) {
				ll y=*it;
				if (y>LIMIT/x) continue;
				y*=x;
				if (has(q[0], y) || has(q[1], y)) continue;
				q[1].insert(y);
			}
			if (q[1].empty()) break;
			foreach(it, q[1]) q[0].insert(*it);
		}
	}

	int nTest=read();
	while (nTest--) {
		ll n;
		cin >> n;
		if (has(q[0], n)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}