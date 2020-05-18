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

const int MAX_P = 40000;

int nP;
ll c[MAX_P], s[MAX_P];

ll solve(int i) {
   if (i > nP) return 1;
   ll res = c[i]*s[i+1] + solve(i+1);
   return res;
}

int main() {
   freopen("10892.in", "r", stdin);
   freopen("10892.out", "w", stdout);
   for(;;) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      int m = n;
      nP = 0;
      for(ll i = 2; i*i <= n; ++i)
         if (n%i == 0) {
            c[++nP] = 0;
            while (n%i == 0) {
               ++c[nP];
               n /= i;
            }
         }
      if (n > 1) c[++nP] = 1;

      s[nP+1] = 1;
      ford(i,nP,1) s[i] = s[i+1]*(2*c[i]+1);

      printf("%d %I64d\n",m,solve(1));
   }
   return 0;
}
