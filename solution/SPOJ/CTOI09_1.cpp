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

void mmax(int &a, int b) { a = max(a, b); }

const int MAX_N = 810;
const int oo = 1000000000;
const int dx[5] = {0, 0, 0, +1, -1};
const int dy[5] = {0, +1, -1, 0, 0};

int n, s, xs, ys, xt, yt;
char a[MAX_N][MAX_N];
int c[MAX_N][MAX_N], d[MAX_N][MAX_N];

deque< pair<int, int> >  q;

void enter() {
   cin >> n >> s;
   fab(i, 0, n+1)
      fab(j, 0, n+1) a[i][j] = 'T';
   q.clear();

   fab(i, 1, n) {
      cin >> ws;
      fab(j, 1, n) {
         cin >> a[i][j];
         d[i][j] = oo;
         if (a[i][j] == 'M') {
            xs = i;  ys = j;
            a[i][j] = 'G';
         }
         else if (a[i][j] == 'D') { xt = i;  yt = j; }
         else if (a[i][j] == 'H') {
            q.pb(mp(i, j));
            d[i][j] = 0;
            a[i][j] = 'T';
         }
      }
   }
}

void cal_d() {
   while (!q.empty()) {
      int i = q.front().fr;
      int j = q.front().sc;
      q.pop_front();
      fab(k, 1, 4) {
         int x = i+dx[k];
         int y = j+dy[k];
         if ((a[x][y] == 'G') && (d[x][y] == oo)) {
            d[x][y] = d[i][j]+1;
            q.pb(mp(x, y));
         }
      }
   }
}

bool ok(int value) {
   if (value >= d[xs][ys]) return false;
   fab(i, 1, n)
      fab(j, 1, n) c[i][j] = oo;
   c[xs][ys] = 0;
   q.clear();
   q.pb(make_pair(xs, ys));

   for (int t = 1; (!q.empty()) && (c[xt][yt] >= oo); ++t) {
      do {
         int i = q.front().fr;
         int j = q.front().sc;
         if (c[i][j] >= t*s) break;
         q.pop_front();
         if (t+value > d[i][j]) continue;

         fab(k, 1, 4) {
            int x = i+dx[k];
            int y = j+dy[k];
            if ((a[x][y] != 'T') && (c[x][y] == oo)) {
               c[x][y] = c[i][j]+1;
               q.pb(mp(x, y));
            }
         }
      } while ((!q.empty()) && (c[xt][yt] >= oo));
   }
   return (c[xt][yt] < oo);
}

void solve() {
   int res = -1, l = 0, r = n*n;
   while (l <= r) {
      int mid = (l+r)>>1;
      if (ok(mid)) {
         res = mid;
         l = mid+1;
      }
      else r = mid-1;
   }
   cout << res << endl;
}

int main() {
   freopen("CTOI09_1.in", "r", stdin);
   freopen("CTOI09_1.out", "w", stdout);
   int nTest;
   cin >> nTest;
   fab(i, 1, nTest) {
      enter();
      cal_d();
      solve();
   }
   return 0;
}

