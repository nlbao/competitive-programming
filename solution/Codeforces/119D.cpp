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

const int MAX_N = 1000007;

char a[MAX_N], b[2*MAX_N], r[2*MAX_N];
int z[2*MAX_N], kmp[2*MAX_N];

int main() {
   freopen("119D.in", "r", stdin);
   freopen("119D.out", "w", stdout);
   gets(a);
   gets(b);
   int n = strlen(a), m = strlen(b);
   if (n != m) {
      printf("-1 -1");
      return 0;
   }

   rep(i, n) b[m+i] = a[i];
   fill(z, 0);
   for(int l = 0, r = 0, i = 1; i < m+n; ++i) {
      if (i <= r) z[i] = min(r-i+1, z[i-l]);
      while (i+z[i] < m+n && b[i+z[i]] == b[z[i]]) ++z[i];
      if (i+z[i]-1 > r) {
         l = i;
         r = i+z[i]-1;
      }
   }

   rep(i, n) r[i] = a[n-i-1];
   rep(i, m) r[n+i+1] = b[i];
   r[n] = char(31);
   kmp[0] = 0;
   foru(i, 1, n+m) {
      int j = kmp[i-1];
      while (j && r[j] != r[i]) j = kmp[j-1];
      if (r[j] == r[i]) ++j;
      kmp[i] = j;
   }

   int x = -1, y = -1;
   rep(p, n-1) {
      if (a[p] != b[m-p-1]) break;
      int i = p+1, j = z[m+i], k = kmp[n+m-i];
      if (j+k >= n-i) {
         x = p;
         y = m-k;
      }
   }
   printf("%d %d",x,y);
   return 0;
}
