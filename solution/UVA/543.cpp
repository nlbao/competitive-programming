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

int nP;
bool ok[MAX_N];
int p[MAX_N];

int main() {
   freopen("543.in", "r", stdin);
   freopen("543.out", "w", stdout);
   nP = 0;
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j += j; j < MAX_N; j += i)
            ok[j] = false;
      }

   int nTest, n;
   for(;;) {
      scanf("%d",&n);
      if (n == 0) break;
      int res = 0;
      for(int i = 0; i < nP && n-p[i] > 2; ++i)
         if (ok[n-p[i]]) {
            res = p[i];
            break;
         }
      if (res > 0) printf("%d = %d + %d\n",n,res,n-res);
      else printf("Goldbach's conjecture is wrong.\n");
   }
   return 0;
}
