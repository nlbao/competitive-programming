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

const int MAX_N = 100007;

int n;
int a[MAX_N], c[13];
int len[3], plen[3], sum[3], psum[3], f[3][13], pf[3][13];

int main() {
   freopen("214B.in", "r", stdin);
   freopen("214B.out", "w", stdout);
   fill(c,0);
   scanf("%d",&n);
   rep(i,n) {
      scanf("%d",&a[i]);
      ++c[a[i]];
   }
   if (c[0] == 0) {
      printf("-1");
      return 0;
   }

   fill(f,0);
   fill(len,0);
   fill(sum,0);
   len[0] = f[0][0] = c[0];
   rep(i,n) {
      if (a[i] == 0) continue;
      rep(j,3) {
         plen[j] = len[j];
         psum[j] = sum[j];
         foru(k,1,9) pf[j][k] = f[j][k];
      }
      rep(j,3) {
         if (plen[j] == 0) continue;
         int r = (j+a[i])%3, l = plen[j]+1;
         if (l > len[r] || (l == len[r] && psum[j]+a[i] > sum[r])) {
            len[r] = plen[j]+1;
            sum[r] = psum[j]+a[i];
            foru(k,1,9) f[r][k] = pf[j][k];
            ++f[r][a[i]];
         }
      }
   }

   if (len[0] == c[0]) f[0][0] = 1;
   ford(i,9,0)
      rep(j,f[0][i]) printf("%d",i);
   return 0;
}
