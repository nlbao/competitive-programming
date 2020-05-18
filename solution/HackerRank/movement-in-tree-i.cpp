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


const ll MODULE = 1e9 + 7;


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x % MODULE;
	ll t = mpow(x, d>>1);
	t = (t*t) % MODULE;
	if (d&1) return (t*x) % MODULE;
	return t;
}


int solve(int d, int k) {
	if (d == 1) return k+1;
	ll a = mpow(d, k+1) - 1;
	if (a < 0) a += MODULE;
	ll b = mpow(d-1, MODULE-2);
	return (a*b) % MODULE;
}


int main() {
#ifdef DEBUG
	freopen("movement-in-tree-i.in", "r", stdin);
	freopen("movement-in-tree-i.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int d, k, h;
		scanf("%d%d%d", &d, &k, &h);
		printf("%d\n", solve(d, k));
	}
	return 0;
}