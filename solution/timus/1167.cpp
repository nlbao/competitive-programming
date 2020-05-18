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

const int MAX_N = 510;
const int MAX_M = MAX_N;
const int oo = 1000000000;

int n,m;
int s[MAX_N];
int g[MAX_N][MAX_N], f[MAX_N][MAX_M];

int main() {
   freopen("1167.in", "r", stdin);
   freopen("1167.out", "w", stdout);
   scanf("%d%d",&n,&m);
   s[0] = 0;
   foru(i,1,n) {
      int x;
      scanf("%d",&x);
      s[i] = s[i-1]+x;
   }

   foru(i,1,n)
      foru(j,1,n) {
         f[i][j] = oo;
         int t = s[j]-s[i-1];
         g[i][j] = t*(j-i+1-t);
      }

   foru(i,1,n) f[i][1] = g[1][i];
   foru(i,2,n) {
      foru(j,2,min(i-1,m))
         foru(k,1,i-j+1)
            f[i][j] = min(f[i][j],f[i-k][j-1]+g[i-k+1][i]);
      f[i][i] = 0;
   }

   printf("%d",f[n][m]);
   return 0;
}
