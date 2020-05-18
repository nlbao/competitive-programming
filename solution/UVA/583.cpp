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

const int MAX_N = 50010;

int nP = 0;
bool ok[MAX_N];
int p[MAX_N];

int main() {
   freopen("583.in", "r", stdin);
   freopen("583.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j < MAX_N; j += i)
            ok[j] = false;
      }

   for(;;) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      printf("%d = ",n);
      bool ok = true;
      if (n < 0) {
         printf("-1");
         n = -n;
         ok = false;
      }
      rep(i,nP) {
         ll x = p[i];
         if (x*x > n) break;
         while (n%x == 0) {
            if (ok) {
               printf("%d",x);
               ok = false;
            }
            else printf(" x %d",x);
            n /= x;
         }
      }
      if (n > 1)
         if (ok) printf("%d",n);
         else printf(" x %d",n);
      printf("\n");
   }
   return 0;
}
