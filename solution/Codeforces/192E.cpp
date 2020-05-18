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

int n, logn = 0;
vector<PI> e[MAX_N];
int h[MAX_N], t[MAX_N], p[MAX_N][22], c[MAX_N], f[MAX_N];

void init_lca(int u) {
   foru(i, 1, logn)
      if (h[u]-(1<<i) > 0) p[u][i] = p[p[u][i-1]][i-1];
      else p[u][i] = -1;
   rep(i, size(e[u])) {
      int v = e[u][i].fr;
      if (p[v][0] == 0) {
         p[v][0] = u;
         h[v] = h[u]+1;
         t[v] = e[u][i].sc;
         init_lca(v);
      }
   }
}

int lca(int u, int v) {
   if (h[u] > h[v]) return lca(v,u);
   if (h[u] < h[v])
      ford(i, logn, 0)
         if (h[v]-(1<<i) >= h[u]) v = p[v][i];
   if (u == v) return u;
   ford(i, logn, 0)
      if (p[u][i] != p[v][i]) {
         u = p[u][i];
         v = p[v][i];
      }
   return p[u][0];
}

int cal_f(int u) {
   f[t[u]] = c[u];
   rep(i, size(e[u])) {
      int v = e[u][i].fr;
      if (p[v][0] == u) f[t[u]] += cal_f(v);
   }
   return f[t[u]];
}

int main() {
   freopen("192E.in", "r", stdin);
   freopen("192E.out", "w", stdout);
   int x, y, k;
   cin >> n;
   foru(i, 1, n-1) {
      scanf("%d%d", &x, &y);
      e[x].pb(mp(y,i));
      e[y].pb(mp(x,i));
   }

   while (1<<(logn+1) <= n) ++logn;
   foru(i, 2, n) p[i][0] = 0;
   h[1] = 1;   p[1][0] = -1;  t[1] = 0;
   init_lca(1);

   fill(c,0);
   cin >> k;
   rep(i,k) {
      scanf("%d%d",&x,&y);
      ++c[x];  ++c[y];
      c[lca(x,y)] -= 2;
   }

   cal_f(1);
   foru(i, 1, n-1) printf("%d ", f[i]);
   return 0;
}
