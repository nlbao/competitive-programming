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

const int MAX_N = 2004;
const ll MODUN = 1000000007LL;

char a[MAX_N], b[MAX_N];
int f[MAX_N][MAX_N];
ll g[MAX_N][MAX_N];

void up(int i, int j, int ff, ll gg) {
   if (ff > f[i][j]) return;
   if (ff < f[i][j]) {
      f[i][j] = ff;
      g[i][j] = gg;
   }
   else g[i][j] = (g[i][j]+gg)%MODUN;
}

int main() {
   freopen("1577.in", "r", stdin);
   freopen("1577.out", "w", stdout);
   scanf("%s",&a);
   scanf("%s",&b);
   int n = strlen(a), m = strlen(b);

   foru(i,0,n)
      foru(j,0,m) {
         f[i][j] = n+m+10000;
         g[i][j] = 0;
      }
   f[0][0] = 0;
   g[0][0] = 1;

   foru(i,0,n)
      foru(j,0,m) {
         if (g[i][j] == 0) continue;
         if (i < n && j < m && a[i] == b[j]) {
            up(i+1,j+1,f[i][j]+1,g[i][j]);
            continue;
         }
         if (i < n) up(i+1,j,f[i][j]+1,g[i][j]);
         if (j < m) up(i,j+1,f[i][j]+1,g[i][j]);
      }
   cout << g[n][m];
   return 0;
}
