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


const int MAX_N = 1e3 + 33;


int n, m, nA, nB;
int a[MAX_N], b[MAX_N], ok[MAX_N];
vector<int> e[MAX_N];


int solve(int mask) {
	filla(ok, 0);
	for (int i = 0; i < nA; ++i)
		if (mask&(1<<i))
			foreach(it, e[a[i]]) {
				if (*it > m) break;
				ok[*it] ^= 1;
			}
	int ans = 0, sum[2];
	for (int i = 1; i <= m; ++i)
		ans += ok[i];
	for (int i = 0; i < nB; ++i) {
		sum[0] = sum[1] = 0;
		foreach(it, e[b[i]]) {
			if (*it > m) break;
			++sum[ok[*it]];
		}
		ans = max(ans, ans + sum[0] - sum[1]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6912.in", "r", stdin);
	freopen("6912.out", "w", stdout);
#endif
	for (int i = 1; i < MAX_N; ++i) {
		e[i].clear();
		for (int j = i; j < MAX_N; j += i)
			e[i].push_back(j);
	}

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d%d", &m, &n);
		int limit = sqrt(m);
		nA = nB = 0;
		for (int i = 0; i < n; ++i) {
			int x = read();
			if (x > m) continue;
			if (x < limit) a[nA++] = x;
			else b[nB++] = x;
		}

		int ans = 0, m = 1<<nA;
		for (int mask = 0; mask < m; ++mask)
			ans = max(ans, solve(mask));
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}