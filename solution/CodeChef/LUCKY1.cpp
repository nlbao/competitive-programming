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

const int MAX_N = 100010;

int c[15*MAX_N] = {0};
int s[MAX_N] = {0};

int count(int x, int d) {
   int c = 0;
   while (x > 0) {
      if (x%10 == d) ++c;
      x /= 10;
   }
   return c;
}

int main() {
   freopen("LUCKY1.in", "r", stdin);
   freopen("LUCKY1.out", "w", stdout);
   int a = 0, b = 0;
   c[5*MAX_N] = 1;
   fab(i, 1, MAX_N) {
      a += count(i, 4);
      b += count(i, 7);
      int x = a-b+5*MAX_N;
      s[i] = s[i-1]+c[x];
      ++c[x];

   }
   int nTest, n;
   scanf("%d", &nTest);
   fab(i, 1, nTest) {
      scanf("%d", &n);
      printf("%d\n", s[n]);
   }
   return 0;
}
