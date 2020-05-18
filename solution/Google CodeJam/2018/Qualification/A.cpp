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


ll damageLimit;
string pattern;


ll cal_damage(const string &s) {
	ll ans = 0, nCharge = 0;
	int n = s.length();
	for (int i = 0; i < n; ++i)
		if (s[i] == 'S') ans += (1LL<<nCharge);
		else ++nCharge;
	// cout << s << " " << ans << endl;
	return ans;
}


// int solve_visible_tests() {
// 	if (cal_damage(pattern) <= damageLimit) return 0;
// 	int n = pattern.length(), cPos = 1e9, ans = 0;
// 	for (int i = 0; i < n; ++i)
// 		if (pattern[i] == 'C') {
// 			cPos = i;
// 			break;
// 		}
// 	while (cPos < n-1) {
// 		swap(pattern[cPos], pattern[cPos+1]);
// 		++cPos, ++ans;
// 		if (cal_damage(pattern) <= damageLimit)
// 			return ans;
// 	}
// 	return -1;
// }


int solve_hide_tests() {
	if (cal_damage(pattern) <= damageLimit) return 0;
	int n = pattern.length(), cnt = 0;
	bool stop = false;
	while (!stop) {
		stop = true;
		for (int i = n-2; i >= 0; --i)
			if (pattern[i] == 'C' && pattern[i+1] == 'S') {
				stop = false;
				swap(pattern[i], pattern[i+1]);
				++cnt;
				if (cal_damage(pattern) <= damageLimit)
					return cnt;
				break;
			}
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> damageLimit >> pattern;
		// int ans = solve_visible_tests();
		int ans = solve_hide_tests();
		cout << "Case #" << testid << ": ";
		if (ans < 0) cout << "IMPOSSIBLE\n";
		else cout << ans << endl;
	}

	return 0;
}