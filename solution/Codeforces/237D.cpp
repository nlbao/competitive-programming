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

const int MAX_N = 200006;

int m;
int p[MAX_N], c[MAX_N];
VI e[MAX_N], q[MAX_N];
vector<PI> edge;

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (p[v] == -1) {
         p[v] = u;
         c[v] = ++m;
         q[m].pb(u);
         q[m].pb(v);
         if (c[u] > 0) edge.pb(mp(c[u],c[v]));
         dfs(v);
      }
   }
   if (u == 1 && sz > 1) {
      int root = c[e[u][sz-1]];
      rep(i,sz-1) edge.pb(mp(root,c[e[u][i]]));
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("237D.in", "r", stdin);
   freopen("237D.out", "w", stdout);
#endif
   int n = read();
   rep(i,n-1) {
      int x = read(), y = read();
      e[x].pb(y);
      e[y].pb(x);
   }

   foru(i,1,n) p[i] = -1;
   p[1] = 0;   c[1] = 0;
   m = 0;
   dfs(1);

   printf("%d\n",m);
   foru(i,1,m) {
      int sz = size(q[i]);
      printf("%d ",sz);
      rep(j,sz) printf("%d ",q[i][j]);
      printf("\n");
   }
   int sz = size(edge);
   rep(i,sz) printf("%d %d\n",edge[i].fr,edge[i].sc);
   return 0;
}
