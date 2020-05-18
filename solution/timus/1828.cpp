#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1828.in", "r", stdin);
   freopen("1828.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   double a = n, b = 0, c = 0, d = 0, e = 0, f = 0;
   foru(i,1,n) {
      double x = read();
      b += i*i*1.0;
      c += i;
      d -= x;
      e -= x*i*1.0;
      f += x*x*1.0;
   }
   c *= 2;
   d *= 2;
   e *= 2;

   printf("%.2f %.2f %.2f %.2f %.2f %.2f\n",a,b,c,d,e,f);

   double t = (2*a*e*c + d*c*c)/(4*b + 2*e*c);
   double r = -2*e*t/(4*b*t - c*c);
   double b1 = -d/(2*a-t) + r;
   printf("%.6f %.6f",b1,r);
   return 0;
}
