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
const int MAX_LEN = 33;
const int MAX_M = sqr(MAX_N) / 2;


int n, len;
char s[MAX_N][MAX_LEN];
pair<int, pii> a[MAX_M];
int p[MAX_N];


int dist(int x, int y) {
	int ans = 0;
	for (int i = 0; i < len; ++i)
		ans = max(ans, abs(s[x][i]-s[y][i]));
	return ans;
}


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("100703A.in", "r", stdin);
	freopen("100703A.out", "w", stdout);
#endif
	scanf("%d%d", &n, &len);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i]);
	int m = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			a[m++] = make_pair(dist(i, j), pii(i, j));
	sort(a, a+m);

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		p[i] = -1;
	for (int i = 0; i < m; ++i) {
		int u = a[i].second.first, v = a[i].second.second;
		u = getRoot(u), v = getRoot(v);
		if (u != v) {
			ans = a[i].first;
			p[u] = v;
		}
	}
	printf("%d\n", ans);
	return 0;
}