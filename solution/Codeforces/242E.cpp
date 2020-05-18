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

const int MAX_N = 100005;
const int MAX_F = 6*MAX_N;

int n;
int a[MAX_N];
ll b[22];
int f[MAX_F][22];
bool g[MAX_F][22];

int read() {   int x;   scanf("%d",&x);   return x;   }

void init(int k, int l, int r) {
   if (l > r) return;
   if (l == r) {
      rep(i,20)
         f[k][i] = (a[l]>>i)&1;
      return;
   }
   int mid = (l+r)>>1;
   int left = k<<1, right = left+1;
   init(left,l,mid);
   init(right,mid+1,r);
   rep(i,20) f[k][i] = f[left][i]+f[right][i];
}

void mnot(bool &x) { x = !x; }

void sub_up(int k, int len) {
   if (k >= MAX_F || k<<1 >= MAX_F) return;
   rep(i,20) if (g[k][i]) {
      mnot(g[k<<1][i]);
      mnot(g[(k<<1)+1][i]);
      g[k][i] = false;
      f[k][i] = len-f[k][i];
   }
}

void up(int k, int l, int r, int u, int v) {
   if (l > r || l > v || r < u) return;
   if (u <= l && r <= v) {
      rep(i,20) if (b[i]) mnot(g[k][i]);
      return;
   }

   int mid = (l+r)>>1;
   int left = k<<1, right = left+1;
   up(left,l,mid,u,v);
   up(right,mid+1,r,u,v);

   sub_up(left,mid-l+1);
   sub_up(right,r-mid);
   rep(i,20) f[k][i] = f[left][i]+f[right][i];
}

void get(int k, int l, int r, int u, int v) {
   if (l > r || l > v || r < u) return;
   int len = r-l+1;
   if (u <= l && r <= v) {
      rep(i,20)
         if (g[k][i]) b[i] += len-f[k][i];
         else b[i] += f[k][i];
      return;
   }

   sub_up(k,len);

   int mid = (l+r)>>1;
   get(k<<1,l,mid,u,v);
   get((k<<1)+1,mid+1,r,u,v);
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("242E.in", "r", stdin);
   freopen("242E.out", "w", stdout);
#endif
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);
   fill(f,0);
   fill(g,false);
   init(1,1,n);

   int m = read();
   rep(id,m) {
      int t, l, r;
      scanf("%d%d%d",&t,&l,&r);
      fill(b,0);
      if (t == 1) {
         get(1,1,n,l,r);
         ll res = 0;
         rep(i,20) res += ll(1LL<<i)*b[i];
         printf("%I64d\n",res);
      }
      else {
         int x = read();
         rep(i,20) b[i] = (x>>i)&1;
         up(1,1,n,l,r);
      }
   }
   return 0;
}
