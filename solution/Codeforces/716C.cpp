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


const int MAX_N = 1e6+5;


int n, nA;
bool isPrime[MAX_N];
int d[MAX_N];
vector<int> a, cnt1, cnt2;
vector<ll> tmp1, tmp2;


ll lcm(ll x, ll y) {
	ll g = __gcd(x, y);
	return (x / g) * y;
}


inline bool isSqr(ll x) {
	ll y = sqrt(x);
	return y*y == x;
}


// ll toSqr_0(ll x, ll k) {
// 	ll ans = x;
// 	while (!isSqr(ans) || (ll(sqrt(ans))%(k+1) != 0)) ans += x;
// 	return ans;
// }


void toSqr(ll x) {
	tmp1.clear();
	cnt1.clear();
	for (int i = 0; i < nA; ++i) {
		ll d = a[i];
		if (d*d > x) break;
		if ((x%d) == 0) {
			ll c = 0;
			while ((x%d) == 0) {
				x /= d;
				++c;
			}
			if (c&1) ++c;
			tmp1.push_back(d);
			cnt1.push_back(c);
		}
	}
}


void totmp2(ll x) {
	tmp2.clear();
	cnt2.clear();
	for (int i = 0; i < nA; ++i) {
		ll d = a[i];
		if (d*d > x) break;
		if ((x%d) == 0) {
			ll c = 0;
			while ((x%d) == 0) {
				x /= d;
				++c;
			}
			tmp2.push_back(d);
			cnt2.push_back(c);
		}
	}
}


ll divide() {
	ll ans = 1;
	int m = tmp2.size();
	for (int i = 0, j = 0; i < (int)tmp1.size(); ++i) {
		if (j >= m) {
			ans *= pow(tmp1[i], cnt1[i]);
			continue;
		}
		ll x = tmp1[i], y = tmp2[j];
		if (x < y) ans *= pow(x, cnt1[i]);
		else {
			if (x == y) ans *= pow(x, cnt1[i] - cnt2[i]);
			++j;
		}
	}
	return ans;
}


void solve() {
	ll p = 2;
	for (ll k = 1; k <= n; ++k) {
		// ll g = __gcd(p*k, k+1);
		// ll x = ((k+1) / g) * (p*k);
		ll x = lcm(k, (k+1)*(k+1));
		// ll m = toSqr(x);
		// // ll m = toSqr_0(x, k);
		// ll t = m / k;


		toSqr(x);
		totmp2(k);
		ll t = divide();

		ll ans = t - p;
		// cout << ans << endl;
		p = ll(sqrt(m)) / (k+1);
		// cout << "		" << k+1 << " " << (k+1)*p << ", " << m << " " << g << " " << x << endl;
		// cout << "		" << k+1 << " " << p << ", " << m << " " << x << endl;
		// cout << t << endl;
	}
}


int main() {
#ifdef DEBUG
	freopen("716C.in", "r", stdin);
	freopen("716C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(isPrime, 1);
	isPrime[1] = 0;
	for (int i = 2; i < MAX_N; ++i) if (isPrime[i]) {
		d[i] = i;
		a.push_back(i);
		for (int j = i+i; j < MAX_N; j += i)
			isPrime[j] = 0, d[j] = i;
	}
	nA = a.size();

	cin >> n;
	solve();

	return 0;
}