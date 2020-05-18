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

VI e[MAX_N];
int a[MAX_N], p[MAX_N], f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   f[u] = 0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (p[v] == 0) {
         p[v] = u;
         dfs(v);
      }
   }

   int c = 0;
   rep(i,sz) {
      int v = e[u][i];
      if (p[v] == u) a[c++] = f[v];
   }
   sort(a,a+c);
   rep(i,c) f[u] = max(f[u],a[i]+c-i);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1362.in", "r", stdin);
   freopen("1362.out", "w", stdout);
#endif
   fill(p,0);
   int n = read();
   foru(i,1,n)
      while(1) {
         int x = read();
         if (x == 0) break;
         e[i].pb(x);
         e[x].pb(i);
      }
   int root = read();

   fill(p,0);
   p[root] = -1;
   dfs(root);
   printf("%d\n",f[root]);
   return 0;
}
