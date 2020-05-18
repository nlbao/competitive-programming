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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 111;
const int MAX_M = 55;
const int oo = 1000000000;

char s[MAX_N];
int f[MAX_N][MAX_M][2], g[MAX_N][MAX_M][2];


int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("132C.in", "r", stdin);
   freopen("132C.out", "w", stdout);
#endif
   scanf("%s",&s);
   int n = strlen(s), m = read();
   foru(i,0,1) f[0][0][i] = g[0][0][i] = 0;
   f[0][1][0] = f[0][1][1] = oo;
   g[0][1][0] = g[0][1][1] = -oo;
   foru(i,1,n) {
      bool ok = (s[i-1] == 'T');
      if (ok) {
         f[i][0][0] = f[i-1][0][1];    f[i][0][1] = f[i-1][0][0];
         g[i][0][0] = g[i-1][0][1];    g[i][0][1] = g[i-1][0][0];
      }
      else {
         f[i][0][0] = f[i-1][0][0]-1;  f[i][0][1] = f[i-1][0][1]+1;
         g[i][0][0] = g[i-1][0][0]-1;  g[i][0][1] = g[i-1][0][1]+1;
      }

      foru(j,1,m) {
         f[i][j][0] = f[i][j][1] = oo;
         g[i][j][0] = g[i][j][1] = -oo;
      }

      foru(j,1,min(i,m))
         if (ok) {
            f[i][j][0] = min(f[i-1][j-1][0]-1, f[i-1][j][1]);
            f[i][j][1] = min(f[i-1][j-1][1]+1, f[i-1][j][0]);
            g[i][j][0] = max(g[i-1][j-1][0]-1, g[i-1][j][1]);
            g[i][j][1] = max(g[i-1][j-1][1]+1, g[i-1][j][0]);
         }
         else {
            f[i][j][0] = min(f[i-1][j-1][1], f[i-1][j][0]-1);
            f[i][j][1] = min(f[i-1][j-1][0], f[i-1][j][1]+1);
            g[i][j][0] = max(g[i-1][j-1][1], g[i-1][j][0]-1);
            g[i][j][1] = max(g[i-1][j-1][0], g[i-1][j][1]+1);
         }
   }

   int res = 0;
   foru(k,0,1) {
      int t = abs(f[n][m][k]);
      if (t < 2*n)
         res = max(res,t);
      t = abs(g[n][m][k]);
      if (t < 2*n)
         res = max(res,t);
   }
   cout << res;
   return 0;
}
