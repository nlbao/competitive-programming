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

const int MAX_N = 1000010;

vector < PI > p;

int main() {
   freopen("COOP4.in", "r", stdin);
   freopen("COOP4.out", "w", stdout);
   int nTest, n, x, y;
   scanf("%d", &nTest);
   fab(i, 1, nTest) {
      scanf("%d", &n);
      fab(j, 1, n) {
         scanf("%d%d", &x, &y);
         p.pb(mp(x, y));
      }
      sort(p.begin(), p.end());
      int res = 1, minX = p[n-1].fr;
      fba(j, n-2, 0)
         if (p[j].sc <= minX) {
            minX = p[j].sc;
            ++res;
         }
      printf("%d\n", res);
   }
   return 0;
}

