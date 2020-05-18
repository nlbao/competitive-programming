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

const int MAX_N = 1000000000;
const int MAX_P = 31650;

int nP, n;
bool is_prime[MAX_P];
int p[MAX_P];

int main() {
   freopen("10179.in", "r", stdin);
   freopen("10179.out", "w", stdout);
   fill(is_prime,true);
   nP = 0;
   foru(i,2,MAX_P-3)
      if (is_prime[i]) {
         p[nP++] = i;
         int j = i+i;
         while (j < MAX_P) {
            is_prime[j] = false;
            j += i;
         }
      }

   for(;;) {
      scanf("%d",&n);
      if (n == 0) break;
      if (n == 1) {
         printf("0\n");
         continue;
      }
      int res = n;
      rep(i,nP) {
         int x = p[i];
         if (x > n) break;
         else if (n%x == 0) {
            res -= res/x;
            while (n%x == 0) n /= x;
         }
      }
      if (n > 1) res -= res/n;
      printf("%d\n",res);
   }
   return 0;
}
