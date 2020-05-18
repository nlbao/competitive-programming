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

const int MAX_N = 22;

int n, sum = 0;
vector< PI > e[MAX_N];
bool ok[MAX_N];
VI a;

void gen(int i) {
   if (i > n) {
      a.pb(sum);
      return;
   }
   gen(i+1);
   rep(j, e[i].size()) {
      int v = e[i][j].sc;
      if (ok[v]) {
         ok[v] = false;
         sum += e[i][j].fr;
         gen(i+1);
         sum -= e[i][j].fr;
         ok[v] = true;
      }
   }
}

int main() {
   freopen("177F1.in", "r", stdin);
   freopen("177F1.out", "w", stdout);
   int t, m;
   cin >> n >> m >> t;
   foru(i, 1, m) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      e[x].pb(mp(w, y));
   }
   fill(ok, true);
   gen(1);
   sort(all(a));
   cout << a[t-1];
   return 0;
}

