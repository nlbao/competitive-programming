#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1007;
const int oo = 1000000000;

int n, m;
ll h[MAX_N][MAX_N], f[MAX_N][MAX_N][2];
ll res;

bool ok(int types, ll h1, ll h2, ll f) {
   if ((f == -1) || (h1 == h2)) return false;
   if (types == 0) {
      if (h1 > h2) return true;
   }
   else if (h1 < h2) return true;
   return false;
}

int main() {
   freopen("IITI02.in", "r", stdin);
   freopen("IITI02.out", "w", stdout);
   cin >> m >> n;
   fab(i, 1, m)
      fab(j, 1, n) {
         int x;
         scanf("%d", &x);
         h[i][j] = ll(x);
   }

   ll res = h[1][1];
   f[1][1][0] = f[1][1][1] = h[1][1];
   fab(j, 2, n)
      fab(k, 0, 1) {
         f[1][j][k] = -1;
         int kk = (k+1)%2;
         if (ok(k, h[1][j], h[1][j-1], f[1][j-1][kk])) f[1][j][k] = f[1][j-1][kk]+h[1][j];
         res = max(res, f[1][j][k]);
      }
   fab(i, 2, m)
      fab(k, 0, 1) {
         f[i][1][k] = -1;
         int kk = (k+1)%2;
         if (ok(k, h[i][1], h[i-1][1], f[i-1][1][kk])) f[i][1][k] = f[i-1][1][kk]+h[i][1];
         res = max(res, f[i][1][k]);
      }

   fab(i, 2, m)
      fab(j, 2, n) {
         fab(k, 0, 1) {
            f[i][j][k] = -1;
            int kk = (k+1)%2;
            if (ok(k, h[i][j], h[i][j-1], f[i][j-1][kk]))
               f[i][j][k] = max(f[i][j][k], f[i][j-1][kk]+h[i][j]);
            if (ok(k, h[i][j], h[i-1][j], f[i-1][j][kk]))
               f[i][j][k] = max(f[i][j][k], f[i-1][j][kk]+h[i][j]);
            res = max(res, f[i][j][k]);
         }
      }
   cout << res << endl;
   return 0;
}
