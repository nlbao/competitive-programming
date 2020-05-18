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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 200003;

int n, m;
int a[MAX_N], sz[MAX_N], p[MAX_N], f[4*MAX_N], res[MAX_N];
VI e[MAX_N];
vector<PI> q[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void update(int k, int l, int r, int u, int v, int d) {
   if (l > r || u > v || l > v || r < u) return;
   if (u <= l && r <= v) {
      f[k] += d;
      return;
   }
   int mid = (l+r)>>1;
   update(k<<1,l,mid,u,v,d);
   update((k<<1)+1,mid+1,r,u,v,d);
}

int get(int k, int l, int r, int x) {
   if (l > r || l > x || r < x) return 0;
   if (l == r) return f[k];
   int mid = (l+r)>>1;
   return f[k] + get(k<<1,l,mid,x) + get((k<<1)+1,mid+1,r,x);
}

void up(int x, int p, int d) {
   if (p+x == sz[x]) update(1,1,n,e[x][p+x-1],n,d);
   else if (p+x < sz[x]) update(1,1,n,e[x][p+x-1],e[x][p+x]-1,d);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("221D.in", "r", stdin);
   freopen("221D.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   foru(i,1,n) {
      scanf("%d",&a[i]);
      if (a[i] <= n) e[a[i]].pb(i);
   }

   foru(i,1,m) {
      int l = read(), r = read();
      q[l].pb(mp(r,i));
   }

   fill(f,0);
   foru(i,1,n) {
      p[i] = 0;
      sz[i] = size(e[i]);
      up(i,0,1);
   }

   foru(i,1,n) {
      int szq = size(q[i]);
      rep(j,szq) res[q[i][j].sc] = get(1,1,n,q[i][j].fr);
      int x = a[i];
      if (x > n) continue;
      while (p[x]+x <= sz[x] && e[x][p[x]] <= i) {
         up(x,p[x],-1);
         ++p[x];
      }
      if (p[x]+x <= sz[x]) up(x,p[x],1);

   }

   foru(i,1,m) printf("%d\n",res[i]);
   return 0;
}
