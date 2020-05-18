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


const int MAX_N = 2*222;


int n;
int e[MAX_N][MAX_N], pos[MAX_N][MAX_N];
int match[MAX_N], ans[MAX_N];


bool tryf(int u, int limit) {
	for (int i = 0; i <= limit; ++i) {
		int v = e[u][i];
		if (pos[v][u] > limit) continue;
		int z = match[v];
		if (z == u) return true;
		if (z == -1) {
			match[v] = u;
			return true;
		}
		if (pos[v][z] < pos[v][u]) continue;
		match[v] = u;
		return tryf(z, limit);
	}
	return false;
}


bool check(int limit) {
	filla(match, -1);
	for (int i = 0; i < n; ++i)
		if (!tryf(i, limit))
			return false;
	for (int i = n; i < 2*n; ++i)
		if (match[i] < 0)
			return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("100703D.in", "r", stdin);
	freopen("100703D.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k) {
			int j = read()-1+n;
			e[i][k] = j;
			pos[i][j] = k;
		}
	for (int i = n; i < 2*n; ++i)
		for (int k = 0; k < n; ++k) {
			int j = read()-1;
			e[i][k] = j;
			pos[i][j] = k;
		}

	int minD = -1, l = 0, r = n-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			minD = mid;
			r = mid-1;
		}
		else l = mid+1;
	}

	printf("%d\n", minD+1);
	check(minD);
	for (int i = n; i < 2*n; ++i)
		ans[match[i]] = i-n+1;
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}