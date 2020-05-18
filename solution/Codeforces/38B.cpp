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

bool crock(int x1, int y1, int x2, int y2) {
   if (x1 == x2 || y1 == y2) return false;
   return true;
}

bool cknight(int x1, int y1, int x2, int y2) {
   int d1 = abs(x1-x2), d2 = abs(y1-y2);
   if (d1+d2 == 3 && (d1 == 1 || d2 == 1)) return false;
   return true;
}

int main() {
   freopen("38B.in", "r", stdin);
   freopen("38B.out", "w", stdout);
   char a, b;
   int y1, y2;
   cin >> a >> y1;
   cin >> b >> y2;
   int x1 = a-'a'+1, x2 = b-'a'+1, res = 0;

   foru(i, 1, 8)
      foru(j, 1, 8) {
         if ((i == x1 && j == y1) || (i == x2 && j == y2)) continue;
         if (crock(x1,y1,i,j) && cknight(i,j,x1,y1) && cknight(i,j,x2,y2))
            ++res;
      }
   cout << res << endl;
   return 0;
}
