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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second


int main() {
   freopen("177B1.in", "r", stdin);
   freopen("177B1.out", "w", stdout);
   int n;
   cin >> n;
   ll res = 1;
   while (n > 1) {
      int d = -1;
      for (int i = 2; i*i <= n; ++i)
         if (n%i == 0) {
            d = i;
            break;
         }
      res += ll(n);
      if (d == -1) break;
      n /= d;
   }
   cout << res;
   return 0;
}

