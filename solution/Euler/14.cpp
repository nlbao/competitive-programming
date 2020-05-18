#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(ll i = (a); i <= (b); ++i)
#define fba(i,b,a) for(ll i = (b); i >= (a); --i)
#define fillchar(a,x) memset( a, (x), sizeof(a));

typedef long long ll;

const int MAX_N = 1000000;

ll f[MAX_N];

int main() {
   ll rl = 0, rn = 0;
   fillchar(f, 0);
   f[1] = 1;
   fab(i, 1, MAX_N) {
      ll j = i, c = 0;
      while ((j > MAX_N) || (f[j] == 0)) {
         if (j%2 == 0) j /= 2;
         else j = 3*j+1;
         ++c;
      }
      f[i] = f[j]+c;
      if (f[i] > rl) {
         rl = f[i];
         rn = i;
      }
   }
   cout << rn;
   return 0;
}
