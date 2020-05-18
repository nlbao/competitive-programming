#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
//#include <math.h>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fillchar(a,x) memset(a, (x), sizeof(a));

const int MAX_N = 1010;

int x1, y1, x2, y2, n;
int x[MAX_N], y[MAX_N], r[MAX_N];

void swap(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

int check(int x0, int y0) {
   fab(i, 1, n)
      if ((x0-x[i])*(x0-x[i])+(y0-y[i])*(y0-y[i]) <= r[i]*r[i])
         return 0;
   return 1;
}

int main() {
   freopen("144B.in", "r", stdin);
   freopen("144B.out", "w", stdout);
   cin >> x1 >> y1 >> x2 >> y2;
   if (x1 > x2) swap(x1, x2);
   if (y1 > y2) swap(y1, y2);
   cin >> n;
   fab(i, 1, n) cin >> x[i] >> y[i] >> r[i];
   int c = 0;
   fab(i, x1, x2) c += check(i, y1)+check(i, y2);
   fab(i, y1+1, y2-1) c += check(x1, i)+check(x2, i);
   cout << c;
   return 0;
}

