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


int main() {
#ifdef DEBUG
	freopen("destroy-1.in", "r", stdin);
	freopen("destroy-1.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		int m = read();
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
		}
		if (n&1) printf("Artur\n");
		else printf("Alex\n");
	}
	return 0;
}