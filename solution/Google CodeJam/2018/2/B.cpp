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


const int MAX_N = 555;


int R, B;


int calLength(int n) {
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		n -= i;
		++ans;
	}
	return ans;
}


int solve() {
	int ans = 0;
	if (R == 0 && B == 0) return 0;
	if (R == 0) {
		for (int i = 1; B >= i; ++i) {
			++ans;
			B -= i;
		}
		return ans;
	}

	int maxVal = 0;
	bool okMaxVal = true;
	while (R > 0 && B > 0) {
		++maxVal;
		okMaxVal = false;
		for (int i = 0; i < maxVal; ++i) {
			if (i <= R && maxVal <= B) {
		        // (i, maxVal)
				R -= i;
				B -= maxVal;
				++ans;
			}
			if (i <= B && maxVal <= R) {
		        // (maxVal, i)
				R -= maxVal;
				B -= i;
				++ans;
			}
			if (R > B) {
				swap(R, B);
				// break;
			}
			okMaxVal = true;
		}
	}
	if (okMaxVal) ++maxVal;
	while (maxVal <= B) {
		B -= maxVal;
		++ans;
		++maxVal;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> R >> B;
		if (R > B) swap(R, B);
		int ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}