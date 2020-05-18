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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second


void enter() {
   int x, y;
   fab(i, 1, n) {
      e[i].clear();
      l[i].clear();
   }
   fab(i, 1, nE) {
      scanf("%d%d", &x, &y);
      e[x].pb(y);
      e[y].pb(x);
   }
   fab(i, 1, nL) {
      scanf("%d%d", &x, &y);
      l[x].pb(y);
      l[y].pb(x);
   }
}

void solve(int id) {
   int m = (1<<n)-1;
   fab(i, 0, m)
      fab(j, 1, n) f[i][j] = oo;


}

int main() {
   freopen("321.in", "r", stdin);
   freopen("321.out", "w", stdout);
   int id = 0;
   scanf("%d%d%d", &n, &nE, &nL);
   while (n > 0) {
      ++id;
      enter();
      solve(id);
      scanf("%d%d%d", &n, &nE, &nL);
   }
   return 0;
}

