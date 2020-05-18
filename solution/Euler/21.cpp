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

ll d[MAX_N];

int main() {
   freopen("Euler.out", "w", stdout);
   int n = 10000;
   fillchar(d, 0);
   fab(i, 1, MAX_N)
      for(int j = i+i; j <= MAX_N; j += i) {
         d[j] += i;
         if (j == 284) cout << i << " " << d[j] << endl;
      }

   ll res = 0;
   fab(i, 2, n)
      if ((d[i] != i) && (d[d[i]] == i)) res += i;
   cout << d[220] << " " << d[284] << endl;
   cout << res;
   return 0;
}
