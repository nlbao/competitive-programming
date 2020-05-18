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

const int MAX_N = 100003;
const int MAX_M = MAX_N;

int n, m;
int a[MAX_M], b[MAX_M], p[MAX_N], f[MAX_N][2];
VI e[MAX_N];

void dfs(int u) {
   f[u][0] = f[u][1] = 0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (u == a[v]) v = b[v];
      else v = a[v];
      if (p[v] == 0) {
         p[v] = u;
         dfs(v);
         f[u][0] += max(f[v][0],f[v][1]);;
      }
   }
   rep(i,sz) {
      int v = e[u][i];
      if (u == a[v]) v = b[v];
      else v = a[v];
      if (p[v] == u)
         f[u][1] = max(f[u][1], f[u][0]-max(f[v][0],f[v][1])+1+f[v][0]);
   }
}

void print_res(int u) {
   int sz = size(e[u]);
   bool ok = (f[u][1] > f[u][0]);
   rep(i,sz) {
      int j = e[u][i], v;
      if (u == a[j]) v = b[j];
      else v = a[j];
      if (p[v] == u) {
         if (ok && f[u][1] == f[u][0]-max(f[v][0],f[v][1])+1+f[v][0]) {
            printf("%d %d\n",a[j],b[j]);
            ok = false;
         }
         print_res(v);
      }
   }
}

int main() {
   freopen("1389.in", "r", stdin);
   freopen("1389.out", "w", stdout);
   scanf("%d%d",&n,&m);
   rep(i,m) {
      scanf("%d%d",&a[i],&b[i]);
      e[a[i]].pb(i);
      e[b[i]].pb(i);
   }

   fill(p,0);
   p[1] = -1;
   dfs(1);
   printf("%d\n",max(f[1][0],f[1][1]));
   print_res(1);
   return 0;
}
