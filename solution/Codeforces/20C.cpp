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

const int MAX_N = 100007;
const int MAX_M = 200007;
const ll oo = 1000000000000000000LL;

struct cmp_hmin {
   bool operator () (const PI x, const PI y) {  return (x.fr > y.fr);   }
};

int n, m;
vector<pair<ll,int> > e[MAX_N];
priority_queue <pair<ll, int>, vector<pair<ll, int> >, cmp_hmin> h;
ll d[MAX_N];
int trace[MAX_N];

ll dijkstra(int s, int t) {
   foru(i, 1, n) {
      d[i] = oo;
      trace[i] = -1;
   }
   d[s] = 0;
   h.push(mp(0,s));
   while (!h.empty()) {
      ll dd = h.top().fr;
      int u = h.top().sc;
      h.pop();
      if (u == n) break;
      if (dd > d[u]) continue;
      rep(i, size(e[u])) {
         int v = e[u][i].sc;
         ll w = e[u][i].fr;
         if (dd+w < d[v]) {
            d[v] = dd+w;
            trace[v] = u;
            h.push(mp(d[v],v));
         }
      }
   }
   return d[t];
}

void print_res(int u) {
   if (u < 1) return;
   print_res(trace[u]);
   printf("%d ", u);
}

int main() {
   freopen("20C.in", "r", stdin);
   freopen("20C.out", "w", stdout);
   scanf("%d%d", &n, &m);
   int j = 0;
   rep(i, m) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      e[x].pb(mp(w,y));
      e[y].pb(mp(w,x));
   }
   ll res = dijkstra(1,n);
   if (res == oo) printf("-1");
   else print_res(n);
   return 0;
}
