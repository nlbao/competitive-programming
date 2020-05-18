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


int n, ans;
string s;


inline void change(char &x) {
	if (x == '-') x = '+';
	else x = '-';
}


void flip(int x, int y) {
	for (int i = x; i <= y; ++i)
		change(s[i]);
	for (int i=x, j=y; i<j; ++i, --j) {
		// change(s[i]);
		// change(s[j]);
		swap(s[i], s[j]);
	}
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cout << "Case #" << testid << ": ";
		cin >> s;
		n = s.size();
		ans = 0;
		for (int i = n-1; i > 0; --i) {
			if (s[i] == '+') continue;
			if (s[0] == '+') {
				s[0] = '-';
				++ans;
			}
			flip(0, i);
			++ans;
		}
		if (s[0] == '-') ++ans;
		cout << ans << endl;
	}

	return 0;
}