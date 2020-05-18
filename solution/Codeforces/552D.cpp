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


const int MAX_N = 2004;


int n;
int x[MAX_N], y[MAX_N];
map<pii, int> c;


inline void fix(int &a, int &b) {
	ll d = __gcd(a, b);
	a /= d, b /= d;
}


ll solve() {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		c.clear();
		for (int j = 0; j < i; ++j) {
			int a = x[j]-x[i], b = y[j]-y[i];
			fix(a, b);
			++c[pii(a, b)];
		}
		for (int j = i+1; j < n; ++j) {
			int a = x[j]-x[i], b = y[j]-y[i];
			fix(a, b);
			ans += i - c[pii(a, b)];
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("552D.in", "r", stdin);
	freopen("552D.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i) {
		x[i] = read();
		y[i] = read();
	}
	cout << solve();
	return 0;
}