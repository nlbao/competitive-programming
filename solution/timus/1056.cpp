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

const int MAX_N = 10004;

int n;
VI e[MAX_N];
int f[MAX_N], p[MAX_N], trace[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   ok[u] = false;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (ok[v]) {
         f[v] = f[u]+1;
         trace[v] = u;
         dfs(v);
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1056.in", "r", stdin);
   freopen("1056.out", "w", stdout);
#endif
   scanf("%d",&n);
   foru(i,2,n) {
      int j = read();
      e[j].pb(i);
      e[i].pb(j);
   }

   fill(ok,true);
   f[1] = 1;
   dfs(1);
   int u = 1;
   foru(i,1,n)
      if (f[i] > f[u]) u = i;

   fill(ok,true);
   f[u] = 1;
   dfs(u);
   int v = u;
   foru(i,1,n)
      if (f[i] > f[v]) v = i;

   int c = f[v];
   foru(i,1,c) {
      p[i] = v;
      v = trace[v];
   }

   if (c%2 == 1) printf("%d",p[(c+1)/2]);
   else printf("%d %d",p[(c+1)/2],p[(c+2)/2]);
   return 0;
}
