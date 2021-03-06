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

const int MAX_N = 33;
const int oo = 2000000000;

int n;
int a[MAX_N];
map<int, int> f;

int solve(int mask) {
   int c0 = 0, c1 = 0, res = oo;
   rep(i, n)
      if (mask&(1<<i)) ++c1;
      else ++c0;
   if (c0 == 0) return 0;
   if (c1 >= c0) return 1;
   if (f.find(mask) != f.end()) return f[mask];

   rep(i, n) {
      int x = mask, t = -1;
      c0 = c1 = 0;
      foru(j, i, n-1) {
         if (mask&(1<<j)) ++c1;
         else {
            ++c0;
            x |= 1<<j;
         }
         if (c0 && c1 >= c0) t = x;
      }
      if (t > -1) res = min(res, 1+solve(t));
   }
   return f[mask] = res;
}

int main() {
   freopen("MEDIAN.in", "r", stdin);
   freopen("MEDIAN.out", "w", stdout);
   int nTest;
   cin >> nTest;
   rep(id, nTest) {
      f.clear();
      int maxA = 0, mask = 0;
      scanf("%d", &n);
      rep(i, n) {
         scanf("%d", &a[i]);
         maxA = max(maxA, a[i]);
      }
      rep(i, n)
         if (a[i] == maxA) mask |= 1<<i;
      cout << solve(mask) << endl;
   }
   return 0;
}
