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

const int MAX_N = 66;
const int MAX_M = 66;
const int MAX_K = 1001;
const int oo = 1000000000;

struct edge {
   int time, car, v;
   edge (int t, int c, int vv) { time = t;   car = c; v = vv;  }
};

struct node {
   int time, change, car, v;
   node (int tt, int ch, int cc, int vv) {
      time = tt;  change = ch;
      car = cc;   v = vv;
   }
};

struct cmp_hmin {
   bool operator() (const node& x, const node &y) const {
      return x.time > y.time;
   }
};

int n, m, r;
vector<edge> e[MAX_N];
priority_queue<node, vector<node>, cmp_hmin> h;
int d[MAX_N][MAX_K], f[MAX_N][MAX_N][MAX_K];

void dijkstra(int s) {
   while (!h.empty()) h.pop();
   rep(k, MAX_K) {
      foru(i, 1, n) d[i][k] = oo;
      d[s][k] = 0;
   }
   rep(i, size(e[s])) {
      edge x = e[s][i];
      d[x.v][0] = min(d[x.v][0], x.time);
      h.push(node(x.time,0,x.car,x.v));
   }
   while (!h.empty()) {
      node x = h.top();  h.pop();
      if (x.time > d[x.v][x.change]) continue;
      rep(i, size(e[x.v])) {
         int y = e[x.v][i].v, c = e[x.v][i].car, k = x.change+int(c != x.car);
         if (k >= MAX_K) continue;
         int t = x.time+e[x.v][i].time;
         if (t < d[y][k]) {
            d[y][k] = t;
            h.push(node(t,k,c,y));
         }
      }
   }
}

int main() {
   freopen("189D.in", "r", stdin);
   freopen("189D.out", "w", stdout);
   cin >> n >> m >> r;
   foru(k, 1, m)
      foru(i, 1, n)
         foru(j, 1, n) {
            int t;
            scanf("%d", &t);
            if (j != i) e[i].pb(edge(t,k,j));
         }
   foru(i, 1, n) {
      dijkstra(i);
      foru(j, 1, n) {
         f[i][j][0] = d[j][0];
         foru(k, 1, MAX_K-1)
            f[i][j][k] = min(d[j][k], f[i][j][k-1]);
      }
   }
   foru(i, 1, r) {
      int x, y, k;
      scanf("%d%d%d", &x, &y, &k);
      printf("%d\n", f[x][y][k]);
   }
   return 0;
}
