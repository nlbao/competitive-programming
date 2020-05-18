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
const int MAX_Q = 1e5 + 5;


int n, m;
int a[MAX_N];
pii ans[MAX_Q];


int main() {
#ifdef DEBUG
	freopen("100703B.in", "r", stdin);
	freopen("100703B.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) a[i] = read();
	int pos = 1, sum = 0;
	for (int i = 1; i < MAX_Q; ++i) {
		if (pos <= n) sum += m;
		while (pos <= n && a[pos] <= sum) {
			sum -= a[pos];
			++pos;
		}
		ans[i] = pii(pos-1, sum);
	}

	int nQ = read();
	while (nQ--) {
		int d = read();
		printf("%d %d\n", ans[d].first, ans[d].second);
	}
	return 0;
}