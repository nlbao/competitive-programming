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
#pragma comment(linker,"/STACK:1000000000,1000000000")

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

const int MAX_N = 50003;

vector<pair<ll,int> > e[MAX_N];
int p[MAX_N];
ll s[MAX_N], f[MAX_N], nChild[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   s[u] = f[u] = 0;
   nChild[u] = 1;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i].sc;
      if (p[v] == 0) {
         p[v] = u;
         dfs(v);
         ll w = e[u][i].fr;
         f[u] += 2*(nChild[v]*s[u] + nChild[u]*s[v] + nChild[u]*nChild[v]*w);
         s[u] += s[v]+nChild[v]*w;
         nChild[u] += nChild[v];
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1371.in", "r", stdin);
   freopen("1371.out", "w", stdout);
#endif
   ll n = read();
   rep(i,n-1) {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      e[a].pb(mp(c,b));
      e[b].pb(mp(c,a));
   }

   fill(p,0);
   p[1] = -1;
   dfs(1);
   ll res = 0;
   foru(i,1,n) res += f[i];
   printf("%.4f",double(res)/double(n*(n-1)));
   return 0;
}
