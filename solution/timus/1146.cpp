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

const int MAX_N = 110;

int n;
int s[MAX_N][MAX_N],f[MAX_N][MAX_N];

int main() {
   freopen("1146.in", "r", stdin);
   freopen("1146.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n)
      foru(j,1,n) scanf("%d",&s[i][j]);

   foru(j,1,n) s[j][0] = 0;
   foru(j,1,n)
      foru(i,1,n)
         s[j][i] += s[j][i-1];

   int res = -200*MAX_N*MAX_N;
   foru(x,1,n)
      foru(y,x,n) {
         int f = 0;
         foru(j,1,n) {
            if (f < 0) f = s[j][y]-s[j][x-1];
            else f += s[j][y]-s[j][x-1];
            res = max(res,f);
         }
      }
   printf("%d",res);
   return 0;
}
