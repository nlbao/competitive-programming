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

int n;
bool ok;
VI e[MAX_N];
int f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   if (!ok) return;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      if (f[v] == -1) {
         f[v] = 1-f[u];
         dfs(v);
      }
      else if (f[v] != 1-f[u]) {
         ok = false;
         return;
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1080.in", "r", stdin);
   freopen("1080.out", "w", stdout);
#endif
   scanf("%d",&n);
   foru(i,1,n)
      while (1) {
         int j = read();
         if (j == 0) break;
         e[i].pb(j);
         e[j].pb(i);
      }

   foru(i,1,n) f[i] = -1;
   f[1] = 0;
   ok = true;
   dfs(1);
   if (!ok) printf("-1");
   else foru(i,1,n) printf("%d",f[i]);
   return 0;
}
