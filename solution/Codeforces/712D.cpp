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


const int LIMIT = 2e5+205;
const int OFFSET = 1e5+1;
const ll MODULE = 1e9+7;


int A, B, K, T, t, tt;
ll c[2][LIMIT], s[2][LIMIT], ca[LIMIT], cb[LIMIT], sa[LIMIT], sb[LIMIT];


inline ll mmod(ll x) {
	x %= MODULE;
	while (x < 0) x += MODULE;
	return x % MODULE;
}


inline ll get(int l, int r) {
	r = min(r, LIMIT-1);
	if (l < 0) return s[tt][r];
	return mmod(s[tt][r] - s[tt][l]);
}


void cal(int initValue) {
	initValue += OFFSET;
	filla(c, 0);
	filla(s, 0);
	t = 0;
	c[t][initValue] = 1;
	for (int i = initValue; i < LIMIT; ++i)
		s[t][i] = 1;
	for (int turn = 1; turn <= T; ++turn) {
		tt = t;
		t ^= 1;
		c[t][0] = s[t][0] = 0;
		for (int i = 1; i < LIMIT; ++i) {
			c[t][i] = get(i-K-1, i+K);
			s[t][i] = mmod(s[t][i-1] + c[t][i]);
		}
	}
}


ll solve() {
	cal(A);
	for (int i = 0; i < LIMIT; ++i)
		ca[i] = c[t][i], sa[i] = s[t][i];
	cal(B);
	for (int i = 0; i < LIMIT; ++i)
		cb[i] = c[t][i], sb[i] = s[t][i];
	ll ans = 0;
	for (int i = 1; i < LIMIT; ++i)
		ans = mmod(ans + mmod(ca[i] * sb[i-1]));
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("712D.in", "r", stdin);
	freopen("712D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> A >> B >> K >> T;
	cout << solve() << endl;

	return 0;
}