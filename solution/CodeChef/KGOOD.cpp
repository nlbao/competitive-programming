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


const int N_CHAR = 26;

int c[N_CHAR], tmp[N_CHAR], K;
string s;


int solve() {
	int ans = 0;
	while (1) {
		int minI = -1, maxI = -1;
		for (int i = 0; i < N_CHAR; ++i) if (c[i] > 0) {
			if (maxI < 0 || c[i] > c[maxI]) maxI = i;
			if (minI < 0 || c[i] < c[minI]) minI = i;
		}
		if (maxI < 0 || minI < 0) break;
		if (c[maxI] - c[minI] <= K) break;
		int t = (c[maxI]-c[minI]) - K;
		c[maxI] -= t;
		ans += t;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("KGOOD.in", "r", stdin);
	freopen("KGOOD.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> s >> K;
		filla(c, 0);
		int n = s.size();
		for (int i = 0; i < n; ++i)
			++c[s[i]-'a'];
		sort(c, c+N_CHAR);

		int ans = n, add = 0;
		for (int pos = 0; pos < N_CHAR; ++pos) if (c[pos] > 0) {
			for (int i = 0; i < N_CHAR; ++i) tmp[i] = c[i];
			ans = min(ans, solve() + add);
			for (int i = 0; i < N_CHAR; ++i) c[i] = tmp[i];
			add += c[pos];
			c[pos] = 0;
		}
		cout << ans << endl;
	}

	return 0;
}