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
int s[MAX_N][MAX_N], f[MAX_N][MAX_N];
bool g[MAX_N][MAX_N], h[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int get_s(int i, int j1, int j2) {
   if (j1 == 0) return s[i][j2];
   return s[i][j2]-s[i][j1-1];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1221.in", "r", stdin);
   freopen("1221.out", "w", stdout);
#endif
   while(1) {
      scanf("%d",&n);
      if (n == 0) break;
      foru(i,1,n) {
         s[i][0] = 0;
         foru(j,1,n)
            s[i][j] = s[i][j-1]+(1-read());
      }

      foru(i,1,n)
         foru(j,1,n) {
            f[i][j] = -1;
            for(int k = 0; j-k > 0 && j+k <= n; ++k)
               if (get_s(i,j-k,j+k) == 2*k+1) f[i][j] = k;
               else break;
         }

      foru(j,1,n) g[1][j] = true;
      foru(i,2,n)
         foru(j,1,n) {
            int len = f[i][j];
            if (f[i][j] == 0) g[i][j] = true;
            else g[i][j] = g[i-1][j] && (f[i-1][j] == len-1) && (2*f[i-1][j]+1 == get_s(i-1,j-len,j+len));
         }

      foru(j,1,n) h[n][j] = true;
      ford(i,n-1,1)
         foru(j,1,n) {
            int len = f[i][j];
            if (f[i][j] == 0) h[i][j] = true;
            else h[i][j] = h[i+1][j] && (f[i+1][j] == len-1) && (2*f[i+1][j]+1 == get_s(i+1,j-len,j+len));
         }

      int res = 0;
      foru(i,2,n-1)
         foru(j,2,n-1) {
            int len = f[i-1][j]+1;
            if (f[i-1][j] != f[i+1][j] || f[i][j] < len) continue;
            if (i-1 < len || n-i < len) continue;
            if (get_s(i-1,j-len,j+len) != 2*f[i-1][j]+1) continue;
            if (get_s(i+1,j-len,j+len) != 2*f[i+1][j]+1) continue;
            if (g[i-1][j] && h[i+1][j])
               res = max(res, 2*len+1);
         }

      if (res < 3) printf("No solution\n");
      else printf("%d\n",res);
   }
   return 0;
}
