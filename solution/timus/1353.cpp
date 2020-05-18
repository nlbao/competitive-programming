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

const int MAX_S = 90;

int f[12][MAX_S], g[MAX_S];

int solve(int s) {
   if (s == 1) return 10;
   fill(f,0);
   fill(g,0);
   rep(i,10) g[i] = f[1][i] = f[i][0] = 1;
   int res = 0;
   foru(i,2,9) {
      foru(j,1,s) {
         int r = min(j,9);
         if (r == j) {
            f[i][j] = 1;
            --r;
         }
         foru(k,1,r) f[i][j] += g[j-k];
      }
      foru(j,1,s) g[j] += f[i][j];
      res += f[i][s];
   }
   if (s < 10) ++res;
   return res;
}

int main() {
   freopen("1353.in", "r", stdin);
   freopen("1353.out", "w", stdout);
   int s;
   scanf("%d",&s);
   printf("%d",solve(s));
   return 0;
}
