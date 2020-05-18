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

const int MAX_N = 100004;
const int MAX_LOG = 20;
const ll MODUN = 1000000007LL;

int n;
VI e[MAX_N];
bool ok[MAX_N];
int p[MAX_N][MAX_LOG], h[MAX_N], sz[MAX_N];
ll c[MAX_N], f[MAX_N][MAX_LOG];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x) {   return x%MODUN;   }

void up(int u, int v) {
   while (u != v) {
      c[u] = 2;
      u = p[u][0];
   }
   c[v] = 2;
}

void dfs_init(int u) {
   ok[u] = false;
   rep(i,sz[u]) {
      int v = e[u][i];
      if (ok[v]) {
         p[v][0] = u;
         h[v] = h[u]+1;
         dfs_init(v);
      }
      else if (v != p[u][0] && h[v] < h[u]) up(u,v);
   }
}

void dfs(int u) {
   ok[u] = false;
   foru(i,1,MAX_LOG-1)
      if (1<<i >= h[u]) p[u][i] = 0;
      else {
         int v = p[u][i-1];
         p[u][i] = p[v][i-1];
         f[u][i] = mmod(f[u][i-1]*f[v][i-1]);
      }
   rep(i,sz[u]) {
      int v = e[u][i];
      if (ok[v]) {
         p[v][0] = u;
         f[v][0] = c[v];
         h[v] = h[u]+1;
         dfs(v);
      }
   }
}

ll get_f(int u, int v) {
   if (h[u] < h[v]) return(get_f(v,u));
   ll t1 = 1, t2 = 1;
   if (h[u] > h[v])
      ford(i,MAX_LOG-1,0)
         if (h[u]-(1<<i) >= h[v]) {
            t1 = mmod(t1*f[u][i]);
            u = p[u][i];
         }
   if (u == v) return mmod(t1*t2);
   ford(i,MAX_LOG-1,0)
      if (p[u][i] != p[v][i]) {
         t1 = mmod(t1*f[u][i]);
         t2 = mmod(t2*f[v][i]);
         u = p[u][i];
         v = p[v][i];
      }
   return mmod(t1*t2);
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("231E.in", "r", stdin);
   freopen("231E.out", "w", stdout);
#endif
   int m;
   scanf("%d%d",&n,&m);
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y);
      e[y].pb(x);
   }
   foru(i,1,n) sz[i] = size(e[i]);

   fill(ok,true);
   foru(i,1,n) c[i] = 1;
   h[1] = 1;   p[1][0] = 0;
   dfs_init(1);

   fill(ok,true);
   h[1] = 1;   p[1][0] = 0;   f[1][0] = 0;
   dfs(1);

   cout << f[7][1] << endl;

   int q = read();
   rep(i,q) {
      int u = read(), v = read();
      int t = get_f(u,v);
      printf("%d\n",t);
   }
   return 0;
}
