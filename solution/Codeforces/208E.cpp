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

const int MAX_N = 100010;
const int MAX_P = 20;

int n, nPos;
VI e[MAX_N], a[MAX_N];
int h[MAX_N], pos[MAX_N], nChild[MAX_N], p[MAX_N][MAX_P];


void dfs(int u) {
   pos[u] = ++nPos;
   a[h[u]].pb(nPos);
   nChild[u] = 0;

   foru(i,1,MAX_P-1)
      if (p[u][i-1] < 1) p[u][i] = 0;
      else p[u][i] = p[p[u][i-1]][i-1];

   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      h[v] = h[u]+1;
      dfs(v);
      nChild[u] += nChild[v]+1;
   }
}

int get_p(int u, int t) {
   ford(i,MAX_P-1,0)
      if (h[u]-(1<<i) >= t) u = p[u][i];
   return u;
}

int solve(int u, int t) {
   if (t >= h[u]) return 0;
   int root = get_p(u,h[u]-t);
   int low = pos[root]+1, up = pos[root]+nChild[root];
   if (a[h[u]][0] > up || a[h[u]][size(a[h[u]])-1] < low) return 0;
   VI::iterator l = a[h[u]].begin(), r = a[h[u]].end();
   return upper_bound(l,r,up)-1-lower_bound(l,r,low);
}

int main() {
   freopen("208E.in", "r", stdin);
   freopen("208E.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n) {
      int x;
      scanf("%d",&x);
      if (x > 0) e[x].pb(i);
      p[i][0] = x;
   }

   nPos = 0;
   foru(i,1,n)
      if (p[i][0] == 0) {
         h[i] = 1;
         dfs(i);
      }

   int m;
   scanf("%d",&m);
   rep(i,m) {
      int u,t;
      scanf("%d%d",&u,&t);
      printf("%d ",solve(u,t));
   }
   return 0;
}
