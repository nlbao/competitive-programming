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

const int MAX_N = 6002;
const int k = 2;

int n;
VI e[MAX_N];
int p[MAX_N], f[MAX_N][2], s[2*MAX_N];

void dfs(int u, int h) {
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      dfs(v,h+1);
      f[u][0] += max(f[v][0],f[v][1]);
   }
   f[u][1] += s[h+k];
   s[h+k] = 0;
   s[h] += max(f[u][0],f[u][1]);
}

int main() {
   freopen("1039.in", "r", stdin);
   freopen("1039.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n) {
      p[i] = f[i][0] = 0;
      scanf("%d",&f[i][1]);
   }
   for(;;) {
      int x,y;
      scanf("%d%d",&x,&y);
      if (x == 0) break;
      e[y].pb(x);
      p[x] = y;
   }

   int res = 0;
   fill(s,0);
   foru(i,1,n)
      if (p[i] == 0) {
         dfs(i,i);
         res += max(f[i][0],f[i][1]);
      }
   printf("%d",res);
   return 0;
}
