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

const int MAX_N = 1000010;
const int MAX_P = 80000;

int nP = 0;
bool ok[MAX_N];
int p[MAX_P];

int main() {
   freopen("10948.in", "r", stdin);
   freopen("10948.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }

   for(;;) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      printf("%d:\n",n);
      if (n%2 == 1) {
         if (ok[n-2]) printf("%d+%d\n",2,n-2);
         else printf("NO WAY!\n");
      }
      else
         rep(i,nP)
            if (p[i] > n) break;
            else
               if (ok[n-p[i]]) {
                  printf("%d+%d\n",p[i],n-p[i]);
                  break;
               }
   }
   return 0;
}
