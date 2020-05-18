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

const ll MAX_N = 1000000000000000000LL;
const int MAX_M = 1304920;

int m = 0, nP = 16;
ll p[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
vector<pair<ll,int> > a;
int f[MAX_M];

void tryf(int i, ll v, int c) {
   a.pb(mp(v,c));
   ll limit = MAX_N/v;
   if (p[i] > limit) return;
   ll x = p[i];
   for(int j = 1; x <= limit; x *= p[i], ++j)
      tryf(i+1,v*x,c*(j+1));
}


int main() {
   freopen("1748.in", "r", stdin);
   freopen("1748.out", "w", stdout);
   tryf(0,1,1);
   m = size(a);
   sort(all(a));
   f[0] = 0;
   foru(i,1,m-1)
      if (a[i].sc > a[f[i-1]].sc) f[i] = i;
      else f[i] = f[i-1];

   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      ll n;
      scanf("%I64d",&n);
      int l = 0, r = m-1, i = 0;
      while (l <= r) {
         int mid = (l+r)/2;
         if (a[mid].fr <= n) {
            i = mid;
            l = mid+1;
         }
         else r = mid-1;
      }
      printf("%I64d %d\n",a[f[i]].fr,a[f[i]].sc);
   }
   return 0;
}
