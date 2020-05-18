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
#pragma comment(linker,"/STACK:1000000000,1000000000")

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

const int MAX_N = 50003;

int n, m, len;
ll a[MAX_N], f[MAX_N];
vector<pair<ll,int> > e[MAX_N];
int p[MAX_N], trace[MAX_N], g[MAX_N];
ll res;
PI des;

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   f[u] = a[u];   g[u] = 0;
   trace[u] = u;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].sc;
      if (p[v] == 0) {
         p[v] = u;
         dfs(v);
         ll w = e[u][i].fr;
         ll t = f[u]+w+f[v];
         if (t > res || (t == res && g[u]+g[v]+1 < len)) {
            res = t;
            len = g[u]+g[v]+1;
            des = mp(trace[u],trace[v]);
         }

         t = f[v]+w+a[u];
         if (t > f[u] || (t == f[u] && g[v]+1 < g[u])) {
            f[u] = t;
            g[u] = g[v]+1;
            trace[u] = trace[v];
         }
      }
   }
   if (f[u] > res) {
      res = f[u];
      des = mp(u,trace[u]);
   }
}

bool print_res(int u, int d) {
   p[u] = -1;
   if (u == d) {
      trace[m++] = u;
      return true;
   }
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].sc;
      if (p[v] == 0) {
         if (print_res(v, d) == true) {
            trace[m++] = u;
            return true;
         }
      }
   }
   return false;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1463.in", "r", stdin);
   freopen("1463.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   foru(i,1,n) a[i] = read();
   rep(i,m) {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      e[a].pb(mp(c,b));
      e[b].pb(mp(c,a));
   }

   res = -1; des = mp(1,1);
   fill(p,0);
   foru(i,1,n)
      if (p[i] == 0) {
         p[i] = -1;
         dfs(i);
      }

   cout << res << endl;
   m = 0;
   fill(p,0);
   print_res(des.fr, des.sc);
   printf("%d\n",m);
   ford(i,m-1,0) printf("%d ",trace[i]);
   return 0;
}
