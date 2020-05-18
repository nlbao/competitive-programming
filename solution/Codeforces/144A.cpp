#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fillchar(a,x) memset(a, (x), sizeof(a));


void swap(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

int main() {
   freopen("144A.in", "r", stdin);
   freopen("144A.out", "w", stdout);
   int n;
   int a[100];
   scanf("%d", &n);
   fab(i, 1, n) scanf("%d", &a[i]);

   int minA = 1000, p = n, res = 0;
   fba(i, n, 1)
      if (a[i] < minA) {
         minA = a[i];
         p = i;
      }
   fab(i, p, n-1) swap(a[i], a[i+1]);
   res = n-p;

   int maxA = 0;  p = 1;
   fab(i, 1, n)
      if (a[i] > maxA) {
         maxA = a[i];
         p = i;
      }
   res += p-1;
   cout << res;
   return 0;
}

