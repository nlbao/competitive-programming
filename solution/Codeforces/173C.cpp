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

const int MAX_N = 505;
const int oo = 1000000000;

int n, m;
int a[MAX_N][MAX_N], s[MAX_N][MAX_N];
int f[2][MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int get_s(int x1, int y1, int x2, int y2) {
   return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("173C.in", "r", stdin);
   freopen("173C.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   int res = -oo;
   foru(i,1,n)
      foru(j,1,m)
         scanf("%d",&a[i][j]);

   fill(s,0);
   foru(i,1,n)
      foru(j,1,m)
         s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];

   int t = 0;
   foru(i,1,n)
      foru(j,1,m)
         f[t][i][j] = a[i][j];

   for(int k = 3; k <= min(m,n); k += 2) {
      int tt = t;
      t = (t+1)&1;
      foru(i,1,n-k+1)
         foru(j,1,m-k+1) {
            f[t][i][j] = get_s(i,j,i+k-1,j+k-1) - f[tt][i+1][j+1] - a[i+1][j];
            res = max(res,f[t][i][j]);
         }
   }
   cout << res;
   return 0;
}
