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

const int MAX_N = 1000007;
const int MAX_M = 257;

int n, m;
ll x[MAX_M], y[MAX_M], f[MAX_N];

int main() {
   freopen("183B.in", "r", stdin);
   freopen("183B.out", "w", stdout);
   cin >> n >> m;
   foru(i, 1, m) {
      int xx, yy;
      scanf("%d%d", &xx, &yy);
      x[i] = xx;  y[i] = yy;
   }
   fill(f, 0);
   foru(i, 1, m)
      foru(j, i+1, m) {
         ll a = y[i]-y[j], b = x[j]-x[i];
         if (a == 0) continue;
         ll c = a*x[i]+b*y[i], t = c/a;
         if (c%a == 0 && 1 <= t && t <= n) {
            ll s = 0;
            foru(k, 1, m)
               if (a*x[k]+b*y[k] == c) ++s;
            f[t] = max(f[t], s);
         }
      }
   ll res = 0;
   foru(i, 1, n)
      if (!f[i]) ++res;
      else res += f[i];
   cout << res;
   return 0;
}
