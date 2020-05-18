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

const int limit = 1000000;

int main() {
   freopen("175A.in", "r", stdin);
   freopen("175A.out", "w", stdout);
   string s;
   getline(cin, s);
   int n = s.size()-1;
   bool ok = false;
   ll res = -limit, x = 0;
   foru(i, 0, n-2) {
      if ((s[0] == '0') && (i > 0)) break;
      x = x*10+ll(s[i])-ll('0');
      if (x > limit) break;
      ll y = 0;
      foru(j, i+1, n-1) {
         if ((s[i+1] == '0') && (j > i+1)) break;
         y = y*10+ll(s[j])-ll('0');
         if ((s[j+1] == '0') && (j+1 < n)) continue;
         if (y > limit) break;
         ll z = 0;
         foru(k, j+1, n) {
            z = z*10+ll(s[k])-ll('0');
            if (z > limit) break;
         }
         if (z > limit) break;
         z = z+x+y;
         if (z > res) {
            ok = true;
            res = z;
         }
      }
   }
   if (!ok) cout << -1 << endl;
   else cout << res << endl;
   return 0;
}

