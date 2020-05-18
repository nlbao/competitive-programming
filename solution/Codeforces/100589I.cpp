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


char s[MAX_N];
ll f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100589I.in", "r", stdin);
	freopen("100589I.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);
		int n = strlen(s);
		f[0] = (s[0] == 'L');
		ll c = f[0];
		for (int i = 1; i < n; ++i) {
			f[i] = f[i-1];
			if (s[i] == 'L') ++c, ++f[i];
		}
		ll ans = 0;
		for (int i = 1; i < n-1; ++i)
			if (s[i] == 'O')
				ans += (c - f[i]) * f[i];
		printf("%lld\n", ans);
	}
	return 0;
}