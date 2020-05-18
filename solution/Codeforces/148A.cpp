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

int main() {
   int d, res = 0;
   int a[4];
   freopen("148A.in", "r", stdin);
   fab(i, 0, 3) cin >> a[i];
   cin >> d;
   fab(i, 1, d) {
      bool ok = false;
      fab(j, 0, 3)
         if (i%a[j] == 0) ok = true;
      if (ok) ++ res;
   }
   cout << res << endl;
   return 0;
}
