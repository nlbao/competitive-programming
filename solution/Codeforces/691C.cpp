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


vector<int> ans;


int main() {
#ifdef DEBUG
	freopen("691C.in", "r", stdin);
	freopen("691C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	string s;
	cin >> s;

	int n = s.size();
	int dotPos = -1;
	for (int i = 0; i < n; ++i)
		if (s[i] == '.') {
			dotPos = i;
			break;
		}
	if (dotPos == -1) {
		s.push_back('.');
		s.push_back('0');
		dotPos = n;
		n += 2;
	}
	while (s[n-1] == '0') --n;


	bool zero = 1;
	int c = 0;
	for (int i = 0; i < dotPos; ++i) {
		if (s[i] == '0' && zero) continue;
		ans.push_back(s[i]-'0');
		if (!zero) ++c;
		zero = 0;
	}

	if (zero) c = -1;
	for (int i = dotPos+1; i < n; ++i) {
		if (s[i] == '0' && zero) {
			--c;
			continue;
		}
		ans.push_back(s[i]-'0');
		zero = 0;
	}

	if (ans.size() < 1) {
		cout << 0;
		return 0;
	}

	int m = ans.size();
	while (m > 1 && ans[m-1] == 0) --m;
	cout << ans[0];
	if (m > 1) cout << '.';
	for (int i = 1; i < m; ++i)
		cout << ans[i];
	if (c != 0) cout << "E" << c << endl;

	return 0;
}