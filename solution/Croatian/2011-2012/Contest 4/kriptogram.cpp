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

const int MAX_N = 1000010;
const ll BASE = 10007;

char s[MAX_N];
pair<ll,int> h[MAX_N];
ll p[MAX_N];
int b[MAX_N], c[MAX_N];

ll get_h(int n) {
   ll h = 0;
   rep(i,n) h = h*BASE+ll(s[i]);
   return h;
}

void enter(int &n) {
   n = 0;
   for(int i = 0; ; ++i) {
      scanf("%s",s);
      if (s[0] == '$') break;
      h[n++] = mp(get_h(strlen(s)),i);
   }
   sort(h,h+n);
}



int main() {
   freopen("kriptogram.in", "r", stdin);
   freopen("kriptogram.out", "w", stdout);
   int n,m;
   enter(n);
   rep(i,n) b[i] = -1, c[i] = n+10;
   foru(i,1,n-1)
      if (h[i-1].fr == h[i].fr) {
         b[h[i].sc] = h[i-1].sc;
         c[h[i-1].sc] = h[i].sc;
      }

   p[0] = 1;
   foru(i,1,n) p[i] = p[i-1]*BASE;

   enter(m);
   ll g = 0;
   foru(i,1,m-1)
      if (h[i-1].fr == h[i].fr)
         g += ll(h[i].sc-h[i-1].sc)*p[h[i].sc];

   ll f = 0;
   for(ll i = 0; i < m-1; ++i)
      if (b[i] > -1) f += (i-b[i])*p[i];

   for(ll i = 0; i < n; ++i) {
      int j = i+m-1;
      if (j >= n) break;
      if (i > 0 && c[i-1] <= j)
         f -= (c[i-1]-i+1)*p[c[i-1]];
      if (b[j] >= i)
         f += (j-b[j])*p[j];
      if (g*p[i] == f) {
         printf("%d",i+1);
         return 0;
      }
   }

   printf("-1");
   return 0;
}
