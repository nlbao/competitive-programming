#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(ll i = (a); i <= (b); ++i)
#define fba(i,b,a) for(ll i = (b); i >= (a); --i)
#define fillchar(a,x) memset( a, (x), sizeof(a));

typedef long long ll;

const int MAX_N = 2000000;

bool p[MAX_N];

int main() {
   ll res = 0, k = 1;
   for (ll k = 1; res == 0; ++k) {
      ll s = k*(k+1)/2, t = 1;
      for(ll i = 2; i*i <= s; ++i) {
         ll c = 0;
         while (s%i == 0) {
            s /= i;
            ++c;
         }
         t *= (c+1);
      }
      if (s > 1) t *= 2;
      if (t >= 500) res = k*(k+1)/2;
   }
   cout << res;
   return 0;
}
