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

int etf[MAX_N];
ll res[MAX_N];

int main() {
   freopen("LCMSUM.in", "r", stdin);
   freopen("LCMSUM.out", "w", stdout);
   foru(i,1,MAX_N-1) etf[i] = i;
   foru(i,2,MAX_N-1)
      if (etf[i] == i) {
         etf[i] = i-1;
         for(int j = i+i; j < MAX_N; j += i)
            etf[j] -= etf[j]/i;
      }

   fill(res,0);
   foru(i,1,MAX_N-1)
      for(int j = i; j < MAX_N; j += i)
         res[j] += i*1LL*etf[i];

   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      printf("%I64d\n",(1+res[n])*n/2);
   }
   return 0;
}
