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


int N, J, a[33], len, baseLen;
ll f[11];
set<string> used;
string base;


string aToString() {
	string s = "";
	for (int i = len-1; i >= 0; --i)
		s.push_back(char(int('0') + a[i]));
	return s;
}


ll toBase(ll base) {
	ll ans = 0, p = 1;
	for (int i = 0; i < len; ++i) {
		ans += a[i] * p;
		p *= base;
	}
	return ans;
}


ll findDivisor(ll x) {
	if ((x%2) == 0) return 2;
	for (ll i = 3; i*i <= x; i += 2)
		if ((x%i) == 0) return i;
	return -1;
}


bool check(int x) {
	len = 0;
	while (x > 0) {
		a[len++] = x%2;
		x /= 2;
	}
	for (int i = 2; i < 11; ++i) {
		ll t = toBase(i);
		ll d = findDivisor(t);
		if (d < 0) return 0;
		f[i] = d;
	}
	return 1;
}


void generate(const string &s) {
	if (J<1) return;
	int len = s.size();
	if (len == N) {
		if (used.find(s) != used.end())
			return;
		used.insert(s);
		cout << s << " ";
		for (int i = 2; i < 11; ++i)
			cout << f[i] << " ";
		cout << endl;
		--J;
		return;
	}
	string t = s;
	for (int i = 0; len + i + baseLen <= N; ++i) {
		generate(base + t);
		t = "0" + t;
	}
}


void solve() {
	int m = 1<<min(16, N);
	for (int mask = 1; mask < m; mask += 2) {
		if (J<1) break;
		if (check(mask)) {
			string s = aToString();
			if (used.find(s) != used.end())
				continue;
			base = s;
			baseLen = len;
			generate(s);
		}
	}
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-small-practice.in", "r", stdin);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid<=nTest; ++testid) {
		cout << "Case #" << testid << ":" << endl;
		cin >> N >> J;
		used.clear();
		solve();
	}

	return 0;
}