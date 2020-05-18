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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 200005;

int n, res;
vector<PI> e[MAX_N];
int f[MAX_N], g[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   ok[u] = false;
   f[u] = 0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].fr;
      if (!ok[v]) continue;
      if (e[u][i].sc == 1) ++f[u];
      dfs(v);
      f[u] += f[v];
   }
}

void dfs2(int u) {
   ok[u] = false;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].fr;
      if (!ok[v]) continue;
      g[v] = g[u]+f[u]-f[v];
      if (e[u][i].sc == 0) ++g[v];
      else --g[v];
      dfs2(v);
   }
   res = min(res,f[u]+g[u]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("219D.in", "r", stdin);
   freopen("219D.out", "w", stdout);
#endif
   scanf("%d",&n);
   rep(i,n-1) {
      int x,y;
      scanf("%d%d",&x,&y);
      e[x].pb(mp(y,0));
      e[y].pb(mp(x,1));
   }

   res = 1000000000;
   fill(ok,true);
   fill(g,0);
   dfs(1);
   fill(ok,true);
   dfs2(1);
   printf("%d\n",res);
   foru(i,1,n)
      if (f[i]+g[i] == res) printf("%d ",i);
   return 0;
}
