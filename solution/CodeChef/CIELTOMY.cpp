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
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 20;
const int oo = 1000000;

struct cmp_hmin {
   bool operator () (const PI x, const PI y) {  return (x.sc > y.sc);   }
};

priority_queue <PI,vector<PI>,cmp_hmin> h;
vector<PI> e[MAX_N];
int d[MAX_N], sz[MAX_N];
ll c[MAX_N];


int solve(int n) {
   fill(c,0);
   foru(i,1,n) d[i] = oo;
   d[1] = 0;   c[1] = 1;
   while (!h.empty()) h.pop();
   h.push(mp(1,0));
   while (!h.empty()) {
      PI t = h.top();   h.pop();
      int u = t.fr;
      if (t.sc > d[u]) continue;
      rep(i,sz[u]) {
         int v = e[u][i].fr, x = e[u][i].sc+d[u];
         if (x < d[v]) {
            d[v] = x;
            h.push(mp(v,x));
            c[v] = c[u];
         }
         else if (x == d[v]) c[v] += c[u];
      }
   }
   return c[n];
}

int main() {
   freopen("CIELTOMY.in", "r", stdin);
   freopen("CIELTOMY.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      int n,m,x,y,z;
      scanf("%d%d",&n,&m);
      foru(i,1,n) e[i].clear();
      rep(i,m) {
         scanf("%d%d%d",&x,&y,&z);
         e[x].pb(mp(y,z));
         e[y].pb(mp(x,z));
      }
      foru(i,1,n) sz[i] = size(e[i]);
      printf("%d",solve(n));
      if (id != nTest-1) printf("\n");
   }
   return 0;
}
