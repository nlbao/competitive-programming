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

using namespace std;

typedef long long ll;
/*typedef long double ll;
typedef long long ll2;*/
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

const ll oo = 2000000000LL;

ll x, y, fx, fy, z;

void swap(ll &x, ll &y) {
   ll t = x;
   x = y;
   y = t;
}

ll check(ll v) {
   ll a = v, b = fx;
   foru(i,x+1,y) {
      ll t = a+b;
      /*if (t > oo) return fy+1;
      if (t < -oo) return fy-1;*/
      if (t > oo) t = oo+1;
      if (t < -oo) t = -oo-1;
      a = b;
      b = t;
   }
   return b;
}

ll solve() {
   if (z == x) return fx;
   if (z == y) return fy;
   if (z < x) {
      ford(i,x-1,z) {
         ll t = fy-fx;
         fy = fx;
         fx = t;
      }
      return fx;
   }
   foru(i,y+1,z) {
      ll t = fx+fy;
      fx = fy;
      fy = t;
   }
   return fy;
}

int main() {
   freopen("1133.in", "r", stdin);
   freopen("1133.out", "w", stdout);
   cin >> x >> fx >> y >> fy >> z;
   if (x > y) {
      swap(x,y);
      swap(fx,fy);
   }


   ll l = -oo, r = oo;
   while (l <= r) {
      ll mid = (l+r)/2, t = check(mid);
      //cout << mid << " " << t <<  "     " << l << " " << r << endl;
      if (t == fy) {
         //cout << mid << endl;
         y = x-1;
         fy = mid;
         swap(x,y);
         swap(fx,fy);
         break;
      }
      else if (t < fy) l = mid+1;
      else r = mid-1;
   }

   /*cout << x << " " << fx << endl;
   cout << y << " " << fy << endl;*/

   cout << solve();
   return 0;
}
