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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 555;


struct Hull {
	ll a[MAX_N], b[MAX_N];
	double x[MAX_N];
	int head, tail;

	Hull(): head(1), tail(0) {}

	ll get(ll xQuery) {
		if (head > tail) return 0;
		while (head < tail && x[head+1] <= xQuery) ++head;
		x[head] = xQuery;
		return a[head] * xQuery + b[head];
	}

	void add(ll aNew, ll bNew) {
		double xNew = -1e18;
		while (head <= tail) {
			if (aNew == a[tail]) return;
			xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
			if (head == tail || xNew >= x[tail]) break;
			tail--;
		}
		a[++tail] = aNew;
		b[tail] = bNew;
		x[tail] = xNew;
	}
};


int n;
ll COST;
ll b[MAX_N], c[MAX_N], d[MAX_N], t[MAX_N], f[MAX_N];
pii a[MAX_N];
Hull hull;


ll solve_0() {
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i-1] - COST;
		ll tmp = d[i] - c[i] * t[i] - COST;
		for (int j = 0; j <= i-1; ++j) {
			ll g = (f[j] - d[j]) + c[j] * t[i];
			f[i] = max(f[i], g + tmp);
		}
	}
	return f[n];
}


ll solve_1() {
	f[0] = 0;
	hull.add(0, 0);
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i-1] + COST;
		ll tmp = c[i] * t[i] - d[i] + COST;
		ll g = hull.get(t[i]);
		f[i] = min(f[i], g + tmp);
		hull.add(-c[i], f[i] + d[i]);
	}
	return f[n];
}


int main() {
#ifdef DEBUG
	freopen("VMPIZZA.in", "r", stdin);
	freopen("VMPIZZA.out", "w", stdout);
#endif
	n = read();
	COST = read();
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		ans += y;
		a[i] = pii(x, z);
	}

	sort(a+1, a+1+n);
	c[0] = d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		t[i] = a[i].first;
		b[i] = a[i].second;
		c[i] = c[i-1] + b[i];
		d[i] = d[i-1] + t[i]*b[i];
	}

	if (n <= 1000) ans += solve_0();
	else ans -= solve_1();
	cout << ans << '\n';
	return 0;
}