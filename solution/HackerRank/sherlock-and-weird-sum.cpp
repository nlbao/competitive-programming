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


int len;
ll n, m;
string a, b, c;


inline char toChar(int x) {
	return char(x + '0');
}


string toString(ll x) {
	string s = "";
	while (x > 0) {
		s = toChar(x%10) + s;
		x /= 10;
	}
	if (s == "") s = "0";
	return s;
}


ll getSum() {
	ll s = 0;
	for (int i = 0; i < len; ++i)
		s = 10LL*s + c[i] - '0';
	return s;
}


ll solve() {
	len = max(a.length(), b.length());
	while ((int)a.length() < len) a = "0" + a;
	while ((int)b.length() < len) b = "0" + b;
	ll ans = 0;
	c = "";
	for (int i = 0; i < len; ++i) c += "9";
	for (int i = 0; i < len; ++i) {
		int la = a[i]-'0', lb = b[i]-'0';
		for (int x = 0; x <= la; ++x)
			for (int y = 0; y <= lb; ++y)
				if (x != la || y != lb) {
					c[i] = toChar((x+y)%10);
					ans = max(ans, getSum());
				}
		c[i] = toChar((la+lb)%10);
	}
	ans = max(ans, getSum());
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("sherlock-and-weird-sum.in", "r", stdin);
	freopen("sherlock-and-weird-sum.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%lld%lld", &n, &m);
		a = toString(n);
		b = toString(m);
		printf("%lld\n", solve());
	}
	return 0;
}