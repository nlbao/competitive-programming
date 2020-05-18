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


const int MAX_N = 1e5+55;


int a[MAX_N];
multiset<int> minS;
multiset<int, greater<int> > maxS;


int main() {
#ifdef DEBUG
	freopen("602B.in", "r", stdin);
	freopen("602B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	cin >> n;
	fori(i,1,n) cin >> a[i];
	int ans=1, j=1;
	fori(i,1,n) {
		minS.insert(a[i]);
		maxS.insert(a[i]);
		while (j<i && *maxS.begin()-*minS.begin() > 1) {
			minS.erase(minS.find(a[j]));
			maxS.erase(maxS.find(a[j]));
			++j;
		}
		ans = max(ans, int(i-j+1));
	}
	cout << ans << endl;

	return 0;
}