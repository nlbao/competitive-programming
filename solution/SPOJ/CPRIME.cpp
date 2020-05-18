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

const int MAX_N = 100000007;
const int MAX_SQRT_N = 10007;
const int MAX_S = 10000;
const int MAX_P = 5761460;

int nP;
bool is_prime[MAX_SQRT_N];
int a[MAX_SQRT_N], p[MAX_P];

double solve(int n) {
   double t = n*1.0/log(n), c = 0;
   int l = 0, r = nP-1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] <= n) l = c = mid+1;
      else r = mid-1;
   }
   t = c-t;
   if (t < 0) t = -t;
   return t/c*100;
}

int main() {
   freopen("CPRIME.in", "r", stdin);
   freopen("CPRIME.out", "w", stdout);
   int cnt = 0;
   fill(is_prime,true);
   for(int i = 2; i < MAX_SQRT_N; ++i)
      if (is_prime[i]) {
         a[cnt++] = i;
         for(ll j = i*1LL*i; j < MAX_SQRT_N; j += i)
            is_prime[j] = false;
      }

   nP = 0;
   for(int k = 0, maxk = MAX_N/MAX_S; k <= maxk; ++k) {
      fill(is_prime,true);
      int start = k*MAX_S;
      rep(i, cnt) {
         int start_idx = (start+a[i]-1)/a[i];
         int j = max(start_idx,2)*a[i]-start;
         for(; j < MAX_S; j += a[i]) is_prime[j] = false;
      }
      if (k == 0) is_prime[0] = is_prime[1] = false;
      for(int i = 0; i < MAX_S && start+i <= MAX_N; ++i)
         if (is_prime[i]) p[nP++] = start+i;
   }

   for(;;) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      printf("%.1f\n",solve(n));
   }
   return 0;
}
