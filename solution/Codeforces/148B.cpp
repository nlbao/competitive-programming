#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

int solve(double vp, double vd, double delay, double f, double c) {
   if (vp >= vd) return 0;
   int res = 0;
   double x = vp*delay;
   while (x < c) {
      double t = x/(vd-vp);
      double y = vd*t;
      if (y >= c) break;
      ++res;
      x = y+vp*(f+y/vd);
   }
   return res;
}

int main() {
   freopen("148B.in", "r", stdin);
   double vp, vd, t, f, c;
   cin >> vp >> vd >> t >> f >> c;
   cout << solve(vp, vd, t, f, c);
   return 0;
}
