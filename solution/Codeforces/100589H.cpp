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


const int MAX_N = 1e5 + 55;


int n, m, crrTurn;
int a[MAX_N];
ll f[MAX_N], ans, limit;
int turn[MAX_N];
map<int, int> id;


ll get(int i) {
	if (i < 1) return 0;
	if (turn[i] < crrTurn) {
		turn[i] = crrTurn;
		f[i] = 0;
	}
	return f[i] + get(i - (i&(-i)));
}


void update(int i, int value) {
	if (i > m) return;
	if (turn[i] < crrTurn) {
		turn[i] = crrTurn;
		f[i] = 0;
	}
	f[i] += value;
	update(i + (i&(-i)), value);
}


inline ll getLessThan(ll x) {
	return get(x-1);
}


inline ll getMoreThan(ll x) {
	return get(m) - get(x);
}


void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (limit == 0) ++ans;
		return;
	}

	int mid = (l+r)>>1;
	solve(l, mid);
	solve(mid+1, r);

	++crrTurn;
	ll c = 0;
	for (int i = l; i <= mid+1; ++i) {
		c += getMoreThan(a[i]);
		update(a[i], 1);
	}
	for (int i = l, j = mid+2; i <= mid; ++i) {
		while (j <= r && c < limit) {
			c += getMoreThan(a[j]);
			update(a[j], 1);
			++j;
		}
		if (c < limit) break;
		ans += (r - (j-1) + 1);
		c -= getLessThan(a[i]);
		update(a[i], -1);
	}
}


int main() {
#ifdef DEBUG
	freopen("100589H.in", "r", stdin);
	freopen("100589H.out", "w", stdout);
#endif
	scanf("%d%lld", &n, &limit);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		id[a[i]];
	}
	m = 0;
	foreach(it, id) it->second = ++m;
	for (int i = 1; i <= n; ++i)
		a[i] = id[a[i]];

	ans = 0;
	crrTurn = 0;
	filla(turn, 0);
	solve(1, n);
	printf("%lld\n", ans);
	return 0;
}