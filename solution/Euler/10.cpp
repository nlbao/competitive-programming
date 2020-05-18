#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fillchar(a,x) memset(a, (x), sizeof(a));

typedef long long ll;

const int MAX_N = 2000000;

bool p[MAX_N];

int main() {
   ll res = 0;
   fillchar(p, true);
   fab(i, 2, MAX_N)
      if (p[i]) {
         res += i;
         for (int j = i+i; j <= MAX_N; j += i)
            p[j] = false;
      }
   cout << res;
   return 0;
}
