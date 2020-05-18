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

const int MAX_N = 307;
const int oo = 1000000000;

int n;
int a[MAX_N][MAX_N], f[2][MAX_N][MAX_N];

int max(int x, int y, int z, int t) {
   if (y > x) x = y;
   if (t > z) z = t;
   if (x > z) return x;
   else return z;
}


int main() {
   freopen("214E.in", "r", stdin);
   freopen("214E.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n)
      foru(j,1,n) scanf("%d",&a[i][j]);
   if (n == 1) {
      printf("%d",a[1][1]);
      return 0;
   }

   foru(i,0,n)
      foru(j,0,n) f[0][i][j] = f[1][i][j] = -oo;
   int t = 0;
   f[t][1][1] = a[1][1];
   foru(k,3,2*n) {
      int tt = (t+1)%2;
      int l = max(k-n,1), r = min(k-1,n);
      foru(i,l,r)
         foru(j,l,r)
            if (i == j)
               f[tt][i][j] = max(f[t][i-1][j-1],f[t][i-1][j],f[t][i][j-1],f[t][i][j]) + a[k-i][i];
            else
               f[tt][i][j] = max(f[t][i-1][j-1],f[t][i-1][j],f[t][i][j-1],f[t][i][j]) + a[k-i][i]+a[k-j][j];
      t = tt;
   }

   cout << f[t][n][n];
   return 0;
}
