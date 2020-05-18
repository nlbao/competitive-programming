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

const int MAX_N = 200005;

int n, top;
ll limit;
VI e[MAX_N];
int pos[MAX_N], last[MAX_N], f[MAX_N], res[MAX_N];
ll d[MAX_N];
pair<ll,int> q[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   pos[u] = last[u] = ++top;
   for (int i = 0, sz = size(e[u]); i < sz; ++i) {
      int v = e[u][i];
      d[v] += d[u];
      dfs(v);
      last[u] = last[v];
   }
}

void update(int i, int value) {
   if (i < 1 || i > n) return;
   f[i] += value;
   update(i+(i&(-i)),value);
}

int get(int i) {
   if (i < 1) return 0;
   if (i > n) return get(n);
   return f[i] + get(i-(i&(-i)));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("runaway.in", "r", stdin);
   freopen("runaway.out", "w", stdout);
#endif
   cin >> n >> limit;
   d[1] = 0;
   foru(i,2,n) {
      int x = read();
      scanf("%lld",&d[i]);
      e[x].pb(i);
   }
   top = 0;
   dfs(1);

   foru(i,1,n) q[i] = mp(d[i], i);
   sort(q+1,q+1+n);

   fill(f,0);
   int p = 1;
   foru(i,1,n) {
      int id = q[i].sc;
      ll x = q[i].fr + limit;
      while (p <= n && q[p].fr <= x) update(pos[q[p++].sc],1);
      res[id] = get(last[id]) - get(pos[id]-1);
   }
   foru(i,1,n) printf("%d\n",res[i]);
   return 0;
}
