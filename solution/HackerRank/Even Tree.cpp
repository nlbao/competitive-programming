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

const int MAX_N = 111;

int n, m;
VI e[MAX_N];
int f[MAX_N][2], sz[MAX_N];
bool ok[MAX_N], c[MAX_N][2], d[2];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   ok[u] = false;
   c[u][1] = true;
   c[u][0] = false;
   f[u][0] = f[u][1] = 0;
   rep(i,sz[u]) {
      int v = e[u][i];
      if (ok[v]) {
         dfs(v);
         foru(i,0,1) {
            d[i] = c[u][i];
            c[u][i] = false;
         }
         foru(i,0,1) if (d[i])
            foru(j,0,1) if (c[v][j]) {
               int k = (i+j)%2;
               c[u][k] = true;
               f[u][k] = max(f[u][k], f[u][i]+f[v][j]);
            }
      }
   }
   if (c[u][0]) ++f[u][0];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("Even Tree.in", "r", stdin);
   freopen("Even Tree.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y);
      e[y].pb(x);
   }

   foru(i,1,n) {
      sz[i] = size(e[i]);
      ok[i] = true;
   }
   dfs(1);
   int res = max(1,max(f[1][0],f[1][1]));
   printf("%d",res-1);
   return 0;
}
