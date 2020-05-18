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

const int MAX_N = 100004;
const int MAX_A = 10004;

int a[MAX_N], f[MAX_N], trace[MAX_N], e[MAX_N];
VI p[MAX_A];

int read() {   int x;   scanf("%d",&x);   return x;   }

void print_path(int u) {
   if (trace[u] > 0) print_path(trace[u]);
   printf("%d ",a[u]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1651.in", "r", stdin);
   freopen("1651.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   foru(i,1,n) {
      scanf("%d",&a[i]);
      p[a[i]].pb(i);
   }

   foru(i,1,n) {
      f[i] = n+100;
      trace[i] = e[i] = 0;
   }

   foru(i,1,MAX_A) {
      int sz = size(p[i]);
      rep(j,sz-1) e[p[i][j]] = p[i][j+1];
   }

   f[1] = 0;
   foru(u,1,n) {
      if (u < n && a[u+1] != a[u] && f[u]+1 < f[u+1]) {
         f[u+1] = f[u]+1;
         trace[u+1] = u;
      }
      if (e[u] > 0 && f[u] < f[e[u]]) {
         f[e[u]] = f[u];
         trace[e[u]] = trace[u];
      }
   }

   int u = n;
   foru(i,1,n-1)
      if(a[i] == a[n] && f[i] < f[u]) u = i;
   print_path(u);
   return 0;
}
