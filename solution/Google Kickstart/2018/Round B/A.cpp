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


const int MAX_LEN = 19;
const ll MOD = 9;


ll f[MAX_LEN][10];


void init() {
	for (int i = 0; i < MAX_LEN; ++i)
		for (int r = 0; r < 9; ++r)
			f[i][r] = 0;
	f[0][0] = 1;
	for (int len = 1; len < MAX_LEN; ++len) {
		for (int r = 0; r < 9; ++r)
			for (int x = 0; x < 9; ++x) {
				int rr = (r+x)%MOD;
				f[len][rr] += f[len-1][r];
			}
	}
}


ll fcnt(ll n) {
	if (n < 1) return 0;
	ll ans = 0;
	string s = to_string(n);
	int len = s.length();
	// length < len
	for (int r = 1; r < MOD; ++r)
		ans += f[len-1][r];
	// length == len
	int k = 0;
	for (int i = 0; i < len; ++i) {
		int i_val = int(s[i]) - int('0');
		for (int x = (i == 0) ? 1 : 0; x < i_val; ++x) {
			int kk = (k+x) % MOD;
			for (int r = 0; r < 9; ++r) {
				int kkk = (kk+r) % MOD;
				if (kkk != 0)
					ans += f[len-i-1][r];
			}
		}
		if (i_val == 9) break;
		k = (k + i_val) % MOD;
		if (i == len-1 && k != 0) ++ans;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	init();

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		ll b, e;
		cin >> b >> e;
		ll ans = fcnt(e) - fcnt(b-1);
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}