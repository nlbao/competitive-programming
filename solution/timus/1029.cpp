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
const int MAX_M = 510;

int n,m;
ll a[MAX_M], f[2][MAX_M];
int trace[MAX_N][MAX_M];

void up(ll &x, ll y, int &i, int j) {
   if (y >= x) return;
   x = y;
   i = j;
}

void print_path(int x, int y) {
   if (x < 1 || y < 1) return;
   if (trace[x][y] == y) print_path(x-1,y);
   else print_path(x,trace[x][y]);
   printf("%d ",y);
}

int main() {
   freopen("1029.in", "r", stdin);
   freopen("1029.out", "w", stdout);
   scanf("%d%d",&n,&m);
   fill(trace,0);
   foru(j,1,m) scanf("%I64d",&f[0][j]);
   int t = 0;
   foru(i,2,n) {
      int tt = (t+1)%2;
      foru(j,1,m) scanf("%I64d",&a[j]);
      foru(j,1,m) {
         f[tt][j] = f[t][j]+a[j];
         trace[i][j] = j;
      }
      foru(j,2,m) up(f[tt][j], f[tt][j-1]+a[j], trace[i][j], j-1);
      ford(j,m-1,1) up(f[tt][j], f[tt][j+1]+a[j], trace[i][j], j+1);
      t = tt;
   }

   ll res = f[t][1], y = 1;
   foru(j,2,m)
      if (f[t][j] < res) {
         res = f[t][j];
         y = j;
      }
   print_path(n,y);
   return 0;
}
