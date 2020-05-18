#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6 + 2*1e5;
const int LIMIT = MAX_N-10;


bool ok[MAX_N];
string s;


inline bool isPalin(int x) {
	stringstream ss;
	ss << x;
	ss >> s;
	int n = s.length();
	for (int i = 0, j = n-1; i < j; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("568A.in", "r", stdin);
	freopen("568A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	ll p, q;
	cin >> p >> q;
	int ans = -1;
	ll sa = 0, sb = 0;
	filla(ok, true);
	ok[1] = false;
	for (int i = 1; i < MAX_N; ++i) {
		if (isPalin(i)) ++sb;
		if (ok[i]) {
			++sa;
			for (ll j = 1LL*i*i; j < MAX_N; j += i)
				ok[j] = false;
		}
		if (q*sa <= p*sb)
			ans = max(ans, i);
		// if (q*sa <= p*sb) cout << "	" << i << " " << sa << " " << sb << endl;
	}

	if (ans >= LIMIT) ans = -1;

	if (ans < 0) cout << "Palindromic tree is better than splay tree\n";
	else cout << ans << '\n';
	return 0;
}