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


const int MAX_N = 1e5 + 5;


int p[MAX_N];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("city-and-soldiers.in", "r", stdin);
	freopen("city-and-soldiers.out", "w", stdout);
#endif
	int n = read();
	for (int i = 1; i <= n; ++i)
		p[i] = -1;
	int nQ = read();
	while (nQ--) {
		int t = read();
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x = getRoot(x), y = getRoot(y);
			if (x != y)
				p[x] = y;
		}
		else if (t == 2) {
			int x = read();
			int r = getRoot(x);
			p[r] = x;
			p[x] = -1;
		}
		else {
			int x = read();
			printf("%d\n", getRoot(x));
		}
	}
	return 0;
}