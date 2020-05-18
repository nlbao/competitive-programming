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

vector<PI> a;

int main() {
   freopen("205D.in", "r", stdin);
   freopen("205D.out", "w", stdout);
   int n;
   scanf("%d",&n);
   rep(i,n) {
      int x,y;
      scanf("%d%d",&x,&y);
      a.pb(mp(x,1));
      if (y != x) a.pb(mp(y,0));
   }

   sort(all(a));

   int nA = size(a), limit = (n/2)+(n%2), res = n+1;
   for(int i = 0, j = 0; i < nA; i = j) {
      int s = 0;
      while (j < nA && a[j].fr == a[i].fr)
         s += a[j++].sc;
      if (j-i >= limit)
         if (s >= limit) {
            res = 0;
            break;
         }
         else res = min(res,limit-s);
   }
   if (res > n) res = -1;
   printf("%d",res);
   return 0;
}
