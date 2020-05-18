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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define VI vector< int >

const int MAX_N = 110;

int nTest, n, m, x, y, p;
VI e[MAX_N];
queue< int > q;
int c[MAX_N];

int main() {
   freopen("HDELIVER.in", "r", stdin);
   freopen("HDELIVER.out", "w", stdout);

   cin >> nTest;
   while (nTest) {
      scanf("%d%d", &n, &m);
      fab(i, 0, n-1) e[i].clear();
      fab(i, 1, m) {
         scanf("%d%d", &x, &y);
         e[x].pb(y);
         e[y].pb(x);
      }

      int nC = 0;
      fill(c, 0);
      while (!q.empty()) q.pop();
      fab(i, 0, n-1)
         if (c[i] == 0) {
            c[i] = ++nC;
            q.push(i);
            while (!q.empty()) {
               int u = q.front();   q.pop();
               fab(i, 0, int(e[u].size())-1)
                  if (c[e[u][i]] == 0) {
                     c[e[u][i]] = c[u];
                     q.push(e[u][i]);
                  }
            }
         }

      scanf("%d", &p);
      fab(i, 1, p) {
         scanf("%d%d", &x, &y);
         if (c[x] == c[y]) printf("YO\n");
         else printf("NO\n");
      }
      --nTest;
   }
   return 0;
}

