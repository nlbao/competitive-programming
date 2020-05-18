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
const ll MODULE = 1e9 + 7;


int n, m, nC;
int c[MAX_N], color[MAX_N];
bool ok[MAX_N];
vector<pii> e[MAX_N];
vector<int> e2[MAX_N];


void dfs(int u) {
	ok[u] = false;
	c[u] = nC;
	foreach(it, e[u]) {
		if (it->first == 0) continue;
		int v = it->second;
		if (ok[v])
			dfs(v);
	}
}


bool check(int u, int col) {
	ok[u] = false;
	color[u] = col;
	col ^= 1;
	foreach(it, e2[u]) {
		int v = *it;
		if (ok[v]) {
			if (!check(v, col)) return false;
		}
		else if (color[v] != col)
			return false;
	}
	return true;
}


int solve() {
	nC = 0;
	filla(ok, true);
	for (int i = 1; i <= n; ++i)
		if (ok[i]) {
			++nC;
			dfs(i);
		}
	for (int u = 1; u <= n; ++u)
		foreach(it, e[u]) {
			if (it->first == 1) continue;
			int v = it->second;
			if (c[u] == c[v]) return 0;
			e2[c[u]].push_back(c[v]);
		}

	int m = 0;
	filla(ok, true);
	for (int i = 1; i <= nC; ++i)
		if (ok[i]) {
			++m;
			if (!check(i, 0))
				return 0;
		}

	ll ans = 1;
	for (int i = 1; i < m; ++i)
		ans = (2LL*ans) % MODULE;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("553C.in", "r", stdin);
	freopen("553C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		e[u].push_back(pii(x, v));
		e[v].push_back(pii(x, u));
	}
	printf("%d\n", solve());
	return 0;
}