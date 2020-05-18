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


const int MAX_N = 1e5 + 5;
const int MAX_M = 1e5 + 5;


ll x[MAX_M], y[MAX_M];
pair<ll, int> a[MAX_N];
int ans[MAX_N];


ll area(int m) {
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		int j = (i-1+m)%m;
		ans += (x[j]+x[i]) * (y[j]-y[i]);
	}
	return abs(ans);
}


int main() {
#ifdef DEBUG
	freopen("CHPLGNS.in", "r", stdin);
	freopen("CHPLGNS.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0; i < n; ++i) {
			int m = read();
			for (int k = 0; k < m; ++k) {
				x[k] = read();
				y[k] = read();
			}
			a[i] = make_pair(area(m), i);
		}
		sort(a, a+n);
		for (int i = 0; i < n; ++i)
			ans[a[i].second] = i;
		for (int i = 0; i < n; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}