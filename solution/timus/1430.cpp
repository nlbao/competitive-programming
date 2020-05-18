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

void swap(ll &x, ll &y) {
   ll t = x;
   x = y;
   y = t;
}

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
   freopen("1430.in", "r", stdin);
   freopen("1430.out", "w", stdout);
   ll a, b, n, x = 0, y = 0;
   cin >> a >> b >> n;
   bool ok = true;
   if (a < b) {
      swap(a,b);
      ok = false;
   }
   ll limit = min(n/a,b-1), f = 0;
   for(ll i = 0; i <= limit; ++i) {
      ll s = a*i, j = (n-s)/b;
      s += j*b;
      if (s > f) {
         f = s;
         x = i;   y = j;
      }
      if (f == n) break;
   }
   if (!ok) swap(x,y);
   cout << x << " " << y << endl;
   return 0;
}
