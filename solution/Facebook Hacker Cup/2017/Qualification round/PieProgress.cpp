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


const int MAX_N = 333;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("PieProgress.in", "r", stdin);
	freopen("PieProgress.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid<=nTest; ++testid) {
		ll ans = 0;
		int n, m;
		cin >> n >> m;
		multiset<ll> heap;
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < m; ++k)
				cin >> a[k];
			sort(a, a+m);
			for (int k = 0; k < m; ++k) {
				ll cost = a[k] + sqr(k+1) - sqr(k);
				heap.insert(cost);
			}
			// eat one pie
			ans += *heap.begin();
			heap.erase(heap.begin());
		}
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}