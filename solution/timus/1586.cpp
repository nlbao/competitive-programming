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
const int MODUN = 1000000009;

bool ok[10][10][10];
ll f[2][10][10];

bool is_prime(int n) {
   if (n < 2) return false;
   for(int i = 2; i*i <= n; ++i)
      if (n%i == 0) return false;
   return true;
}


int main() {
   freopen("1586.in", "r", stdin);
   freopen("1586.out", "w", stdout);
   int n;
   scanf("%d",&n);
   fill(ok,false);
   fill(f,0);
   foru(i,1,9)
      rep(j,10)
         rep(k,10)
            if (is_prime(i*100+j*10+k)) {
               ok[i][j][k] = true;
               ++f[0][j][k];
            }

   int t = 0;
   rep(id,n-3) {
      int tt = (t+1)%2;
      rep(i,10)
         rep(j,10) f[tt][i][j] = 0;
      foru(i,1,9)
         rep(j,10)
            rep(k,10)
               if (ok[i][j][k]) f[tt][j][k] = (f[tt][j][k]+f[t][i][j])%MODUN;
      t = tt;
   }

   ll res = 0;
   rep(i,10)
      rep(j,10) res = (res+f[t][i][j])%MODUN;

   cout << res;
   return 0;
}
