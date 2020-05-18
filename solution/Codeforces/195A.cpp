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


int main() {
   freopen("195A.in", "r", stdin);
   freopen("195A.out", "w", stdout);
   int a,b,c;
   cin >> a >> b >> c;
   int res = c*a;
   foru(i,0,c*a) {
      if ((i*b)/(a-b) >= c) {
         res = i;
         break;
      }
   }
   cout << res;
   return 0;
}
