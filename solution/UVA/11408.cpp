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

const int MAX_N = 5000007;

bool ok[MAX_N];
ll s[MAX_N];
int f[MAX_N];

int main() {
   freopen("11408.in", "r", stdin);
   freopen("11408.out", "w", stdout);
   fill(s,0);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         s[i] += i;
         for(int j = i+i; j < MAX_N; j += i) {
            s[j] += i;
            ok[j] = false;
         }
      }

   f[0] = f[1] = 0;
   for(int i = 2; i < MAX_N; ++i)
      f[i] = f[i-1]+(s[i] < MAX_N && ok[s[i]]);

   for(;;) {
      int a, b, res;
      scanf("%d",&a);
      if (a == 0) break;
      scanf("%d",&b);
      if (a > b) res = 0;
      else res = f[b]-f[a-1];
      printf("%d\n",res);
   }
   return 0;
}
