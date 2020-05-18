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

const int MAX_N = 55;
const int MAX_S = 2555;

int c[MAX_N], a[MAX_N][MAX_N];
PI pos[MAX_S], b[MAX_S];
vector<pair<PI,PI> > res;

int read() {   int x;   scanf("%d",&x);   return x;   }

void swap(int &x, int &y) {
   int t = x;
   x = y;
   y = t;
}

void swap_a(int u, int v) {
   if (u == v) return;
   res.pb(mp(pos[u],pos[v]));
   swap(a[pos[u].fr][pos[u].sc], a[pos[v].fr][pos[v].sc]);
   PI t = pos[u];
   pos[u] = pos[v];
   pos[v] = t;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("237B.in", "r", stdin);
   freopen("237B.out", "w", stdout);
#endif
   int n = read(), s = 0;
   foru(i,1,n) scanf("%d",&c[i]);
   foru(i,1,n)
      foru(j,1,c[i]) {
         scanf("%d",&a[i][j]);
         pos[a[i][j]] = mp(i,j);
         b[++s] = mp(i,j);
      }

   foru(i,1,s) swap_a(i,a[b[i].fr][b[i].sc]);

   int sz = size(res);
   printf("%d\n",sz);
   rep(i,sz)
      printf("%d %d %d %d\n",res[i].fr.fr,res[i].fr.sc
                            ,res[i].sc.fr,res[i].sc.sc);
   return 0;
}
