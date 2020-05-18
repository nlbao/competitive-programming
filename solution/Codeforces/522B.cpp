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
#define fr first
#define sc second

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 2e5 + 5;


int h[MAX_N], w[MAX_N], l[MAX_N], r[MAX_N];


int main() {
#ifdef DEBUG
	freopen("522B.in", "r", stdin);
	freopen("522B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int n = read(), s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> h[i];
		s += w[i];
	}
	l[0] = 0;
	for (int i = 1; i <= n; ++i)
		l[i] = max(l[i-1], h[i]);
	r[n+1] = 0;
	for (int i = n; i >= 1; --i)
		r[i] = max(r[i+1], h[i]);
	for (int i = 1; i <= n; ++i) {
		ll a = s-w[i];
		ll b = max(l[i-1], r[i+1]);
		cout << a*b << ' ';
	}

	return 0;
}