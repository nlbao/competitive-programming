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


int n, p;
char s[111];


int main() {
#ifdef DEBUG
	freopen("100589C.in", "r", stdin);
	freopen("100589C.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%s%d", &n, s, &p);
		for (int i = (s[0] == 'o') ? 2 : 1, c = 0; i <= n; i += 2) {
			++c;
			if (c == p) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}