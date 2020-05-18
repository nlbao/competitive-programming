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


int main() {
#ifdef DEBUG
	freopen("LCKYST.in", "r", stdin);
	freopen("LCKYST.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		ll a = read();
		ll x = a;
		while (x%10 == 0) x /= 10;
		while (x%5 == 0) {
			a *= 4;
			x /= 5;
			if (x%5 != 0) break;
			x /= 5;
		}
		printf("%lld\n", a);
	}
	return 0;
}