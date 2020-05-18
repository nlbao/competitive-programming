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


const int MAX_N = 16;


int n;
string a[MAX_N], b[MAX_N];
set<string> qa, qb;


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		int ans = 0, m = 1<<n;
		for (int mask = 0; mask < m; ++mask) {
			qa.clear();
			qb.clear();
			for (int i = 0; i < n; ++i) if (mask&(1<<i)) {
				qa.insert(a[i]);
				qb.insert(b[i]);
			}
			bool ok = 1;
			int cnt = 0;
			for (int i = 0; i < n; ++i) if (!(mask&(1<<i))) {
				ok &= qa.find(a[i]) != qa.end();
				ok &= qb.find(b[i]) != qb.end();
				if (!ok) break;
				++cnt;
			}
			if (ok) ans = max(ans, cnt);
		}
		cout << "Case #" << tid << ": " << ans << endl;
	}

	return 0;
}