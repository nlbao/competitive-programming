#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1010;

int n;
int x1[MAX_N], y1[MAX_N], x2[MAX_N], y2[MAX_N];
vector< int > a;

void enter() {
   scanf("%d", &n);
   fab(i, 1, n) {
      scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
      a.pb(x1[i]);
      a.pb(x2[i]);
   }
}

void swap(int &x, int &y) {
   int t = x;
   x = y;
   y = t;
}

void qsort(int l, int r) {
   if (l >= r) return;
   int p = y2[(l+r)>>1];
   int i = l, j = r;
   do {
      while (y2[i] < p) ++i;
      while (y2[j] > p) --j;
      if (i <= j) {
         swap(x1[i], x1[j]);
         swap(y1[i], y1[j]);
         swap(x2[i], x2[j]);
         swap(y2[i], y2[j]);
         ++i;  --j;
      }
   } while (i < j);
   qsort(l, j);    qsort(i, r);
}

void solve() {
   sort(a.begin(), a.end());
   qsort(1, n);
   ll res = 0;
   fab(i, 0, int(a.size())-2) {
      ll ymin = 0, ymax = 0;
      fab(j, 1, n) {
         if ((x1[j] < a[i+1]) && (x2[j] > a[i]) && (y1[j] > ymax)) {
            if (y2[j] <= ymax)
               ymax = max(ymax, ll(y1[j]));
            else {
               res += (ymax-ymin)*ll(a[i+1]-a[i]);
               ymax = y1[j];
               ymin = y2[j];
            }
         }
      }
      res += (ymax-ymin)*ll(a[i+1]-a[i]);
   }
   cout << res << endl;
}

int main() {
   freopen("planting.in", "r", stdin);
   freopen("planting.out", "w", stdout);
   enter();
   solve();
   return 0;
}

