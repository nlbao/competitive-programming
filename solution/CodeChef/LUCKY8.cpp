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

const int MAX_N = 18;
const int MAX_M = 524290;

int m, u, v;
vector<pair<ll,int> > a;
int IT[4*MAX_M];

void update_IT(int k, int l, int r) {
   if (l > r) return;
   if (l == r) {
      IT[k] = a[l].sc;
      return;
   }
   int mid = (l+r)/2;
   update_IT(k<<1,l,mid);
   update_IT((k<<1)+1,mid+1,r);
   IT[k] = max(IT[k<<1],IT[(k<<1)+1]);
}

int get_IT(int k, int l, int r) {
   if (l > r || u > v || u > r || v < l) return 0;
   if (u <= l && r <= v) return IT[k];
   int mid = (l+r)/2;
   return max(get_IT(k<<1,l,mid), get_IT((k<<1)+1,mid+1,r));
}

void init(int n) {
   foru(i,1,n) {
      ll limit = 1<<i;
      for (ll x = 0; x < limit; ++x) {
         ll y = 0;
         int f4 = 0, f7 = 0;
         rep(j,i) {
            y *= 10;
            if (x&(1<<j)) ++f4, y += 4;
            else ++f7, y += 7;
         }
         a.pb(mp(y,f4*f7));
      }
   }
   m = size(a);
   sort(all(a));
   //rep(i, m) printf("%I64d %d\n", a[i].fr,a[i].sc);
   update_IT(1,0,m-1);


}

int solve(int x, int y) {
   u = m;
   int l = 0, r = m-1;
   while (l <= r) {
      int mid = (l+r)/2;
      ll t = a[mid].fr;
      if (t < x) l = mid+1;
      else {
         if (t <= y) u = mid;
         r = mid-1;
      }
   }
   v = -1;
   l = 0, r = m-1;
   while (l <= r) {
      int mid = (l+r)/2;
      ll t = a[mid].fr;
      if (t > y) r = mid-1;
      else {
         if (t >= x ) v = mid;
         l = mid+1;
      }
   }

   //cout << x << " " << y << "        " << u << " " << v << endl;

   if (u > v) return 0;
   return get_IT(1,0,m-1);
}

int main() {
   freopen("LUCKY8.in", "r", stdin);
   freopen("LUCKY8.out", "w", stdout);
   init(18);
   int nTest;
   ll x, y;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%I64d%I64d",&x,&y);
      printf("%d\n",solve(x,y));
   }
   return 0;
}
