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


const int MAX_N = 1e5 + 5;
const int MAX_M = 22;
const int MAX_P = 1<<MAX_M + 4;
const ll MODULE = 1e9 + 7;


int n, m;
int f[MAX_P];
char s[MAX_M];


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x;
	ll t = mpow(x, d>>1);
	t = (t*t) % MODULE;
	if (d&1) return (t*x) % MODULE;
	return t;
}


inline int toInt() {
	int ans = 0;
	for (int i = 0; i < m; ++i)
		if (s[i] == '1')
			ans |= (1<<i);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("vim-war.in", "r", stdin);
	freopen("vim-war.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	filla(f, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		++f[toInt()];
	}
	scanf("%s", s);
	int final = toInt();

	int nMask = 1<<m;
	for (int i = 0; i < m; ++i)
		for (int mask = 0; mask < nMask; ++mask)
			if (mask & (1<<i))
				f[mask] += f[mask ^ (1<<i)];

	int ans = 0;
	for (int mask = 0; mask <= final; ++mask)
		if ((mask|final) == final) {
			ll t = (mpow(2, f[mask]) - 1 + MODULE) % MODULE;
			if (__builtin_popcount(final^mask) & 1)
				t = (MODULE-t) % MODULE;
			ans = (ans + t) % MODULE;
		}
	printf("%d\n", ans);

	return 0;
}