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

const int MAX_N = 1003;

int n, m;
VI e[MAX_N];
int d[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1280.in", "r", stdin);
   freopen("1280.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   fill(d,0);
   rep(i,m) {
      int x = read(), y = read();
      e[x].pb(y);
      ++d[y];
   }
   foru(i,1,n) {
      int u = read();
      if (d[u] > 0) {
         printf("NO");
         return 0;
      }
      int sz = size(e[u]);
      rep(i,sz) --d[e[u][i]];
   }
   printf("YES");
   return 0;
}
