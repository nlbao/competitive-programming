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


string s;
int n;
ll L, R;


inline ll isBlue(ll x) {
	return s[x%n] == 'B';
}


ll solve() {
	ll ans = 0;
	while (L<=R && (L%n != 0)) {
		ans += isBlue(L);
		++L;
	}
	while (R>=L && (R%n != n-1)) {
		ans += isBlue(R);
		--R;
	}
	if (L>R) return ans;
	ll k = (R-L+1)/n, c = 0;
	for (int i = 0; i < n; ++i)
		c += isBlue(i);
	ans += k*c;
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> s;
		n = s.size();
		cin >> L >> R;
		--L, --R;
		cout << "Case #" << testid << ": " << solve() << endl;
	}

	return 0;
}