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

int read() {
   int x;
   scanf("%d",&x);
   return x;
}

int main() {
   freopen("215D.in", "r", stdin);
   freopen("215D.out", "w", stdout);
   ll n = read(), m = read();
   ll res = 0;
   rep(i,n) {
      ll t = read(), T = read(), x = read(), cost = read();
      if (T <= t) res += m*x + cost;
      else {
         //m-a(T-t) <= 0
         ll a = m/(T-t);
         while (a*(T-t) < m) ++a;
         ll s = 0 + a*cost;
         //m-a(T-t) > 0
         ll k = cost-(T-t)*x;
         if (k >= 0) s = min(s,(m+T-t)*x + 1*k);
         else s = min(s,(m+T-t)*x + (a-1)*k);
         res += s;
      }
   }
   cout << res;
   return 0;
}
