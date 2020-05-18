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

const int MAX_N = 4000007;

int etf[MAX_N];
ll f[MAX_N];

int main() {
   freopen("11426.in", "r", stdin);
   freopen("11426.out", "w", stdout);
   rep(i,MAX_N) etf[i] = i;
   foru(i,2,MAX_N-1)
      if (etf[i] == i) {
         --etf[i];
         for(int j = i+i; j < MAX_N; j += i)
            etf[j] -= etf[j]/i;
      }

   fill(f,0);
   foru(i,2,MAX_N-1) {
      ll c = 0;
      for(int j = i; j < MAX_N; j += i)
         f[j] += (++c)*etf[i];
   }
   foru(i,2,MAX_N-1) f[i] += f[i-1];

   int n;
   for(;;) {
      scanf("%d",&n);
      if (n == 0) break;
      printf("%I64d\n",f[n]);
   }
   return 0;
}
