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
typedef unsigned long long ull;
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
const int MAX_M = 100007;
const int MAX_C = 100007;

int n, m;
int a[MAX_N], t[MAX_N];
VI e[MAX_N], color[MAX_C];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("246D.in", "r", stdin);
   freopen("246D.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   foru(i,1,n) {
      scanf("%d",&a[i]);
      color[a[i]].pb(i);
   }
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y);
      e[y].pb(x);
   }

   int res = -1, pos = a[1];
   fill(t,0);
   foru(i,1,MAX_C-1) {
      int c = 0;
      int sz = size(color[i]);
      if (sz == 0) continue;
      rep(j,sz) {
         int u = color[i][j];
         int sz2 = size(e[u]);
         rep(k,sz2) {
            int v = e[u][k];
            if (a[v] != i && t[a[v]] != i) {
               t[a[v]] = i;
               ++c;
            }
         }
      }
      if (c > res) {
         res = c;
         pos = i;
      }
   }
   cout << pos;
   return 0;
}
