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
const ll MODUN = 1000000007;

int n, k;
int p[MAX_N], root[MAX_N];
ll depth[MAX_N], e[MAX_N];

int get_root(int u) {
   if (!p[u]) return u;
   return p[u] = get_root(p[u]);
}

ll get_depth(int u) {
   if (!p[u]) return 0;
   return depth[u] = (depth[u]+get_depth(p[u]))%MODUN;
}

int main() {
   freopen("195E.in", "r", stdin);
   freopen("195E.out", "w", stdout);
   scanf("%d",&n);
   fill(p,0);
   fill(root,0);
   fill(depth,0);
   fill(e,0);
   foru(i,1,n) {
      scanf("%d",&k);
      rep(j,k) {
         int v, x;
         scanf("%d%d",&v,&x);
         ll d = (get_depth(v)+x)%MODUN;
         int u = get_root(v);
         e[u] = d;
         p[u] = i;
         depth[u] = e[u];
      }
   }
   ll res = 0;
   foru(i,1,n) res = (res+e[i])%MODUN;
   while (res < 0) res += MODUN;
   cout << res;
   return 0;
}
