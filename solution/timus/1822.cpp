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

const int MAX_N = 10004;
const double eps = 0.0000001;

int n, max_time;
int p[MAX_N], t[MAX_N], f[MAX_N], b[MAX_N];
VI e[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u, double value) {
   f[u] = t[u];
   int sz = size(e[u]);
   if (sz == 0) return;
   rep(i,sz) dfs(e[u][i], value);
   rep(i,sz) b[i] = f[e[u][i]];
   sort(b,b+sz);
   int c = 0, maxB = 0;
   while (c < sz && value-(c*1.0)/(1.0*sz) > eps) ++c;
   f[u] += b[c-1];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1822.in", "r", stdin);
   freopen("1822.out", "w", stdout);
#endif
   scanf("%d%d",&n,&max_time);
   foru(i,2,n) {
      scanf("%d%d",&p[i],&t[i]);
      e[p[i]].pb(i);
   }
   t[1] = 0;

   double res = 0, l = 0, r = 1;
   foru(i,1,100) {
      double mid = (l+r)/2;
      dfs(1,mid);
      if (f[1] <= max_time) {
         res = mid;
         l = mid;
      }
      else r = mid;
   }
   printf("%.4lf",res*100);
   return 0;
}
