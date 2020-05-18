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
   freopen("186D.in", "r", stdin);
   freopen("186D.out", "w", stdout);
   double s, a, b, c, x, y, z;
   cin >> s;
   cin >> a >> b >> c;
   if (a+b+c == 0) x = y = z = 0;
   else {
      x = a*s/(a+b+c);
      y = b*s/(a+b+c);
      z = c*s/(a+b+c);
   }
   printf("%.20f %.20f %.20f", x, y, z);
   return 0;
}
