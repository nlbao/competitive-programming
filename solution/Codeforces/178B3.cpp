#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100007;
const int MAX_M = 100007;
const int MAX_K = 100007;

int n, m, k, log2_n;
VI e[MAX_N];
int p[MAX_N][22], f[MAX_N][22], h[MAX_N], low[MAX_N];
bool ok[MAX_N];

int log2(int x)   {  int t = 0;  while (1<<t <= x) ++t;  return t;   }

void dfs_init(int u) {
   low[u] = u;
   foru(i, 1, log2_n)
      if (h[u]-(1<<i) < 1) break;
      else {
         p[u][i] = p[p[u][i-1]][i-1];
         f[u][i] = f[u][i-1]+f[p[u][i-1]][i-1];
      }
   rep(i, size(e[u])) {
      int v = e[u][i];
      if (p[v][0] == 0) {
         h[v] = h[u]+1;
         p[v][0] = u;
         f[v][0] = 1;
         dfs_init(v);
         if (h[low[v]] < h[low[u]]) low[u] = low[v];
      }
      else if (v != p[u][0] && h[v] < h[low[u]]) low[u] = v;
   }

}

void dfs_f(int u) {
   ok[u] = true;
   foru(i, 0, log2_n) {
      int hh = h[u]-(1<<i);
      if (hh < 1) break;
      else if (hh >= h[low[u]]) f[u][i] = 0;
      else if (i) f[u][i] = f[u][i-1]+f[p[u][i-1]][i-1];
   }
   rep(i, size(e[u])) {
      int v = e[u][i];
      if (!ok[v]) dfs_f(v);
   }
}

int lca(int u, int v) {
   if (h[u] < h[v]) return lca(v, u);
   if (h[u] > h[v])
      ford(i, log2_n, 0)
         if (h[u]-(1<<i) >= h[v]) u = p[u][i];
   if (u == v) return u;
   ford(i, log2_n, 0)
      if (h[u]-(1<<i) > 0 && p[u][i] != p[v][i]) {
         u = p[u][i];
         v = p[v][i];
      }
   return p[u][0];
}

int cal_f(int r, int u) {
   if (h[low[u]] <= h[r]) return 0;
   int i = 0;
   while (h[u]-(1<<(i+1)) >= h[r]) ++i;
   return f[u][i]+cal_f(r, p[u][i]);
}

int main() {
   freopen("178B2.in", "r", stdin);
   freopen("178B2.out", "w", stdout);
   int x, y;
   cin >> n >> m;
   foru(i, 1, m) {
      scanf("%d%d", &x, &y);
      e[x].pb(y); e[y].pb(x);
   }

   log2_n = log2(n);
   fill(h, 0);
   fill(p, 0);
   fill(f, 0);
   h[1] = 1;   p[1][0] = -1;
   dfs_init(1);

   fill(ok, false);
   dfs_f(1);

   cin >> k;
   rep(testid, k) {
      scanf("%d%d", &x, &y);
      int r = lca(x,y);
      cout << cal_f(r,x)+cal_f(r,y) << endl;
   }
   return 0;
}
