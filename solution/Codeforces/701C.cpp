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


const int MAX_N = 1e5+55;
const int MAX_X = 26*2 + 4;


int n, nPoke;
string s;
int c[MAX_N][MAX_X];


int toNum(char x) {
	return (x < 'a') ? x-'A' : x-'a'+26;
}


int solve(int i, int j) {
	int ans = 0;
	for (int x = 0; x < MAX_X; ++x)
		if (c[j][x]-c[i-1][x] > 0)
			++ans;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("701C.in", "r", stdin);
	freopen("701C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	cin >> s;
	filla(c, 0);
	for (int i = 0; i < n; ++i) {
		for (int x = 0; x < MAX_X; ++x)
			c[i+1][x] = c[i][x];
		++c[i+1][toNum(s[i])];
	}
	nPoke = 0;
	for (int x = 0; x < MAX_X; ++x)
		if (c[n][x] > 0) ++nPoke;

	int ans = n;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = min(n-i+1, ans-1);
		while (l <= r) {
			int mid = (l+r)>>1;
			if (solve(i, i+mid-1) == nPoke) {
				ans = min(ans, mid);
				r = mid-1;
			}
			else l = mid+1;
		}
	}
	cout << ans << endl;


	return 0;
}