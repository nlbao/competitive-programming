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
const int MAX_S = 11000;
const int MAX_P = 5761465;

int nP = 0, cnt = 0;
bool ok[MAX_S];
int p[MAX_P];

bool is_prime(int n) {
   int l = 0, r = nP-1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] == n) return true;
      else if (p[mid] < n) l = mid+1;
      else r = mid-1;
   }
   return false;
}

int find(int n) {
   int l = 0, r = nP-1, t = 0;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] >= n) r = mid-1;
      else {
         t = mid;
         l = mid+1;
      }
   }
   return t;
}

int main() {
   freopen("10311.in", "r", stdin);
   freopen("10311.out", "w", stdout);
   fill(ok,true);
   for(int i = 2; i < MAX_SQRT_N; ++i)
      if (ok[i]) {
         p[cnt++] = i;
         ll j = i;
         for(j *= j; j < MAX_SQRT_N; j += i)
            ok[j] = false;
      }
   for(int k = 0, maxk = MAX_N/MAX_S; k <= maxk; ++k) {
      int start = k*MAX_S;
      fill(ok,true);
      rep(i,cnt) {
         int start_idx = (start+p[i]-1)/p[i];
         int j = max(start_idx,2)*p[i]-start;
         for(; j < MAX_S; j += p[i]) ok[j] = false;
      }
      if (k == 0) ok[0] = ok[1] = false;
      for(int i = 0; i < MAX_S && start+i < MAX_N; ++i)
         if (ok[i]) p[nP++] = start+i;
   }

   int n;
   while (scanf("%d",&n) == 1) {
      int p1 = 0, p2 = 0;
      if (n > 4) {
         if (n%2 == 1) {
            if (is_prime(n-2)) p1 = 2;
         }
         else {
            int i = find(n/2);
            for(; i >= 0; --i)
               if (is_prime(n-p[i])) {
                  p1 = p[i];
                  break;
               }
         }
         p2 = n-p1;
      }
      if (p1 == 0) printf("%d is not the sum of two primes!\n",n);
      else printf("%d is the sum of %d and %d.\n",n,p1,p2);
   }
   return 0;
}
