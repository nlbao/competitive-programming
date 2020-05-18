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

const int MAX_N = 5010;
const int MAX_M = 10010;

int n,m,cnt,nLeaf1;
PI e[MAX_M];
VI a[MAX_N];
bool ok[MAX_M], is_cut[MAX_N];
int p[MAX_N], nChild[MAX_N], f[MAX_N], num[MAX_N], low[MAX_N];

void dfs(int u) {
   nChild[u] = 0;
   num[u] = ++cnt;
   low[u] = 10*n;
   int sz = size(a[u]);
   rep(i,sz) {
      int j = a[u][i];
      if (!ok[j]) continue;
      ok[j] = false;
      int v = e[j].fr;
      if (v == u) v = e[j].sc;
      if (p[v] == -1) {
         p[v] = u;
         ++nChild[u];
         dfs(v);
         low[u] = min(low[u],low[v]);
      }
      else low[u] = min(low[u],num[v]);
   }
   if (p[u] < n || nChild[u] > 1)
      if (low[u] >= num[u]) is_cut[u] = true;
}

void dfs2(int u) {
   f[u] = 0;
   int sz = size(a[u]);
   rep(i,sz) {
      int j = a[u][i], v = e[j].fr;
      if (v == u) v = e[j].sc;
      if (p[v] != u) continue;
      dfs2(v);
      f[u] += f[v];
   }
   if (is_cut[u] && f[u] == 0) f[u] = 1;
}

int solve() {
   if (f[1] == 0) return 0;
   int nLeaf = f[1]+1;
   return ((nLeaf/2)+(nLeaf%2));
}

int main() {
   freopen("3177.in", "r", stdin);
   freopen("3177.out", "w", stdout);
   scanf("%d%d",&n,&m);
   rep(i,m) {
      scanf("%d%d",&e[i].fr,&e[i].sc);
      a[e[i].fr].pb(i);
      a[e[i].sc].pb(i);
      ok[i] = true;
   }

   fill(is_cut,false);
   foru(i,1,n) p[i] = -1;
   p[1] = n+1;
   cnt = 0;
   dfs(1);
   dfs2(1);
   printf("%d",solve());
   return 0;
}
