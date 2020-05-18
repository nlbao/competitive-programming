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

const int MAX_N = 207;
const int oo = 1000000000;

int n;
int a[MAX_N], deg[MAX_N], sz[MAX_N], d[MAX_N];
int q[4][MAX_N], l[4], r[4], next[4];
VI e[MAX_N];

bool is_empty(int i) {  return l[i] > r[i];  }

int solve(int x) {
   fill(r,0);
   l[1] = l[2] = l[3] = 1;
   foru(i,1,n)
      if (deg[i] == 0) q[a[i]][++r[a[i]]] = i;

   if (is_empty(x)) return oo;

   int res = 0;
   while (1) {
      while (!is_empty(x)) {
         ++res;
         int u = q[x][l[x]++];
         rep(i,sz[u]) {
            int v = e[u][i];
            if (--deg[v] == 0) q[a[v]][++r[a[v]]] = v;
         }
      }
      if (!is_empty(next[x])) x = next[x], ++res;
      else if (!is_empty(next[next[x]])) x = next[next[x]], res += 2;
      else return res;
   }
}

int main() {
   freopen("214C.in", "r", stdin);
   freopen("214C.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);
   fill(deg,0);
   foru(i,1,n) {
      int k;
      scanf("%d",&k);
      rep(j,k) {
         int x;
         scanf("%d",&x);
         e[x].pb(i);
         ++deg[i];
      }
   }

   next[1] = 2;   next[2] = 3;   next[3] = 1;
   foru(i,1,n) sz[i] = size(e[i]);

   int res = oo;
   foru(i,1,3) {
      foru(j,1,n) d[j] = deg[j];
      res = min(res,solve(i));
      foru(j,1,n) deg[j] = d[j];
   }
   printf("%d",res);
   return 0;
}
