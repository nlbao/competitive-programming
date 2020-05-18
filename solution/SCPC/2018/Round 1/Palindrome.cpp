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


const int MAX_N = 1e4+44;


int f[MAX_N], len[MAX_N];
vector<int> palins;


bool is_palindrome(int n) {
	string s = to_string(n);
	for (int l = 0, r = s.length()-1; l < r; ++l, --r)
		if (s[l] != s[r])
			return false;
	return true;
}


void init() {
	palins.clear();
	for (int i = 1; i < 10; ++i) {
		palins.push_back(i);
		f[i] = i;
		len[i] = 1;
	}
	for (int i = 10; i < MAX_N; ++i) {
		if (is_palindrome(i)) {
			palins.push_back(i);
			f[i] = i;
			len[i] = 1;
			continue;
		}
		f[i] = -1;
		len[i] = 1e9;
		foreach(it, palins) {
			int p = *it, pre = i-p;
			if (f[pre] > 0) {
				if (f[i] < 0 || len[pre]+1 < len[i]) {
					f[i] = p;
					len[i] = len[pre] + 1;
				}
			}
		}
		// if (len[i] > 3) cout << i << " " << len[i] << endl;
	}
	// cout << palins.size() << endl;
}


void solve(int n) {
	if (n < 10) {
		cout << 1 << " " << n << endl;
		return;
	}
	if (len[n] > 3 || f[n] < 0) {
		cout << 0 << endl;
		return;
	}

	vector<int> ans;
	while (n > 0) {
		ans.push_back(f[n]);
		n -= f[n];
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans.size();
	foreach(it, ans) cout << " " << *it;
	cout << endl;
}


int main() {
#ifdef DEBUG
	freopen("Palindrome.in", "r", stdin);
	freopen("Palindrome.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	init();

	int nTest = read();
	for (int i = 1; i <= nTest; ++i) {
		int n;
		cin >> n;
		cout << "Case #" << i << endl;
		solve(n);
	}

	return 0;
}