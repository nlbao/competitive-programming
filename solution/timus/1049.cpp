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

const int MAX_N = 10010;

int c[MAX_N];

int main() {
   freopen("1049.in", "r", stdin);
   freopen("1049.out", "w", stdout);
   fill(c,0);
   rep(id,10) {
      int n;
      scanf("%d",&n);
      for(int i = 2; i*i <= n; ++i)
         while (n%i == 0) {
            ++c[i];
            n /= i;
         }
      if (n > 1) ++c[n];
   }

   int res = 1;
   foru(i,2,MAX_N)
      if (c[i])
         res = (res*(c[i]+1))%10;
   printf("%d\n",res);
   return 0;
}
