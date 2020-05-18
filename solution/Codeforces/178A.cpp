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

const int MAX_N = 100007;

ll a[MAX_N];

int main() {
   freopen("178A.in", "r", stdin);
   freopen("178A.out", "w", stdout);
   int n;
   cin >> n;
   foru(i, 1, n) {
      int x;
      scanf("%d", &x);
      a[i] = x;
   }
   ll res = 0;
   ll limit = 0;
   while (1<<(limit+1) <= n) ++limit;
   foru(i, 1, n-1) {
      int l = 0, r = limit, t = 0;
      while (l <= r) {
         int mid = (l+r)/2;
         if (i+(1<<mid) <= n) {
            t = mid;
            l = mid+1;
         }
         else r = mid-1;
      }
      a[i+(1<<t)] += a[i];
      res += a[i];
      cout << res <<endl;
   }

   return 0;
}
