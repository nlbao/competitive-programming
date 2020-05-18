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

const int MAX_N = 31622780;
const int MAX_SQRT_N = 6000;
const int MAX_S = 10000;
const int MAX_P = 1951980;

int nP = 0;
bool ok[MAX_S];
ll p[MAX_N];


ll find(ll n) {
   if (n < 4) return -1;
   ll res = -1, c = 0;

   if (n%2 == 0) {
      ++c;
      res = 2;
      while (n%2 == 0) n /= 2;
   }

   ll sqrtn = sqrt(n*1.0)+2;
   rep(i,nP) {
      ll x = p[i];
      if (x > n) break;
      if (n%x == 0) {
         ++c;
         res = x;
         while (n%x == 0) n /= x;
      }
   }

   if (n > 1) res = n, ++c;
   if (c == 1) return -1;
   return res;
}

int main() {
   freopen("11466.in", "r", stdin);
   freopen("11466.out", "w", stdout);
   int cnt = 0;
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(ll i = 2; i < MAX_SQRT_N; ++i)
      if (ok[i]) {
         p[cnt++] = i;
         for(ll j = i*i; j < MAX_SQRT_N; j += i)
            ok[j] = false;
      }
   for(int k = 0, maxk = MAX_N/MAX_S; k <= maxk; ++k) {
      fill(ok,true);
      int start = k*MAX_S;
      rep(i,cnt) {
         ll start_idx = (start+p[i]-1)/p[i];
         for(ll j = max(start_idx,2LL)*p[i]-start; j < MAX_S; j += p[i])
            ok[j] = false;
      }
      if (k == 0) ok[0] = ok[1] = false;
      for(ll i = 0; i < MAX_S && start+i < MAX_N; ++i)
         if (ok[i]) p[nP++] = start+i;
   }

   for(;;) {
      ll n;
      scanf("%I64d",&n);
      if (n == 0) break;
      if (n < 0) n = -n;
      ll res = find(n);
      printf("%I64d\n",res);
   }
   return 0;
}
