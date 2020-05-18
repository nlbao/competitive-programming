#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


inline string getString(ll n) {
	string ans = "";
	while (n > 0) {
		ans = char('0' + n%10) + ans;
		n /= 10;
	}
	if (ans == "") ans = "0";
	return ans;
}


inline ll mpow(ll x, int d) {
	ll ans = 1;
	for (int i = 0; i < d; ++i)
		ans *= x;
	return ans;
}


ll cal(ll len) {
	if (len == 1) return 9;
	return len * 9LL * mpow(10, len-1);
}


ll solve(ll n) {
	if (n < 1) return 0;
	if (n < 10) return n;
	ll ans = 0;
	string s = getString(n);
	int len = s.length();
	for (int i = 0; i < len; ++i)
		ans += cal(i);

	for (int i = 0; i < len; ++i) {
		int x = s[i] - '0';
		int l = (i == 0) ? 1 : 0;
		int t = len-i-1;
		ll p = mpow(10, t);
		for (int v = l; v < x; ++v)
			ans += p * len;
	}
	ans += len;

	return ans;
}


int main() {
#ifdef DEBUG
	freopen("552B.in", "r", stdin);
	freopen("552B.out", "w", stdout);
#endif
	int n = read();
	cout << solve(n);
	return 0;
}