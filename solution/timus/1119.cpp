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

const int MAX_N = 1010;
const double oo = 1000000000.0;

int n,m,q;
bool ok[MAX_N][MAX_N];
double f[2][MAX_N];

void up(int i, int j, double v) {
   if (j < 1 || j > m) return;
   f[i][j] = min(f[i][j],v);
}

int main() {
   freopen("1119.in", "r", stdin);
   freopen("1119.out", "w", stdout);
   scanf("%d%d",&n,&m);
   scanf("%d",&q);
   fill(ok,false);
   rep(i,q) {
      int x,y;
      scanf("%d%d",&x,&y);
      ok[x][y] = true;
   }

   ++n;  ++m;
   foru(i,0,1)
      foru(j,1,m) f[i][j] = oo;
   f[0][1] = 0;
   int t = 0;
   double d = 100.0*sqrt(2.0);
   foru(i,1,n) {
      int tt = (t+1)%2;
      foru(j,1,m) f[tt][j] = oo;
      foru(j,1,m) {
         up(tt,j,f[t][j]+100.0);
         up(t,j+1,f[t][j]+100.0);
         if (ok[i][j]) up(tt,j+1,f[t][j]+d);
      }
      t = tt;
   }
   t = (t+1)%2;
   printf("%.0f",f[t][m]);
   return 0;
}
