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

const int MAX_N = 77777;
const int MAX_M = 200010;

int n, m;
vector< pair< int, ll > > e[MAX_N];
bool avail[MAX_N];
ll s[MAX_N];
bool ok = true;

void enter() {
   scanf("%d%d", &n, &m);
   int x, y, z;
   fab(i, 1, m) {
      scanf("%d%d%d", &x, &y, &z);
      e[x-1].pb(mp(y, z));
      e[y].pb(mp(x-1, -z));
   }
}

bool check(int u) {
   avail[u] = false;
   bool res = true;
   fab(i, 0, int(e[u].size())-1) {
      int v = e[u][i].fr;
      if (avail[v]) {
         s[v] = s[u]+e[u][i].sc;
         res = res & check(v);
      }
      else
         if (s[v] != s[u]+e[u][i].sc) res = false;
      if (!res) return res;
   }
   return res;
}

void solve() {
   fill(avail, true);
   fab(i, 0, n)
      if (avail[i]) {
         s[i] = 0;
         ok = ok & check(i);
         if (!ok) {
            printf("-1");
            return;
         }
      }
   fab(i, 1, n)
      printf("%lld ", s[i]-s[i-1]);
}

int main() {
   freopen("RSRECIPE.in", "r", stdin);
   freopen("RSRECIPE.out", "w", stdout);
   enter();
   solve();
   return 0;
}

