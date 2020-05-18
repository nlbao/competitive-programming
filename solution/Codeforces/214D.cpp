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

const int MAX_N = 107;
const int MAX_S = 10007;
const ll MOD = 1000000007LL;

int a[MAX_N];
ll c[MAX_N][MAX_N], f[MAX_N][MAX_N];

ll mmod(ll x) {  while (x < 0) x += MOD; return x%MOD;  }

ll get_c(int k, int n) {
   if (k < 0 || k > n) return 0;
   return c[n][k];
}

int main() {
   freopen("214D.in", "r", stdin);
   freopen("214D.out", "w", stdout);
   int n, s = 0;
   scanf("%d",&n);
   rep(i,10) {
      scanf("%d",&a[i]);
      s += a[i];
   }
   if (s > n || (s == n && s == a[0])) {
      printf("0");
      return 0;
   }

   fill(c,0);
   foru(i,0,n+3) c[i][0] = c[i][i] = 1;
   foru(i,2,n+3)
      foru(j,1,i-1)
         c[i][j] = mmod(c[i-1][j]+c[i-1][j-1]);

   fill(f,0);
   foru(j,a[9],n) f[9][j] = 1;
   s = a[9];
   ford(i,8,0) {
      int x = (i == 0);
      s += a[i];
      foru(j,s,n)
         foru(k,a[i],j)
            f[i][j] = mmod(f[i][j] + f[i+1][j-k]*get_c(k,j-x));
   }

   ll res = 0;
   foru(i,s,n) res = mmod(res+f[0][i]);
   cout << res;
   return 0;
}
