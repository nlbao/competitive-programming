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


const int MAX_N = 111;
const int MAX_X = 77;
const int MAX_Y = 5005;


ll f[MAX_N][MAX_X][MAX_Y];


int main() {
#ifdef DEBUG
	freopen("sum-of-squares-1.in", "r", stdin);
	freopen("sum-of-squares-1.out", "w", stdout);
#endif
	filla(f, 0);
	f[0][0][0] = 1;
	for (int x = 0; x < MAX_X; ++x)
		f[0][x][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		for (int x = 1; x < MAX_X; ++x) {
			f[i][x][i] = 1;
			for (int y = i+1; y < MAX_Y; ++y) {
				f[i][x][y] = f[i][x-1][y];
				if (y >= x*x)
					f[i][x][y] += f[i-1][x][y - x*x];
			}
		}
	}

	int nTest = read();
	while (nTest--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int x = sqrt(k);
		while (sqr(x+1) <= k) ++x;
		printf("%lld\n", f[n][x][k]);
	}
	return 0;
}