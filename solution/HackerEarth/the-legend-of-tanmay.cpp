#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   cin >> x;   return x;   }


const int MAX_N = 22;


int n;
ll a[MAX_N];


ll findMax() {
	ll ans = a[0], t = 1;
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, a[i]);
		if (a[i] < 0) pos = i+1;
		else if (a[i] > 0) {
			t *= a[i];
			ans = max(ans, t);
		}
	}
	if (pos > 0) {
		ll p = t;
		for (int i = 0; i < pos-1; ++i)
			p *= a[i];
		if (pos > 1) ans = max(ans, p);
		ans = max(ans, p * a[pos-1]);
	}
	return ans;
}


ll findMin() {
	ll ans = a[0], t = 1;
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, a[i]);
		if (a[i] < 0) pos = i+1;
		else if (a[i] > 0) t *= a[i];
	}
	if (pos > 0) {
		ll p = t;
		for (int i = 0; i < pos-1; ++i)
			p *= a[i];
		if (pos > 1) ans = min(ans, p);
		ans = min(ans, p * a[pos-1]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("the-legend-of-tanmay.in", "r", stdin);
	freopen("the-legend-of-tanmay.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		n = read();
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a+n);
		cout << findMax() << " " << findMin() << "\n";
	}
	return 0;
}