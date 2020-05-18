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

const int MAX_N = 110;
const int MAX_M = 10010;
const int oo = 100000000;

int n, m;

int c[MAX_N];
int a[MAX_N][MAX_N], f[MAX_N][MAX_M];

void enter() {
   cin >> n >> m;
   fill(a, -oo);
   fab(i, 1, n) {
      scanf("%d", &c[i]);
      fab(j, 1, c[i])
         scanf("%d", &a[i][j]);
   }
}

void update(int &a, int b) {
   a = max(a, b);
}

int solve() {
   int p = 0;
   int g[MAX_N], s[MAX_N] = {0};
   fill(f, 0);
   fab(i, 1, n) {
      fab(j, 1, c[i]+1)
         s[j] = s[j-1]+a[i][j];
      fill(g, 0);
      fab(j, 1, c[i]) {
         fab(k, 1, j+1) {
            int t = k+c[i]-j-1;
            update(g[j], s[k-1]+s[c[i]]-s[t]);
         }
      }
      fab(j, 0, p)
         fab(k, 0, c[i])
            update(f[i][j+k], f[i-1][j]+g[k]);
      p += c[i];
   }
   return f[n][m];
}

int main() {
   freopen("148E.in", "r", stdin);
   enter();
   cout << solve();
   return 0;
}
