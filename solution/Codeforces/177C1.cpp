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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 2222;

VI e1[MAX_N], e2[MAX_N];

bool ok[MAX_N], invited[MAX_N];
int rcount;
bool check;

void dfs(int u) {
   if (!ok[u]) {
      check = false;
      return;
   }
   invited[u] = true;
   ++rcount;
   rep(i, e2[u].size()) ok[e2[u][i]] = false;
   rep(i, e1[u].size()) {
      int v = e1[u][i];
      if (!invited[v]) dfs(v);
      if (!check) return;
   }
}

int main() {
   freopen("177C1.in", "r", stdin);
   freopen("177C1.out", "w", stdout);
   int n, m, x, y, res = 0;
   cin >> n >> m;
   foru(i, 1, m) {
      scanf("%d%d", &x, &y);
      e1[x].pb(y);
      e1[y].pb(x);
   }
   cin >> m;
   foru(i, 1, m) {
      scanf("%d%d", &x, &y);
      e2[x].pb(y);
      e2[y].pb(x);
   }
   foru(i, 1, n) {
      fill(ok, true);
      fill(invited, false);
      rcount = 0;  check = true;
      dfs(i);
      if (check) res = max(res, rcount);
   }
   cout << res;
   return 0;
}

