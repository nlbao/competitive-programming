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


const int MAX_LEN = 17;


ll p10[MAX_LEN], s8[MAX_LEN];


string to_string(ll n) {
	if (n == 0) return "0";
	string s = "";
	while (n > 0) {
		ll r = n%10;
		n /= 10;
		s.push_back(char(r + int('0')));
	}
	reverse(s.begin(), s.end());
	return s;
}


ll solve(ll source) {
	if (source < 10) return source%2;
	string s = to_string(source);
	int n = s.length();
	bool allEven = true;
	for (int i = 0; i < n; ++i)
		if ((int(s[i])-int('0'))&1) {
			allEven = false;
			break;
		}
	if (allEven) return 0;
	ll ans = 1e18;
	ll pre = 0;
	for (int i = 0; i < n; ++i) {
		int rlen = n-1-i;
		ll x = int(s[i])-int('0');
		ll new_x, target;
		// up
		if (x < 8) {
			new_x = x+1;
			if (new_x&1) ++new_x;
			target = (pre*10+new_x) * p10[rlen];
			ans = min(ans, abs(target-source));
		}
		// down
		if (x > 0) {
			new_x = x-1;
			if (new_x&1) --new_x;
			target = (pre*10+new_x) * p10[rlen] + s8[rlen];
			ans = min(ans, abs(target-source));
		}
		// unchange
		if (x&1) break;
		pre = 10*pre + x;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-practice.in", "r", stdin);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p10[0] = 1;
	s8[0] = 0;
	for (int i = 1; i < MAX_LEN; ++i) {
		p10[i] = p10[i-1] * 10;
		s8[i] = s8[i-1] * 10 + 8;
	}

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		ll n;
		cin >> n;
		cout << "Case #" << testid << ": " << solve(n) << endl;
	}

	return 0;
}