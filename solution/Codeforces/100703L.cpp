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


const int MAX_N = 1e3 + 3;


int p[MAX_N], k[MAX_N], r[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100703L.in", "r", stdin);
	freopen("100703L.out", "w", stdout);
#endif
	int n = read(), c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) p[i] = read();
	for (int i = 0; i < n; ++i) k[i] = read();
	for (int i = 0; i < n; ++i) r[i] = read();
	for (int i = 0; i < n; ++i) {
		int x = abs(p[i]-r[i]), y = abs(k[i]-r[i]);
		if (x == y) continue;
		if (x < y) ++c1;
		else ++c2;
	}
	printf("%d %d\n", c1, c2);
	return 0;
}