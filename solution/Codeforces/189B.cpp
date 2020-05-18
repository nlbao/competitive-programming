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
   freopen("189B.in", "r", stdin);
   freopen("189B.out", "w", stdout);
   int w, h;
   cin >> w >> h;
   ll res = 0;
   foru(i, 0, w-1)
      foru(j, 1, h-1) {
         ll t = (w+i)/2-i;
         ll z = min(j, h-j);
         if (t <= 0 || z <= 0) continue;
         res += t*z;
      }
   cout << res;
   return 0;
}
