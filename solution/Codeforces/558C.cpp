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
const int MAX_A = 1e5 + 5;
const int MAX_F = 2*MAX_A + 4;
const int oo = 1e9;


int n, ans;
int a[MAX_F], c[MAX_F], d[MAX_F], f[MAX_F], g[MAX_F];


void dfs_1(int u) {
	if (u >= MAX_A) return;
	f[u] = 0;
	c[u] = a[u];
	int l = u<<1, r = l+1;
	dfs_1(l);
	c[u] += c[l];
	f[u] += f[l] + c[l];
	dfs_1(r);
	c[u] += c[r];
	f[u] += f[r] + c[r];
}


void dfs_2(int u) {
	if (u >= MAX_A) return;
	ans = min(ans, f[u] + g[u]);
	d[u] += a[u];
	int l = u<<1, r = l+1;
	g[l] = min(oo, g[u] + d[u] + f[r] + 2*c[r]);
	d[l] = min(oo, d[u] + c[r]);
	dfs_2(l);
	if (d[u] > 0 || c[l] > 0)
		d[r] = g[r] = oo;
	dfs_2(r);
}


int main() {
#ifdef DEBUG
	freopen("558C.in", "r", stdin);
	freopen("558C.out", "w", stdout);
#endif
	filla(a, 0);
	filla(c, 0);
	filla(d, 0);
	filla(f, 0);
	filla(g, 0);
	int n = read();
	for (int i = 0; i < n; ++i)
		++a[read()];
	dfs_1(1);
	ans = f[1];
	dfs_2(1);
	printf("%d\n", ans);
	return 0;
}