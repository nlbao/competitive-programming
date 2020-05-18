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


const int MAX_N = 1e4 + 4;
const int oo = 1e9;


int n, m, costS, costQ;
int a[MAX_N], b[MAX_N], ans[MAX_N];


inline int cal(int len) {
	int need = 1, c = 0, pos = 0;
	while (need <= n) {
		int l = pos, r = m-1, i = -1;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (a[mid]-len <= need) {
				i = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		if (i == -1) return oo;
		b[c++] = a[i];
		need = a[i] + len + 1;
		pos = i+1;
	}
	if (need <= n) return oo;
	return c;
}


int main() {
#ifdef DEBUG
	freopen("sprinklers.in", "r", stdin);
	freopen("sprinklers.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		scanf("%d%d", &costS, &costQ);

		for (int i = 0; i < m; ++i)
			a[i] = read();

		int minCost = 2*oo, ansE = -1, ansB = -1;
		for (int i = 0; i <= n; ++i) {
			int j = cal(i);
			if (j > m) continue;
			int cost = costS * j + costQ * i;
			if (cost < minCost) {
				minCost = cost;
				ansB = j;
				ansE = i;
				for (int k = 0; k < ansB; ++k)
					ans[k] = b[k];
			}
		}

		// cout << "minCost = " << minCost << endl;
		printf("%d %d\n", ansB, ansE);
		for (int i = 0; i < ansB; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}