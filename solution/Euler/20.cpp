#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(ll i = (a); i <= (b); ++i)
#define fba(i,b,a) for(ll i = (b); i >= (a); --i)
#define fillchar(a,x) memset( a, (x), sizeof(a));

typedef long long ll;

const int MAX_M = 5010;

ll f[MAX_M];

int main() {
   freopen("Euler.out", "w", stdout);
   int n = 100, m = 1;
   f[1] = 1;
   fab(i, 2, n) {
      int nho = 0;
      fab(j, 1, m) {
         f[j] = f[j]*i+nho;
         nho = f[j]/10;
         f[j] %= 10;
      }
      while (nho > 0) {
         f[++m] = nho%10;
         nho /= 10;
      }
   }
   ll res = 0;
   fab(i, 1, m) res += f[i];
   cout << res << " " << m;
   return 0;
}
