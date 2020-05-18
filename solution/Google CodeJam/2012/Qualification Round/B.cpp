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

bool is_triplet(int a, int b, int c) {
   if ((a < 0) || (b < 0) || (c < 0)) return false;
   if ((a > 10) || (b > 10) || (c > 10)) return false;
   if ((abs(a-b) > 2) || (abs(b-c) > 2) || (abs(c-a) > 2)) return false;
   return true;
}

int main() {
   //freopen("B.in", "r", stdin);
   //freopen("B.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) {
      int n, s, p, t, res = 0;
      scanf("%d%d%d", &n, &s, &p);
      foru(i, 1, n) {
         scanf("%d", &t);
         bool ok = false, no_surprising = false;
         foru(x, p, t)
            foru(y, x-2, x+2) {
               int z = t-x-y;
               if (!is_triplet(x, y, z)) continue;
               ok = true;
               if ((abs(x-y) < 2) && (abs(y-z) < 2) && (abs(z-x) < 2)) no_surprising = true;
            }
         if (ok)
            if (no_surprising) ++res;
            else if (s > 0) {
               --s;
               ++res;
            }
      }
      printf("Case #%d: %d\n", testid, res);
   }
   return 0;
}

