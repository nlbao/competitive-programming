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

int a[100007];

int main() {
   freopen("160C.in", "r", stdin);
   freopen("160C.out", "w", stdout);
   int n;
   ll k;
   cin >> n >> k;
   fab(i, 0, n-1) scanf("%d", &a[i]);
   sort(a, a+n);
   int i = 0;
   while (i < n) {
      int j = i;
      while ((j+1 < n) && (a[j+1] == a[i])) ++j;
      int l = j-i+1;
      if (k > n*l) k -= n*l;
      else {
         int t = k/l;
         if (t*l < k) ++t;
         if (t > 0) --t;
         printf("%d %d", a[i], a[t]);
         break;
      }
      i = ++j;
   }
   return 0;
}
