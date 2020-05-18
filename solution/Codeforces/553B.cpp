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


const int MAX_N = 55;
const ll oo = 1e18 + 1;


int n;
ll k;
ll f[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("553B.in", "r", stdin);
	freopen("553B.out", "w", stdout);
#endif
	scanf("%d %lld", &n, &k);
	filla(f, 0);
	f[n][n] = 1;
	f[n+1][n+1] = 1;
	for (int i = n-1; i >= 1; --i) {
		f[i][i] = f[i+1][i+1] + f[i+1][i+2];
		f[i][i+1] = f[i+2][i+2] + f[i+2][i+3];
		// cout << i << " " << f[i][i] << " " << f[i][i+1] << endl;
	}

	int i = 1;
	while (i <= n) {
		if (k <= f[i][i]) {
			printf("%d ", i);
			++i;
		}
		else {
			k -= f[i][i];
			printf("%d %d ", i+1, i);
			i += 2;
		}
	}
	return 0;
}