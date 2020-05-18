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

vector<PI> w;
VI res;

int main() {
   freopen("203C.in", "r", stdin);
   freopen("203C.out", "w", stdout);
   int n,d,a,b;
   scanf("%d%d",&n,&d);
   scanf("%d%d",&a,&b);
   foru(i,1,n) {
      int x, y;
      scanf("%d%d",&x,&y);
      w.pb(mp(x*a+y*b,i));
   }
   sort(all(w));
   rep(i,n)
      if (w[i].fr <= d) {
         d -= w[i].fr;
         res.pb(w[i].sc);
      }
   int m = size(res);
   printf("%d\n",m);
   rep(i,m) printf("%d ",res[i]);
   return 0;
}
