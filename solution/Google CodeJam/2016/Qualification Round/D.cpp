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


int K, S, C;
vector<ll> ans;


bool solve() {
	if (S*C < K) return 0;
	ans.clear();
	for (int i = 1; i <= K; i += C) {	// start of the interval to be covered: (i, i+1, ..., i+C-1)
		ll p = i;						// p covers i
		for (int d = 1; d < C; ++d) {	// level
			p = (p-1)*K + min(i+d, K);	// now p = position at (d+1)-th level,
										// and p covers (i, i+1, ..., i+d)
		}
		ans.push_back(p);
	}
	for (int i = 0, sz = ans.size(); i < sz; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 1;
}


int main() {
#ifdef DEBUG
	// freopen("D.in", "r", stdin);
	// freopen("D-small-practice.in", "r", stdin);
	freopen("D-large-practice.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int tid = 1; tid <= nTest; ++tid) {
		cout << "Case #" << tid << ": ";
		cin >> K >> C >> S;
		if (!solve()) cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}