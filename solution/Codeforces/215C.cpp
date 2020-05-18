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

ll n;

int read() {
   int x;
   scanf("%d",&x);
   return x;
}

//ll f(ll a, ll b, ll c, ll d) {   return (n-2*max(a,c))*(m-2*max(b,d));  }

int main() {
   freopen("215C.in", "r", stdin);
   freopen("215C.out", "w", stdout);
   ll n = read(), m = read(), s = read(), res = 0;

   for(ll a = 0; 2*a+1 <= n; ++a)
      for(ll b = 0; 2*b+1 <= m; ++b) {
         //c <= a
         for(ll c = 0; c <= a && 2*c+1 <= n; ++c) {
            //d <= b
            if (4*a*b+2*(a+b)+1 == s) res += (n-2*a)*(m-2*b)*(b+1);
            //d > b
            ll x = s-4*(b*c-a*b)-2*a-1;
            ll y = 4*c+2;
            ll d = x/y;
            if (x%y == 0 && d > b && 2*d+1 <= m) res += (n-2*a)*(m-2*d);
         }
         //c == a


         //c > a
         for(ll c = a+1; 2*c+1 <= n; ++c) {
            //d < b
            ll x = s-4*a*b-2*(b+c)-1;
            ll y = 4*(c-a);
            ll d = x/y;
            if (x%y == 0 && d >= 0 && d < b) res += (n-2*c)*(m-2*b);
            //d >= b
            x = s-2*c-1;
            y = 4*c+2;
            d = x/y;
            if (x%y == 0 && d >= b && 2*d+1 <= m) res += (n-2*c)*(m-2*d);
         }
         //cout << a << " " << b << " " << res << endl;
      }

   cout << res;
   return 0;
}
