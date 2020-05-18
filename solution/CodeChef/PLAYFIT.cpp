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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second


int main() {
   freopen("PLAYFIT.in", "r", stdin);
   freopen("PLAYFIT.out", "w", stdout);
   int nTest, n;
   cin >> nTest;
   fab(i, 1, nTest) {
      scanf("%d", &n);
      int a, minA = 1000000000, res = 0;
      fab(j, 1, n) {
         scanf("%d", &a);
         res = max(res, a-minA);
         minA = min(minA, a);
      }
      if (res < 1) printf("UNFIT\n");
      else printf("%d\n", res);
   }
   return 0;
}

