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


bool isSameCase(char x, char y) {
	if (x > y) swap(x, y);
	if (x < 'a' && y >= 'a') return 0;
	return 1;
}


char reflect(char x) {
	if (x == 'o' || x == 'O' || x == 'H' || x == 'A' || x == 'I' || x == 'M') return x;
	if (x == 'T' || x == 'U' || x == 'V' || x == 'v' || x == 'W' || x == 'w' || x == 'Y') return x;
	if (x == 'x' || x == 'X') return x;
	// if (x == 'm') return x;
	if (x == 'b') return 'd';
	if (x == 'd') return 'b';
	if (x == 'p') return 'q';
	if (x == 'q') return 'p';
	return '-';
}


bool solve() {
	int n = s.size();
	for (int i = 0, j = n-1; i <= j; ++i, --j) {
		if (!isSameCase(s[i], s[j])) return 0;
		if (reflect(s[j]) != s[i]) return 0;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("691B.in", "r", stdin);
	freopen("691B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> s;
	if (solve()) cout << "TAK";
	else cout << "NIE";

	return 0;
}