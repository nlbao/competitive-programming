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
   freopen("160A.in", "r", stdin);
   freopen("160A.out", "w", stdout);
   int n, s1 = 0, s2 = 0, c = 0;
   int a[107];
   scanf("%d", &n);
   fab(i, 0, n-1) {
      scanf("%d", &a[i]);
      s2 += a[i];
   }
   sort(a, a+n);
   fba(i, n-1, 0) {
      ++c;
      s1 += a[i];
      s2 -= a[i];
      if (s1 > s2) {
         cout << c << endl;
         break;
      }
   }
   return 0;
}


