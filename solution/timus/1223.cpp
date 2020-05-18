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

const int MAX_N = 13;
const int MAX_M = 1003;

int f[MAX_N][MAX_M];

int cbit(int n) {
   int c = 0;
   while (n > 0) {
      n /= 2;
      ++c;
   }
   return c;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1223.in", "r", stdin);
   freopen("1223.out", "w", stdout);
#endif

   int n = cbit(MAX_M-2), m = MAX_M-2;
   fill(f,0);
   foru(i,0,m) f[1][i] = i;
   foru(i,2,n) {
      f[i][1] = 1;
      foru(j,2,m) {
         f[i][j] = MAX_N+MAX_M;
         foru(k,1,j)
            f[i][j] = min(f[i][j],max(f[i-1][j-k],f[i][k-1])+1);
      }
   }

   while(1) {
      scanf("%d%d",&n,&m);
      if (n == 0 && m == 0) break;
      int k = cbit(m);
      if (n >= k) printf("%d\n",k);
      else printf("%d\n",f[n][m]);
   }
   return 0;
}
