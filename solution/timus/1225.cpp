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

ll f[2][3][3];

ll solve(int n) {
   if (n == 1) return 2;
   if (n == 2) return 2;
   int t = 0;
   fill(f,0);
   f[t][0][2] = f[t][2][0] = 1LL;
   f[t][0][1] = f[t][2][1] = 1LL;
   foru(i,3,n) {
      int tt = (t+1)%2;
      rep(j,2)
         rep(k,2) f[tt][j][k] = 0;
      f[tt][0][1] = f[tt][0][2] = f[t][1][0]+f[t][2][0];
      f[tt][1][0] = f[t][2][1];
      f[tt][1][2] = f[t][0][1];
      f[tt][2][0] = f[tt][2][1] = f[t][0][2]+f[t][1][2];
      t = tt;
   }
   return f[t][0][2]+f[t][1][0]+f[t][1][2]+f[t][2][0];
}

int main() {
   freopen("1225.in", "r", stdin);
   freopen("1225.out", "w", stdout);
   int n;
   scanf("%d",&n);
   printf("%I64d\n",solve(n));
   return 0;
}
