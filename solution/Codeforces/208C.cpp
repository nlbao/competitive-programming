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

const int MAX_N = 103;
const int MAX_M = 10010;
const ll oo = 1000000000000000LL;

int n,m;
ll f[MAX_N][MAX_N], g[MAX_N][MAX_N];

int main() {
   freopen("208C.in", "r", stdin);
   freopen("208C.out", "w", stdout);
   scanf("%d%d",&n,&m);
   foru(i,1,n) {
      foru(j,1,n) {
         f[i][j] = oo;
         g[i][j] = 0;
      }
      f[i][i] = 0;
      g[i][i] = 1;
   }
   rep(i,m) {
      int x,y;
      scanf("%d%d",&x,&y);
      f[x][y] = f[y][x] = 1;
      g[x][y] = g[y][x] = 1;
   }

   foru(k,1,n)
      foru(i,1,n) {
         if (i == k) continue;
         foru(j,1,n) {
            if (i == j || j == k) continue;
            ll d = f[i][k]+f[k][j];
            if (d < f[i][j]) {
               f[i][j] = d;
               g[i][j] = g[i][k]*g[k][j];
            }
            else if (d == f[i][j]) g[i][j] += g[i][k]*g[k][j];
         }
      }

   double res = 1;
   foru(i,1,n) {
      if (i == 1 || i == n) continue;
      if (f[1][i]+f[i][n] != f[1][n]) continue;
      res = max(res,double(2*g[1][i]*g[i][n])/double(g[1][n]));
   }
   printf("%.7f",res);
   return 0;
}
