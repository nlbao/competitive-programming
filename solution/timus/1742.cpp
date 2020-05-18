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

const int MAX_N = 100003;

int n, mcount, res;
int d[MAX_N], e[MAX_N], num[MAX_N], low[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs_min(int u) {
   ok[u] = false;
   if (ok[e[u]]) dfs_min(e[u]);
}

int dfs(int u) {
   ok[u] = false;
   num[u] = ++mcount;
   low[u] = n+10;
   int c = 1;
   if (e[u] != u)
      if (ok[e[u]]) {
         c += dfs(e[u]);
         low[u] = min(low[u],low[e[u]]);
      }
      else low[u] = min(low[u],num[e[u]]);
   if (low[u] == num[u]) res -= c-1;
   return c;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1742.in", "r", stdin);
   freopen("1742.out", "w", stdout);
#endif
   fill(d,0);
   scanf("%d",&n);
   foru(i,1,n) {
      scanf("%d",&e[i]);
      if (e[i] != i) ++d[e[i]];
   }

   res = 0;
   fill(ok,true);
   foru(i,1,n)
      if (d[i] == 0) {
         ++res;
         dfs_min(i);
      }
   foru(i,1,n)
      if (ok[i]) {
         ++res;
         dfs_min(i);
      }
   printf("%d ",res);

   res = n;
   mcount = 0;
   fill(ok,true);
   foru(i,1,n)
      if (d[i] == 0) dfs(i);
   foru(i,1,n)
      if (ok[i]) dfs(i);
   printf("%d",res);
   return 0;
}
