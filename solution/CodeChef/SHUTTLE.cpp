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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define VI vector< int >

const int MAX_N = 10010;
int f[MAX_N];

int main() {
   freopen("SHUTTLE.in", "r", stdin);
   freopen("SHUTTLE.out", "w", stdout);
   int nTest, n, res;
   fill(f, 0);
   fab(i, 1, MAX_N) {
      int j = i+i;
      while (j <= MAX_N) {
         ++f[j];
         j += i;
      }
   }
   cin >> nTest;
   fab(i, 1, nTest) {
      scanf("%d", &n);
      printf("%d\n", n-f[n]);
   }
   return 0;
}
