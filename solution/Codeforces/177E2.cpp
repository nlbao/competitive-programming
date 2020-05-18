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

const int MAX_N = 11111;

int n, c;
ll a[MAX_N], b[MAX_N];

ll cal(ll x) {
   ll sum = n;
   foru(i, 1, n) {
      if (a[i] && x/b[i] > c/a[i]) return c+1;
      sum += (x*a[i])/b[i];
      if (sum > c) return c+1;
   }
   return sum;
}

int main() {
   freopen("177E1.in", "r", stdin);
   freopen("177E1.out", "w", stdout);
   cin >> n >> c;
   ll sumA = 0;
   foru(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[i] = x;   b[i] = y;
      sumA += x;
   }
   if (sumA == 0) {
      if (c == n) cout << -1;
      else cout << 0;
      return 0;
   }

   ll limit = 1000000000000000000ll;
   ll l = 1, r = limit, l0 = 0, r0 = -1;
   while (l <= r) {
      ll mid = (l+r)/2, v = cal(mid);
      if (v >= c) {
         if (v == c) l0 = mid;
         r = mid-1;
      }
      else l = mid+1;
   }

   l = 1;   r = limit;
   while (l <= r) {
      ll mid = (l+r)/2, v = cal(mid);
      if (v <= c) {
         if (v == c) r0 = mid;
         l = mid+1;
      }
      else r = mid-1;
   }
   cout << r0-l0+1;
   return 0;
}

