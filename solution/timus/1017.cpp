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

const int MAX_N = 502;

ll s[MAX_N][MAX_N];

int main() {
   freopen("1017.in", "r", stdin);
   freopen("1017.out", "w", stdout);
   int n;
   scanf("%d",&n);
   s[1][0] = 0;
   s[1][1] = 1LL;
   foru(i,2,n) {
      s[i][0] = 0;
      foru(j,1,i-1)
         s[i][j] = s[i][j-1] + s[i-j][min(j-1,i-j)];
      s[i][i] = s[i][i-1]+1;
   }
   printf("%I64d\n",s[n][n-1]);
   return 0;
}
