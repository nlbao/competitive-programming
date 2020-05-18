#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#include <math.h>

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

const int MAX_N = 1010;

int n, r;
int x[MAX_N], y[MAX_N], p[MAX_N];
vector < pair < double, PI > > e;

double sqr(double x) { return x*x; }

void enter() {
   scanf("%d%d", &n, &r);
   fab(i, 1, n) scanf("%d%d", &x[i], &y[i]);
}

int get_root(int u) {
   if (p[u] < 0) return u;
   return p[u] = get_root(p[u]);
}

void solve(int id) {
   int nState = 0;
   double sRoad = 0, sRail = 0;

   e.clear();
   fab(i, 1, n)
      fab(j, i+1, n) {
         double t = sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
         if (t <= r) e.pb(mp(t, mp(i, j)));
      }
   sort(all(e));
   fab(i, 1, n) p[i] = -1;
   fab(i, 0, int(e.size())-1) {
      int r1 = get_root(e[i].sc.fr), r2 = get_root(e[i].sc.sc);
      if (r1 != r2) {
         sRoad += e[i].fr;
         p[r1] += p[r2];
         p[r2] = r1;
      }
   }

   fab(i, 1, n)
      if (p[i] < 0) ++nState;

   e.clear();
   fab(i, 1, n)
      fab(j, i+1, n) {
         int r1 = get_root(i), r2 = get_root(j);
         if (r1 != r2)
            e.pb(mp(sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])), mp(r1, r2)));
      }
   sort(all(e));
   fab(i, 1, n) p[i] = -1;
   fab(i, 0, int(e.size())-1) {
      int r1 = get_root(e[i].sc.fr), r2 = get_root(e[i].sc.sc);
      if (r1 != r2) {
         sRail += e[i].fr;
         p[r1] += p[r2];
         p[r2] = r1;
      }
   }
   cout << "Case #" << id << ": " << nState << " " << round(sRoad) << " " << round(sRail) << endl;
}

int main() {
   freopen("11228.in", "r", stdin);
   freopen("11228.out", "w", stdout);
   int nTest;
   cin >> nTest;
   fab(i, 1, nTest) {
      enter();
      solve(i);
   }
   return 0;
}
