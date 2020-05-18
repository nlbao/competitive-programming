#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fillchar(a,x) memset(a, (x), sizeof(a));

typedef long long ll;

int main() {
   int res = 0;
   fab(i, 1, 1000)
      fab(j, i+1, 1000-i) {
         int k = 1000-i-j;
         if (i*i+j*j == k*k) res = i*j*k;
      }
   cout << res;
   return 0;
}
