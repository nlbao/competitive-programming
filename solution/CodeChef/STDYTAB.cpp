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


const int MAX_N = 2004;
const ll MODULE = 1e9;


int n, m;
int g[MAX_N][MAX_N], sg[MAX_N][MAX_N];
ll sf[2][MAX_N];


int solve() {
	filla(sf, 0);
	int t = 0;
	sf[t][0] = 1;
	for (int x = 1; x <= m; ++x)
		sf[t][x] = (sf[t][x-1] + g[m][x]) % MODULE;
	for (int i = 2; i <= n; ++i) {
		int tt = t;
		t ^= 1;
		sf[t][0] = 1;
		for (int x = 1; x <= m; ++x) {
			ll f = (sf[tt][x] * g[m][x]) % MODULE;
			sf[t][x] = (sf[t][x-1] + f) % MODULE;
		}
	}
	return sf[t][m];
}


int main() {
#ifdef DEBUG
	freopen("STDYTAB.in", "r", stdin);
	freopen("STDYTAB.out", "w", stdout);
#endif
	// init
	filla(g, 0);
	filla(sg, 0);
	for (int x = 0; x < MAX_N; ++x) sg[0][x] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		g[i][0] = sg[i][0] = 1;
		for (int x = 1; x < MAX_N; ++x) {
			g[i][x] = sg[i-1][x];
			sg[i][x] = (sg[i][x-1] + g[i][x]) % MODULE;
		}
	}
	// solve
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", solve());
	}
	return 0;
}