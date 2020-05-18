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

const int MAX_N = 1010;
const int MAX_M = 1010;

int n, m, nC;
int x[MAX_N], y[MAX_N];
int c[MAX_N], p[MAX_N];
VI e[MAX_N];
vector < pair< double, pair< int, int > > > f;

double sqr(double x) { return (x*x); }

void enter() {
   scanf("%d%d", &n, &m);
   fab(i, 1, n) scanf("%d%d", &x[i], &y[i]);
   fab(i, 1, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].pb(v);
      e[v].pb(u);
   }
}

void dfs(int u, int cc) {
   c[u] = cc;
   fab(i, 0, int(e[u].size())-1)
      if (c[e[u][i]] == 0) dfs(e[u][i], cc);
}

int get_root(int u) {
   if (p[u] < 0) return u;
   return (p[u] = get_root(p[u]));
}

void solve() {
   int nC = 0;
   double res = 0;
   fill(c, 0);
   fab(i, 1, n)
      if (c[i] == 0) dfs(i, ++nC);
   fab(i, 1, n)
      fab(j, i+1, n)
         if (c[i] != c[j]) f.pb(mp(sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])), mp(c[i], c[j])));
   sort(f.begin(), f.end());
   fab(i, 1, nC) p[i] = -1;
   fab(i, 0, int(f.size())-1) {
      int r1 = get_root(f[i].sc.fr);
      int r2 = get_root(f[i].sc.sc);
      if (r1 != r2) {
         res += f[i].fr;
         p[r1] += p[r2];
         p[r2] = r1;
      }
   }
   printf("%.2lf", res);
}

int main() {
   freopen("roads.in", "r", stdin);
   freopen("roads.out", "w", stdout);
   enter();
   solve();
   return 0;
}
