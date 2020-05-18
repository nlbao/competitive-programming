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

int p[1007];

int main() {
   freopen("A.in", "r", stdin);
   freopen("A.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(i, 1, nTest) {
      int c, n, x, r1 = 0, r2 = 0;
      fill(p, 0);
      scanf("%d", &c);
      scanf("%d", &n);
      foru(j, 1, n) {
         scanf("%d", &x);
         if ((x < c) && (p[c-x] > 0)) {
            r1 = p[c-x];
            r2 = j;
         }
         p[x] = j;
      }
      printf("Case #%d: %d %d\n", i, r1, r2);
   }
   return 0;
}

