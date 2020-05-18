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

const int MAX_N = 10000007;
const int MAX_SQRT_N = 3200;
const int MAX_S = 10000;
const int MAX_P = 664590;

int nP = 0;
bool is_prime[MAX_S+10];
int a[MAX_SQRT_N], p[MAX_P];

int solve(int n) {
   int m = (n/2)+1;
   if (m > n) return 0;
   int l = 0, r = nP-1, i = nP+1, j = 0;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] > n) r = mid-1;
      else {
         j = mid;
         l = mid+1;
      }
   }
   l = 0, r = j;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] < m) l = mid+1;
      else {
         i = mid;
         r = mid-1;
      }
   }
   if (i > j) return 0;
   return j-i+1;
}

int main() {
   freopen("FINDPRM.in", "r", stdin);
   freopen("FINDPRM.out", "w", stdout);
   int cnt = 0;
   fill(is_prime,true);
   for(int i = 2; i < MAX_SQRT_N; ++i)
      if (is_prime[i]) {
         a[cnt++] = i;
         for(ll j = i*1LL*i; j < MAX_SQRT_N; j += i)
            is_prime[j] = false;
      }

   for(int k = 0, maxk = MAX_N/MAX_S; k <= maxk; ++k) {
      fill(is_prime,true);
      int start = k*MAX_S;
      rep(i,cnt) {
         int start_idx = (start+a[i]-1)/a[i];
         int j = max(start_idx,2)*a[i]-start;
         for(; j < MAX_S; j += a[i]) is_prime[j] = false;
      }
      if (k == 0) is_prime[0] = is_prime[1] = false;
      for(int i = 0; i < MAX_S && start+i < MAX_N; ++i)
         if (is_prime[i]) p[nP++] = start+i;
   }

   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      printf("%d\n",solve(n));
   }
   return 0;
}
