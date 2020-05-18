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

int main() {
   freopen("165B.in", "r", stdin);
   freopen("165B.out", "w", stdout);
   ll n, k;
   cin >> n >> k;
   ll l = 0, r = n, res = 0;
   while (l <= r) {
      ll mid = (l+r)/2, c = mid, t = 1, j = mid;
      while (j != 0) {
         t = t*k;
         j = mid/t;
         c += j;
      }
      if (c >= n) {
         res = mid;
         r = mid-1;
      }
      else l = mid+1;
   }
   cout << res << endl;
   return 0;
}


