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

const int MAX_N = 200002;
const ll MAX_K = 12158598919ll;

int f[MAX_N];
ll s[MAX_N];

int gcd(int x, int y) {
   if (x == 0 || y == 0) return x+y;
   return gcd(y,x%y);
}

int main() {
   freopen("11327.in", "r", stdin);
   freopen("11327.out", "w", stdout);
   s[0] = 0;
   foru(j,1,MAX_N-1) {
      int n = j;
      f[j] = n;
      for(int i = 2; i*i <= n; ++i)
         if (n%i == 0) {
            f[j] -= f[j]/i;
            while (n%i == 0) n /= i;
         }
      if (n > 1) f[j] -= f[j]/n;
      s[j] = s[j-1]+ll(f[j]);
   }
   ll k;
   for(;;) {
      scanf("%I64d",&k);
      if (k == 0) break;
      if (--k == 0) {
         printf("0/1\n");
         continue;
      }
      int l = 1, r = MAX_N-1, i = 1;
      while (l <= r) {
         int mid = (l+r)/2;
         if (s[mid] >= k) {
            i = mid;
            r = mid-1;
         }
         else l = mid+1;
      }
      k -= s[i-1];
      foru(j,1,i)
         if (gcd(i,j) == 1 && --k == 0) {
            printf("%d/%d\n",j,i);
            break;
         }
   }
   return 0;
}
