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


int n, nC;
vector<int> e[MAX_N];
int color[MAX_N], c[MAX_N][2], root[MAX_N], choose[MAX_N][MAX_N], ans[MAX_N];
bool ok[MAX_N], f[MAX_N][MAX_N];


bool dfs(int u, int col) {
	ok[u] = false;
	color[u] = col;
	++c[nC][col];
	col ^= 1;
	foreach(it, e[u]) {
		int v = *it;
		if (ok[v]) {
			if (!dfs(v, col))
				return false;
		}
		else if (color[v] != col)
			return false;
	}
	return true;
}


void getAns(int u, int col) {
	ok[u] = false;
	ans[u] = col;
	col ^= 1;
	foreach(it, e[u]) {
		int v = *it;
		if (ok[v])
			getAns(v, col);
	}
}


int main() {
#ifdef DEBUG
	freopen("ANCOIMP.in", "r", stdin);
	freopen("ANCOIMP.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				int x = read();
				if (x == 0) continue;
				e[i].push_back(j);
				e[j].push_back(i);
			}

		nC = 0;
		filla(ok, true);
		bool ck = true;
		for (int i = 1; i <= n; ++i) if (ok[i]) {
			root[nC] = i;
			c[nC][0] = c[nC][1] = 0;
			ck = ck && dfs(i, 0);
			if (!ck) break;
			++nC;
		}
		if (!ck) {
			printf("-1\n");
			continue;
		}

		// dp
		filla(f, false);
		for (int i = 0; i < 2; ++i) {
			f[0][c[0][i]] = true;
			choose[0][c[0][i]] = i;
		}
		for (int i = 1; i < nC; ++i)
			for (int x = 0; x <= n; ++x) {
				if (x >= c[i][0] && f[i-1][x-c[i][0]]) {
					f[i][x] = true;
					choose[i][x] = 0;
				}
				else if (x >= c[i][1] && f[i-1][x-c[i][1]]) {
					f[i][x] = true;
					choose[i][x] = 1;
				}
			}
		int t = n/2, minC = 1000*MAX_N;
		for (int x = 0; x <= n; ++x)
			if (f[nC-1][x] && abs(x-t) < abs(minC-t))
				minC = x;

		// get ans
		filla(ok, true);
		for (int i = nC-1, x = minC; i >= 0; --i) {
			getAns(root[i], choose[i][x]);
			x -= c[i][choose[i][x]];
		}
		for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}