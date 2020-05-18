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

const int MAX_N = 33;

int n, nA, nRes, minRes;
VI e[MAX_N];
int id[MAX_N];
int a[MAX_N], res[MAX_N], c[MAX_N], sz[MAX_N];
bool ok[MAX_N][MAX_N], avail[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int pow2(int x) { return x*x; }

void tryf(int i) {
   if (nA > nRes || nRes < minRes) return;
   if (i > n) {
      foru(j,1,n)
         if (c[j] < 1) return;
      nRes = nA;
      foru(j,1,nA) res[j] = a[j];
      return;
   }
   int u = id[i];
   a[++nA] = u;
   rep(j,sz[u]) ++c[e[u][j]];
   tryf(i+1);
   if (nRes < minRes) return;
   rep(j,sz[u]) --c[e[u][j]];
   --nA;
   if (avail[u]) tryf(i+1);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1824.in", "r", stdin);
   freopen("1824.out", "w", stdout);
#endif
   int r;
   int x[MAX_N], y[MAX_N];
   scanf("%d%d",&n,&r);
   foru(i,1,n) scanf("%d%d",&x[i],&y[i]);
   r *= r;
   foru(i,1,n)
      foru(j,i,n)
         if (pow2(x[i]-x[j]) + pow2(y[i]-y[j]) <= r) {
            e[i].pb(j);
            e[j].pb(i);
         }
   foru(i,1,n) sz[i] = size(e[i]);

   fill(c,0);
   foru(i,1,n) {
      int u = -1, t = -1;
      foru(j,1,n)
         if (c[j] == 0 && sz[j] > t) {
            t = sz[j];
            u = j;
         }
      if (u < 0) break;
      id[i] = u;
      c[u] = 1;
   }

   fill(c,0);
   fill(ok,false);
   fill(avail,true);
   foru(u,1,n)
      rep(j,sz[u]) {
         int v = e[u][j];
         if (v == u) continue;
         ok[v][u] = true;
         ++c[v];
      }
   foru(i,1,n) if (c[i] == 1)
      foru(j,1,n)
         if (ok[i][j]) {
            avail[j] = false;
            break;
         }

   minRes = 0;
   fill(c,0);
   foru(i,1,n) {
      int u = -1, t = -1;
      foru(j,1,n)
         if (c[j] == 0 && sz[j] > t) {
            t = sz[j];
            u = j;
         }
      if (u < 0) break;
      rep(j,sz[u]) c[e[u][j]] = 1;
      ++minRes;
   }


   nRes = n+1000;
   nA = 0;
   fill(c,0);
   tryf(1);
   printf("%d\n",nRes);
   foru(i,1,nRes) printf("%d ",res[i]);
   return 0;
}
