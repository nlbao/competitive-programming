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
typedef unsigned long long ull;
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

const int MAX_N = 100005;
const int MAX_M = 100005;

int n, m, s1, s2, r1, r2, rk;
VI e[MAX_N], p1, p2;
int deg[MAX_N], turn[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool ok(int k, int d1, int d2) {
   int a = max(s1+k+1-d1,0);
   int b = max(s2+k+1-d2,0);
   if (a+b <= k) return true;
   return false;
}

bool check(int u) {
   if (deg[u] < min(s1,s2)) return false;
   int sz = size(e[u]);
   rep(i,sz) turn[e[u][i]] = u;
   rep(i,sz) {
      int v = e[u][i];
      if (v <= u) continue;
      if (deg[u] <= s1 && deg[v] <= s1) continue;
      if (deg[u] <= s2 && deg[v] <= s2) continue;

      int sz2 = size(e[v]), k = 0;
      rep(j,sz2) {
         int z = e[v][j];
         if (z != u && turn[z] == u) ++k;
      }

      if (ok(k,deg[u],deg[v])) {
         r1 = u;  r2 = v;
         rk = k;
         return true;
      }
      if (ok(k,deg[v],deg[u])) {
         r1 = v;  r2 = u;
         rk = k;
         return true;
      }
   }
   return false;
}

void print_res(int u, int v) {
   fill(turn,0);
   int sz = size(e[u]);
   rep(i,sz) turn[e[u][i]] = u;

   int b = max(s2+rk+1-deg[v],0);
   sz = size(e[v]);
   rep(i,sz) {
      if (s2 < 1) break;
      int z = e[v][i];
      if (z == u) continue;
      if (turn[z] != u) {
         p2.pb(z);
         --s2;
      }
      else if (b > 0) {
         p2.pb(z);
         turn[z] = v;
         --b;
         --s2;
      }
   }

   sz = size(e[u]);
   rep(i,sz) {
      if (s1 < 1) break;
      int z = e[u][i];
      if (z == v) continue;
      if (turn[z] == u) {
         p1.pb(z);
         --s1;
      }
   }

   int s1 = size(p1), s2 = size(p2);
   rep(i,s1) printf("%d ",p1[i]);
   printf("\n");
   rep(i,s2) printf("%d ",p2[i]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("243B.in", "r", stdin);
   freopen("243B.out", "w", stdout);
#endif
   scanf("%d%d%d%d",&n,&m,&s1,&s2);
   fill(deg,0);
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y); ++deg[x];
      e[y].pb(x); ++deg[y];
   }

   bool found = false;
   fill(turn,0);
   foru(i,1,n)
      if (check(i)) {
         found = true;
         break;
      }

   if (found) {
      printf("YES\n");
      printf("%d %d\n",r1,r2);
      print_res(r1,r2);
   }
   else printf("NO");
   return 0;
}
