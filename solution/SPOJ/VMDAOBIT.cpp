#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1005;


int m, n;
bool a[MAX_N][MAX_N];
vector<pii> ans;


inline bool ok(int x, int y) {
	return x > 0 && x <= m-2 && y > 0 && y <= n-2;
}


inline void swapBit(int x, int y) {
	for (int i = x; i <= x+2; ++i)
		for (int j = y; j <= y+2; ++j)
			a[i][j] = !a[i][j];
}


bool solve() {
	ans.clear();
	for (int s = 2; s <= n+m; ++s)
		for (int i = 1; i <= m; ++i) {
			int j = s-i;
			if (!ok(i, j)) continue;
			if (a[i][j]) continue;
			swapBit(i, j);
			ans.push_back(pii(i, j));
		}

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (!a[i][j])
				return false;

	int n = ans.size();
	sort(ans.begin(), ans.end());
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("VMDAOBIT.in", "r", stdin);
	freopen("VMDAOBIT.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			int x = read();
			a[i][j] = (x == 0);
		}
	if (!solve())
		printf("-1\n");
	return 0;
}