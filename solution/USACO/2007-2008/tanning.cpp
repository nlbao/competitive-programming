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

const int MAX_N = 2510;
const int MAX_M = 2510;

vector < PI > a, b;

int main() {
   freopen("tanning.in", "r", stdin);
   freopen("tanning.out", "w", stdout);
   int n, m, x, y, res = 0;
   scanf("%d%d", &n, &m);
   fab(i, 1, n) {
      scanf("%d%d", &x, &y);
      a.pb(mp(y, x));
   }
   fab(i, 1, m) {
      scanf("%d%d", &x, &y);
      b.pb(mp(x, y));
   }
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   fab(i, 0, n-1)
      fab(j, 0, m-1)
         if (b[j].fr > a[i].fr) break;
         else if ((b[j].sc > 0) && (b[j].fr >= a[i].sc)) {
            ++res;
            --b[j].sc;
            break;
         }
   cout << res << endl;
   return 0;
}


