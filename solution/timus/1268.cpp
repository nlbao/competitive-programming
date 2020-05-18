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

const int MAX_N = 65540;

ll n;
int nP, phi;
int p[MAX_N];

ll mpow(ll x, ll a) {
   if (a == 0) return 1;
   if (a == 1) return x;
   ll t = mpow(x,a/2);
   t = (t*t)%n;
   if (a%2 == 0) return t;
   else return (t*x)%n;
}

int find(ll k) {
   ford(i,nP-1,0)
      if (mpow(k,p[i]) == 1) return (phi/p[i]);
   return phi;
}

int main() {
   freopen("1268.in", "r", stdin);
   freopen("1268.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      int maxd = 0, res = 0;
      scanf("%I64d",&n);

      nP = 1;  p[0] = 1;
      phi = n-1;
      int m = phi;
      for(int i = 2; i*i <= m; ++i)
         if (m%i == 0) {
            p[nP++] = phi/i;
            while (m%i == 0) m /= i;
         }
      if (m > 1) p[nP++] = phi/m;
      sort(p,p+nP);

      for(ll i = n-1; i > 0; --i) {
         ll d = find(i);
         if (d > maxd) {
            maxd = d;
            res = i;
         }
         if (maxd == n-1) break;
      }
      printf("%d\n",res);
   }
   return 0;
}
