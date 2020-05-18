// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

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


const int MAX_N = 2e5 + 5;
const double EPS = 1e-9;


int m;
pdi a[MAX_N];
int ans[MAX_N];


bool is_equal(double a, double b) {
	return fabs(a-b) <= EPS;
}


double parse(const string& s) {
	double x = 0, y = 0, z = 0;
	bool foundX = false, foundY = false, foundZ = false;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		char ch = s[i];
		if (isdigit(ch)) {
			double val = int(ch) - int('0');
			if (!foundX) x = x*10 + val;
			else if (!foundY) y = y*10 + val;
			else if (!foundZ) z = z*10 + val;
		}
		else {
			if (ch == '(' || ch == '/') continue;
			if (!foundX) foundX = true;
			else if (!foundY) foundY = true;
			else if (!foundZ) foundZ = true;
		}
	}
	return (x+y)/z;
}


int main() {
#ifdef DEBUG
	freopen("958D1.in", "r", stdin);
	freopen("958D1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> m;
	string s;
	for (int i = 0; i < m; ++i) {
		cin >> s;
		a[i] = pdi(parse(s), i);
		// cout << a[i].first << endl;
	}

	filla(ans, 0);
	sort(a, a+m);
	// return 0;
	for (int i = 0, j = 0; i < m; i = j) {
		double last = a[j].first;
		while (j < m && is_equal(a[j].first, last))
			++j;
		int len = j-i;
		for (int k = i; k < j; ++k)
			ans[a[k].second] = len;
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << " ";

	return 0;
}