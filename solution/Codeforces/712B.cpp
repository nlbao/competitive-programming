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

int solve() {
	int n = s.size();
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') ++y;
		else if (s[i] == 'D') --y;
		else if (s[i] == 'L') --x;
		else ++x;
	}
	x = abs(x);
	y = abs(y);
	if (x < y) swap(x, y);
	if ((x%2) != (y%2)) return -1;
	int ans = (x-y)/2;
	ans += y;
	return ans;
}

int main() {
#ifdef DEBUG
	freopen("712B.in", "r", stdin);
	freopen("712B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> s;
	cout << solve() << endl;

	return 0;
}