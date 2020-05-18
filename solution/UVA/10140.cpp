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

const ll MAX_R = 2147483660LL;
const int MAX_LEN = 1000007;
const int MAX_N = 77777;
const ll MAX_S = 100000LL;
const int MAX_P = 8007;

int nP;
bool ok[MAX_LEN];
ll p[MAX_P];
int a[MAX_LEN];

int main() {
   freopen("10140.in", "r", stdin);
   freopen("10140.out", "w", stdout);
   nP = 0;
   fill(ok,true);
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }

   ll left, right;
   while(cin >> left >> right) {
      int nA = 0;
      ll start = -MAX_S;
      for(ll k = 0, maxk = MAX_R/MAX_S; k <= maxk; ++k) {
         start += MAX_S;
         if (start > right) break;
         if (start+MAX_S-1 < left) continue;
         fill(ok,true);
         rep(i,nP) {
            ll start_idx = (start+p[i]-1)/p[i];
            ll j = max(start_idx,2LL)*p[i]-start;
            for(; j < MAX_S; j += p[i])
               ok[j] = false;
         }
         if (k == 0) ok[0] = ok[1] = false;
         for(ll i = 0; i < MAX_S; ++i) {
            ll j = start+i;
            if (j > right) break;
            if (ok[i] && j >= left) a[nA++] = j;
         }
      }

      if (nA < 2) {
         printf("There are no adjacent primes.\n");
         continue;
      }
      int c1 = 0, c2 = 2147483640, d1 = 0, d2 = 0;
      foru(i,1,nA-1) {
         ll t = a[i]-a[i-1];
         if (t < c2-c1) {  c1 = a[i-1];   c2 = a[i];  }
         if (t > d2-d1) {  d1 = a[i-1];   d2 = a[i];  }
      }
      printf("%d,%d are closest, %d,%d are most distant.\n",c1,c2,d1,d2);
   }
   return 0;
}
