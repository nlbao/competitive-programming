#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(ll i = (a); i <= (b); ++i)
#define fba(i,b,a) for(ll i = (b); i >= (a); --i)
#define fillchar(a,x) memset( a, (x), sizeof(a));

typedef long long ll;

const int MAX_N = 22;

ll f[MAX_N][MAX_N];

int main() {
   freopen("Euler.out", "w", stdout);
   int n = 21;
   fab(i, 1, n) {
      f[i][1] = 1;
      f[1][i] = 1;
   }
   fab(i, 2, n)
      fab(j, 2, n)
         f[i][j] = f[i-1][j]+f[i][j-1];
   cout << f[n][n];
   return 0;
}
