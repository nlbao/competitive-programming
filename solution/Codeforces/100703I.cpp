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


const int MAX_N = 222;
const int MAX_M = 1e3 + 3;
const int oo = 1e9 + 9;


int n;
int m[MAX_N], b[MAX_N], f[MAX_N];
vector<pii> a[MAX_N];


int find(int i, int limit) {
	int l = 0, r = m[i]-1, ans = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (a[i][mid].first >= limit) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100703I.in", "r", stdin);
	freopen("100703I.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &m[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m[i]; ++j)
			a[i].push_back(pii(read(), j));
		sort(a[i].begin(), a[i].end());
	}

	if (n == 1) {
		printf("0\n%d", a[1][0].first);
		return 0;
	}

	int ans = oo;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m[i]; ++j) {
			bool ok = true;
			int minValue = a[i][j].first, maxValue = 0;
			for (int k = 1; k <= n; ++k) if (k != i) {
				int t = find(k, minValue);
				if (t == -1) {
					ok = false;
					break;
				}
				b[k] = a[k][t].second;
				maxValue = max(maxValue, a[k][t].first);
			}
			if (!ok || maxValue - minValue >= ans) continue;
			ans = maxValue - minValue;
			for (int k = 1; k <= n; ++k)
				f[k] = b[k];
			f[i] = a[i][j].second;
		}
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
	return 0;
}