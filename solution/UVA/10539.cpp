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

const ll MAX_N = 1000000000007LL;
const int MAX_SQRT_N = 1000007;

int nP;
bool ok[MAX_SQRT_N];
int p[MAX_SQRT_N];

int main() {
   freopen("10539.in", "r", stdin);
   freopen("10539.out", "w", stdout);
   nP = 0;
   fill(ok,true);
   for(ll i = 2; i*i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_SQRT_N; j += i)
            ok[j] = false;
      }

   int nTest;
   ll low, hight;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%I64d%I64d",&low,&hight);
      int res = 0;
      for(int i = 0; i < nP; ++i) {
         ll x = p[i], y = x*x;
         if (y > hight) break;
         int k = 0;
         for(; y <= hight; y *= x)
            if (y >= low) ++k;
         res += k;
      }
      printf("%d\n",res);
   }
   return 0;
}
