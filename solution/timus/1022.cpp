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

const int MAX_N = 110;

int n, m = 0;
VI e[MAX_N];
int deg[MAX_N], q[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1022.in", "r", stdin);
   freopen("1022.out", "w", stdout);
#endif
   fill(deg,0);
   scanf("%d",&n);
   foru(i,1,n)
      while(1) {
         int j;
         scanf("%d",&j);
         if (j == 0) break;
         e[i].pb(j);
         ++deg[j];
      }

   foru(i,1,n)
      if (deg[i] == 0) q[m++] = i;
   int i = 0;
   while (i < m) {
      int u = q[i], sz = size(e[u]);
      rep(j,sz) {
         int v = e[u][j];
         --deg[v];
         if (deg[v] == 0) q[m++] = v;
      }
      ++i;
   }
   rep(i,m) printf("%d ",q[i]);
   return 0;
}
