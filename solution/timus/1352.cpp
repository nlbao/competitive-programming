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
   freopen("1352.in", "r", stdin);
   freopen("1352.out", "w", stdout);
   int a[40];
   a[0] = 0;
   a[1] = 2;
   a[2] = 3;
   a[3] = 5;
   a[4] = 7;
   a[5] = 13;
   a[6] = 17;
   a[7] = 19;
   a[8] = 31;
   a[9] = 61;
   a[10] = 89;
   a[11] = 107;
   a[12] = 127;
   a[13] = 521;
   a[14] = 607;
   a[15] = 1279;
   a[16] = 2203;
   a[17] = 2281;
   a[18] = 3217;
   a[19] = 4253;
   a[20] = 4423;
   a[21] = 9689;
   a[22] = 9941;
   a[23] = 11213;
   a[24] = 19937;
   a[25] = 21701;
   a[26] = 23209;
   a[27] = 44497;
   a[28] = 86243;
   a[29] = 110503;
   a[30] = 132049;
   a[31] = 216091;
   a[32] = 756839;
   a[33] = 859433;
   a[34] = 1257787;
   a[35] = 1398269;
   a[36] = 2976221;
   a[37] = 3021377;
   a[38] = 6972593;
   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      printf("%d\n",a[n]);
   }
   return 0;
}
