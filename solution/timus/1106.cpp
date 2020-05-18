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

const int MAX_N = 110;

int n, m, c0 = 0;
VI e[MAX_N];
int deg[MAX_N], f[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   ok[u] = false;
   if (f[u] == 0) ++c0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (ok[v]) {
         f[v] = 1-f[u];
         dfs(v);
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1106.in", "r", stdin);
   freopen("1106.out", "w", stdout);
#endif
   scanf("%d",&n);
   foru(i,1,n)
      while (1) {
         int j = read();
         if (j == 0) break;
         e[i].pb(j);
         ++deg[j];
      }

   foru(i,1,n)
      if (deg[i] == 0) {
         printf("0");
         return 0;
      }

   fill(ok,true);
   foru(i,1,n)
      if (ok[i]) {
         f[i] = 0;
         dfs(i);
      }

   printf("%d\n",c0);
   foru(i,1,n)
      if (f[i] == 0) printf("%d ",i);
   return 0;
}
