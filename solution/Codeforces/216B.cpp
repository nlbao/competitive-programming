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

const int MAX_N = 1003;

VI e[MAX_N];
int deg[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int dfs(int u) {
   ok[u] = false;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (ok[v]) return dfs(v)+1;
   }
   return 1;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("216B.in", "r", stdin);
   freopen("216B.out", "w", stdout);
#endif
   int n, m;
   scanf("%d%d",&n,&m);
   fill(deg,0);
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y);
      e[y].pb(x);
      ++deg[x];
      ++deg[y];
   }

   fill(ok,true);
   int c1 = 0, c2 = 0, t = 0;
   foru(i,1,n)
      if (ok[i] && deg[i] == 1) {
         int c = dfs(i);
         c1 += c/2;
         c2 += c/2;
         if (c%2 == 1)
            if (c1 < c2) ++c1;
            else if (c1 > c2) ++c2;
            else ++t;
      }
   foru(i,1,n)
      if (ok[i] && deg[i] == 2) {
         int c = dfs(i);
         c1 += c/2;
         c2 += c/2;
      }
   foru(i,1,n)
      if (deg[i] == 0)
         if (c1 < c2) ++c1;
         else if (c1 > c2) ++c2;
         else ++t;
   c1 = min(c1,c2);
   c2 = c1;
   c1 += t/2;
   c2 += t/2;
   printf("%d",n-c1-c2);
   return 0;
}
