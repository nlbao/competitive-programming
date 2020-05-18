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

int nP;
bool ok[MAX_S];
int p[MAX_P], f[MAX_P];

int find(int n) {
   int l = 0, r = nP-1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] == n) return mid;
      else if (p[mid] < n) l = mid+1;
      else r = mid-1;
   }
   return -1;
}

int solve(int n) {
   int l = 0, r = nP-1, res = -1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (p[mid] > n) r = mid-1;
      else {
         res = mid;
         l = mid+1;
      }
   }
   if (res < 0) return 0;
   return f[res];
}

int main() {
   freopen("HS08PAUL.in", "r", stdin);
   freopen("HS08PAUL.out", "w", stdout);
   int cnt = 0;
   fill(ok,true);
   for(int i = 2; i < MAX_SQRT_N; ++i)
      if (ok[i]) {
         p[cnt++] = i;
         for(int j = i*i; j < MAX_SQRT_N; j += i) ok[j] = false;
      }
   nP = 0;
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

   fill(f,0);
   int r = sqrt(MAX_SQRT_N)+1;
   rep(i,MAX_SQRT_N) {
      int x = i*i;
      if (x > MAX_N) break;
      rep(j,r) {
         int y = j*j;
         y = x+y*y;
         if (y > MAX_N) break;
         int k = find(y);
         if (k > 0) f[k] = 1;
      }
   }
   f[0] = 1;
   foru(i,1,nP-1) f[i] += f[i-1];

   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      printf("%d\n",solve(n));
   }
   return 0;
}
