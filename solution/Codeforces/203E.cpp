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

const ll oo = 4000000000LL;

vector<ll> a;

int main() {
   freopen("203E.in", "r", stdin);
   freopen("203E.out", "w", stdout);
   ll n,d,s, res = 0, sC = 1, last = 0, minf = oo, ff = oo;
   cin >> n >> d >> s;
   rep(i,n) {
      int c,f,l;
      scanf("%d%d%d",&c,&f,&l);
      if (c == 0) {
         if (l >= d) {
            a.pb(f);
            ff = min(ff,ll(f));
         }
         else ++last;
      }
      else {
         ++res;
         sC += c-1;
         if (l >= d) minf = min(minf,ll(f));
      }
   }

   if (minf > s && ff > s) {
      printf("0 0");
      return 0;
   }
   if (minf > s) minf = res = sC = 0;

   ll t = min(sC,last);
   res += t;
   sC -= t;

   sort(all(a));
   ll nA = size(a);
   t = min(sC,nA);
   res += t;
   nA -= t;

   rep(i,nA) {
      t = a[i]+minf;
      if (t > s) break;
      minf = t;
      ++res;
   }

   cout << res << " " << minf;
   return 0;
}
