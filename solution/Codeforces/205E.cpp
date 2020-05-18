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

const int MAX_N = 200007;

char s[MAX_N];
vector<ll> a[30], sum[30];
int sz[30];

int num(char x) { return x-'A';  }

ll get_sum(int x, int i, int j) {
   if (i == 0) return sum[x][j];
   return sum[x][j]-sum[x][i-1];
}

int main() {
   freopen("205E.in", "r", stdin);
   freopen("205E.out", "w", stdout);
   rep(i,30) a[i].clear();

   ll n;
   scanf("%I64d",&n);
   scanf("%s",s);
   rep(i,n) a[num(s[i])].pb(i+1);
   scanf("%s",s);

   ll c = 0;
   for(ll i = 1; i <= n; ++i)
      c += (n-i+1)*(n-i+1);

   rep(i,30) {
      sz[i] = size(a[i]);
      if (sz[i] == 0) continue;
      sum[i].pb(a[i][0]);
      foru(j,1,sz[i]-1)
         sum[i].pb(sum[i][j-1]+a[i][j]);
   }

   double res = 0;
   for(ll i = 1; i <= n; ++i) {
      int x = num(s[i-1]);
      ll l = 0, r = sz[x]-1, t = r+1;
      while (l <= r) {
         ll mid = (l+r)/2;
         if (a[x][mid] >= i) {
            t = mid;
            r = mid-1;
         }
         else l = mid+1;
      }
      r = sz[x]-1;
      ll d = 0;
      if (t <= r) d += (r-t+1)*(i*n+i)-i*get_sum(x,t,r);
      if (t > 0) d += get_sum(x,0,t-1)*(n-i+1);
      res += double(d)/double(c);
   }

   printf("%.7f",res);
   return 0;
}
