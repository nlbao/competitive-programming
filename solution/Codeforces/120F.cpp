#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a));
#define pb(a) push_back((a));

void mmax(int &a, int b) { a = max(a, b); }

const int MAX_N = 110;

vector<int> adj[MAX_N];
int stt[MAX_N], f[MAX_N];
int maxf, maxu;


void dfs(int u) {
   stt[u] = 1;
   if (f[u] >= maxf) {
      maxf = f[u];
      maxu = u;
   }
   fab(i, 0, adj[u].size()-1) {
      int v = adj[u][i];
      if (stt[v] == 0) {
         f[v] = f[u]+1;
         dfs(v);
      }
   }
}

int solve() {
   int n;
   scanf("%d", &n);
   fab(i, 1, n) adj[i].clear();
   fab(i, 1, n-1) {
      int x, y;
      scanf("%d%d", &x, &y);
      adj[x].pb(y);
      adj[y].pb(x);
   }
   fill(stt, 0);
   f[1] = maxf = 0;
   dfs(1);
   fill(stt, 0);
   f[maxu] = maxf = 0;
   dfs(maxu);
   return f[maxu];
}

int main() {
   freopen("120F.in", "r", stdin);
   freopen("120F.out", "w", stdout);
   int n, res = 0;
   scanf("%d", &n);
   fab(i, 1, n) res += solve();
   printf("%d", res);
   return 0;
}

