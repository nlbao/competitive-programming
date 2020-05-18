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


const int MAX_C = 1e6 + 6;


int c[MAX_C];


int main() {
#ifdef DEBUG
	freopen("monk-in-the-land-of-pokemons.in", "r", stdin);
	freopen("monk-in-the-land-of-pokemons.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read(), ans = 0;
		filla(c, 0);
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			++c[a];
			if (c[b] < 1) ++ans;
			else --c[b];
		}
		printf("%d\n", ans);
	}
	return 0;
}