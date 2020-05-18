#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_X = 1002;

int a[MAX_X][MAX_X], b[MAX_X][MAX_X];

int main() {
   freopen("159B.in", "r", stdin);
   freopen("159B.out", "w", stdout);
   int n, m;
   cin >> n >> m;
   fill(a, 0);
   fill(b, 0);
   fab(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      ++a[x][y];
   }
   fab(i, 1, m) {
      int x, y;
      scanf("%d%d", &x, &y);
      ++b[x][y];
   }

   int r1 = 0, r2 = 0;
   fab(i, 1, 1000)
      fab(j, 1, 1000) {
         int t = min(a[i][j], b[i][j]);
         r1 += t;
         r2 += t;
         a[i][j] -= t;
         b[i][j] -= t;
      }
   fab(j, 1, 1000) {
      int sa = 0, sb = 0;
      fab(i, 1, 1000) {
         sa += a[i][j];
         sb += b[i][j];
      }
      int t = min(sa, sb), t1 = t;
      r1 += t;
      sa -=t;
      sb -= t;
      fab(i, 1, 1000) {
         int k = min(t, sa);
         t -= k;  sa -= k;
         k = min(t1, sb);
         t1 -= k; sb -= k;
      }
   }
   cout << r1 << " " << r2 << endl;
   return 0;
}


