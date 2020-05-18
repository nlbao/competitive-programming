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

const int MAX_N = 203;

VI e[MAX_N];
int q[MAX_N], x[MAX_N], y[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void bfs(int u) {
   int l = 1, r = 0;
   q[++r] = u;
   ok[u] = false;
   while (l <= r) {
      u = q[l++];
      int sz = size(e[u]);
      rep(i,sz) {
         int v = e[u][i];
         if (ok[v]) {
            q[++r] = v;
            ok[v] = false;
         }
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("218C.in", "r", stdin);
   freopen("218C.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   foru(i,1,n) scanf("%d%d",&x[i],&y[i]);

   foru(i,1,n)
      foru(j,i+1,n)
         if (x[i] == x[j] || y[i] == y[j]) {
            e[i].pb(j);
            e[j].pb(i);
         }

   int res = 0;
   foru(i,1,n) {
      fill(ok,true);
      bfs(i);
      foru(j,1,n)
         if (ok[j]) {
            e[i].pb(j);
            e[j].pb(i);
            ++res;
            bfs(j);
         }
   }
   printf("%d",res);
   return 0;
}
