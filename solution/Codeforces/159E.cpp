#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100007;


int n;
vector < pair < PI, int > > a;
ll f[MAX_N], g[MAX_N];
int d[MAX_N], e[MAX_N];
ll res = 0;
int r1, r2, l1, l2;
VI x, y;

void swap(int &x, int &y) {
   int t = x;
   x = y;
   y = t;
}

void update(ll value, int r11, int r22, int l11, int l22) {
   if (value <= res) return;
   res = value;
   r1 = r11;   r2 = r22;
   l1 = l11;   l2 = l22;
}

void check(int i, int j) {
   if (f[i] < 1) return;
   if (d[i] != d[j]) {
      if (f[j] > 0) update(f[i]+f[j], d[j], d[i], j, i);
   }
   else
      if (g[j] > 0) update(f[i]+g[j], e[j], d[i], j, i);
}

int main() {
   freopen("159E.in", "r", stdin);
   freopen("159E.out", "w", stdout);
   cin >> n;
   fab(i, 1, n) {
      int c, s;
      scanf("%d%d", &c, &s);
      a.pb(mp(mp(c, s), i));
   }

   sort(a.begin(), a.end());
   fill(f, 0); fill(g, 0);
   fill(d, 0); fill(e, 0);

   int i = n-1;
   while (i >= 0) {
      int j = i, k = 0, tmp = a[i].fr.fr;
      ll h = 0;
      while ((j >= 0) && (a[j].fr.fr == tmp)) {
         ++k;
         h += ll(a[j].fr.sc);
         if (h > f[k]) {
            g[k] = f[k];   e[k] = d[k];
            f[k] = h;      d[k] = i+1;
         }
         else if (h > g[k]) {
            g[k] = h;
            e[k] = i+1;
         }
         a[j].fr.fr = i+1;
         --j;
      }
      i = j;
   }

   r1 = r2 = l1 = l2 = 0;
   fab(i, 1, n) {
      if (g[i] > 0) update(f[i]+g[i], e[i], d[i], i, i);
      check(i, i+1);
      check(i, i-1);
   }

   if (l1 < l2) {
      swap(l1, l2);
      swap(r1, r2);
   }

   int c1 = l1, c2 = l2;
   fba(i, n-1, 0) {
      if ((c1 > 0) && (a[i].fr.fr == r1)) {
         x.pb(a[i].sc);
         --c1;
      }
      if ((c2 > 0) && (a[i].fr.fr == r2)) {
         y.pb(a[i].sc);
         --c2;
      }
   }
   cout << res << endl;
   cout << l1+l2 << endl;
   fab(i, 0, l2-1)
      cout << x[i] << " " << y[i] << " ";
   if (l1 > l2) cout << x[l1-1] << endl;
   return 0;
}


