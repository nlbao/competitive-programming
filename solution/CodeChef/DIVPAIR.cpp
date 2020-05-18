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


int main() {
   freopen("DIVPAIR.in", "r", stdin);
   freopen("DIVPAIR.out", "w", stdout);
   int nTest, a, b;
   cin >> nTest;
   rep(testid, nTest) {
      scanf("%d%d", &a, &b);
      ll n = a, m = b;
      ll x = n/m, y = n%m, res, limit = m/2;
      if (m%2 != 0) res = (m-1)*x*x/2 + y*x + x*(x-1)/2;
      else {
         res = (m-2)*x*x/2 + y*x + x*(x-1);
         --limit;
      }
      if (m-y <= limit) res += limit-m+y+1;
      cout << res << endl;
      //printf("%lld\n", res);
   }
   return 0;
}
