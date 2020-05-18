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

ll gcd(ll a, ll b, ll &x, ll &y) {
   if (a == 0) {
      x = 0;   y = 1;
      return b;
   }
   ll x1, y1;
   ll d = gcd(b%a,a,x1,y1);
   x = y1-(b/a)*x1;
   y = x1;
   return d;
}

int main() {
   freopen("1286.in", "r", stdin);
   freopen("1286.out", "w", stdout);
   ll p,q,x1,y1,x2,y2,x,y;
   cin >> p >> q;
   cin >> x1 >> y1;
   cin >> x2 >> y2;
   ll dx = x2-x1, dy = y2-y1;
   ll d = gcd(abs(p),abs(q),x,y);

   string res = "YES";
   if (dx%d != 0) res = "NO";
   if (dy%d != 0) res = "NO";
   if (res == "YES") {
      dx /= d;
      x1 = x*dx;  y1 = y*dx;
      dy /= d;
      x2 = x*dy;  y2 = y*dy;
      if ((x2+y2-x1-y1)%2 != 0) {
         if (abs(p-q)%2 == 0 && (abs(p/d-q/d)%2 == 0)) res = "NO";
      }

   }
   cout << res;
   return 0;
}
