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


const ll MODULE = 997;
const int MAX_C = MODULE + 10;
const int MAX_N = 111;
const int dx[9] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};
const int dy[9] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};


pii a[MAX_N];
ll c[MAX_C][MAX_C], f[MAX_N];


ll getC(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	if (k == 0 || k == n) return 1;
	if (n < MODULE) return c[n][k];
	ll ans = 1;
	while (n) {
		ll t = getC(n % MODULE, k % MODULE);
		if (t == 0) return 0;
		ans = (ans*t) % MODULE;
		n /= MODULE, k /= MODULE;
	}
	return ans;
}


ll cal(int i, int j) {
	ll n = a[j].first - a[i].first + 1;
	ll m = a[j].second - a[i].second + 1;
	return getC(m+n-2, n-1);
}


int main() {
#ifdef DEBUG
	freopen("6916.in", "r", stdin);
	freopen("6916.out", "w", stdout);
#endif
	filla(c, 0);
	for (int i = 0; i < MAX_C; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MODULE;
	}

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int m, n, k, nC = 0;
		scanf("%d%d%d", &m, &n, &k);
		a[0] = pii(1, 1);
		for (int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			for (int t = 0; t < 9; ++t) {
				int xx = x + dx[t];
				int yy = y + dy[t];
				a[++nC] = pii(xx, yy);
			}
		}
		a[++nC] = pii(m, n);

		sort(a+1, a+1+nC);
		for (int i = 1; i <= nC; ++i)
			f[i] = cal(0, i);
		for (int i = 1; i < nC; ++i)
			for (int j = i+1; j <= nC; ++j) {
				if (a[j].first < a[i].first || a[j].second < a[i].second)
					continue;
				f[j] = (f[j] - f[i] * cal(i, j)) % MODULE;
				if (f[j] < 0) f[j] += MODULE;
			}
		printf("Case #%d: %d\n", testid, (int)f[nC]);
	}
	return 0;
}