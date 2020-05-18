#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 10000010;
const int MAX_K = 10;
const int MAX_F = 12;
const int MAX_L = 1000;

int main() {
   freopen("cowids.in", "r", stdin);
   freopen("cowids.out", "w", stdout);
   int n, k;
   int f[MAX_F], res[MAX_L];
   int g[MAX_F][MAX_K];
   scanf("%d%d", &n, &k);
   int tk = k;
   f[0] = 1;
   fab(i, 1, MAX_F)
      f[i] = f[i-1]*i;
   fab(i, 0, k)
      fab(j, i, MAX_F)
         g[j][i] = (f[j]/f[i])/f[j-i];

   fab(i, 0, MAX_L) res[i] = 1;
   int len = --k;
   while (g[len][k] < n) {
      n -= g[len][k];
      ++len;
   }
   fab(i, 1, len) {
      if ((n < 1) || (len-i < k)) break;
      if (n > g[len-i][k]) {
         res[i] = 1;
         n -= g[len-i][k];
         --k;
      }
      else res[i] = 0;
   }
   if ((n > 0) && (len+1 > tk)) res[len] = 0;
   fab(i, 0, len) cout << res[i];
   cout << endl;
   return 0;
}
