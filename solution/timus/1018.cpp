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

const int MAX_N = 110;
const int oo = 5000000;

int n,q;
vector<PI> e[MAX_N];
bool ok[MAX_N];
int f[MAX_N][MAX_N];

void dfs(int u) {
   ok[u] = false;
   f[u][0] = 0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].fr;
      if (ok[v]) {
         dfs(v);
         ford(j,q,1)
            rep(k,j)
               f[u][j] = max(f[u][j],f[u][j-k-1] + f[v][k] + e[u][i].sc);
      }
   }
}

int main() {
#ifdef DEBUG
   freopen("1018.in", "r", stdin);
   freopen("1018.out", "w", stdout);
#endif
   scanf("%d%d",&n,&q);
   rep(i,n) {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      e[x].pb(mp(y,z));
      e[y].pb(mp(x,z));
   }
   foru(i,1,n) {
      ok[i] = true;
      rep(j,q+1) f[i][j] = -oo;
   }
   dfs(1);
   cout << f[1][q] << endl;
   return 0;
}
