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

const int MAX_N = 77777;

int main() {
   freopen("MAXCOUNT.in", "r", stdin);
   freopen("MAXCOUNT.out", "w", stdout);
   int nTest, n;
   scanf("%d", &nTest);
   fab(i, 1, nTest) {
      vector<int> a;
      scanf("%d", &n);
      fab(j, 1, n) {
         int x;
         scanf("%d", &x);
         a.pb(x);
      }
      sort(a.begin(), a.end());
      int c = 0, v = 1000000, j = 0;
      while (j <= n-1) {
         int k = j;
         while ((k < n-1) && (a[k+1] == a[j])) ++k;
         if (k-j+1 > c) {
            c = k-j+1;
            v = a[j];
         }
         j = k+1;
      }
      printf("%d %d\n", v, c);
   }
   return 0;
}

