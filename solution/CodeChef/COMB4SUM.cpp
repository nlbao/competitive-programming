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


const int MAX_N = 1e3 + 33;
const int PADDING = 1e5 + 5;
const int MAX_F = 4*PADDING + 10;


int n;
int a[MAX_N];
ll c[MAX_F][3], f[MAX_F][3];


void sub_update(int k, int i, ll value) {
	if (i >= MAX_F) return;
	c[i][k] += 1;
	f[i][k] += value;
	sub_update(k, i + (i & (-i)), value);
}


void update(int k, ll value) {
	sub_update(k, PADDING+value, value);
}


pll sub_get(int k, int i) {
	if (i < 1 || i >= MAX_F) return pll(0, 0);
	pll u(c[i][k], f[i][k]);
	pll t = sub_get(k, i - (i & (-i)));
	u.first += t.first;
	u.second += t.second;
	return u;
}


pll get(int k, int pos) {
	return sub_get(k, PADDING+pos);
}


int main() {
#ifdef DEBUG
	freopen("COMB4SUM.in", "r", stdin);
	freopen("COMB4SUM.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			a[i] = read();

		filla(c, 0);
		filla(f, 0);

		ll ans = 0, all = 0;
		ll sum[3], t[3];
		pll u[3];
		filla(sum, 0);
		for (int j = n; j >= 1; --j) {
			for (int i = 1; i < j; ++i) {
				ll s = 0;
				t[0] = a[i]+a[j];
				t[1] = a[i]-a[j];
				t[2] = a[i]-a[j];
				for (int k = 0; k < 3; ++k) {
					u[k] = get(k, t[k]);
					s += u[k].first * t[k] - u[k].second - (all-u[k].first) * t[k] + (sum[k] - u[k].second);
				}
				s *= 2;
				ans += s;
			}
			for (int k = j+1; k <= n; ++k) {
				update(0, a[j]+a[k]);
				update(1, a[j]-a[k]);
				update(2, a[k]-a[j]);
				sum[0] += a[j]+a[k];
				sum[1] += a[j]-a[k];
				sum[2] += a[k]-a[j];
				++all;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}