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
const int MAX_M = 400000;
const int MAX_Q = 1000000;
const ll BASE = 10007;

int n, m, maxD;
vector<PI> e[MAX_N];
int d[MAX_N], q[MAX_N];
ll h[MAX_N];
map<ll, int> list[MAX_N];
char s[MAX_Q];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("NKRTEST.in", "r", stdin);
   freopen("NKRTEST.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   rep(i,m) {
      int x,y,w;
      scanf("%d%d%d",&x,&y,&w);
      e[x].pb(mp(y,w));
      e[y].pb(mp(x,w));
   }

   foru(i,1,n) {
      d[i] = -1;
      h[i] = 0;
   }
   d[1] = 0;   h[1] = 0;
   int l = 1, r = 1;
   q[1] = 1;
   while (l <= r) {
      int pr = r;
      while (l <= pr) {
         int pl = l;
         while (pl < pr && h[q[pl+1]] == h[q[l]]) ++pl;
         foru(id,l,pl) {
            int u = q[id], sz = size(e[u]);
            rep(i,sz) {
               if (e[u][i].sc == 1) continue;
               int v = e[u][i].fr;
               if (d[v] == -1) {
                  d[v] = d[u]+1;
                  h[v] = h[u]*BASE;
                  q[++r] = v;
               }
            }
         }
         foru(id,l,pl) {
            int u = q[id], sz = size(e[u]);
            rep(i,sz) {
               if (e[u][i].sc == 0) continue;
               int v = e[u][i].fr;
               if (d[v] == -1) {
                  d[v] = d[u]+1;
                  h[v] = h[u]*BASE + 1LL;
                  q[++r] = v;
               }
            }
         }
         l = pl+1;
      }
   }

   maxD = 0;
   foru(i,2,n) if (d[i] > 0) {
      maxD = max(maxD,d[i]);
      if (list[d[i]].count(h[i]) > 0) ++list[d[i]][h[i]];
      else list[d[i]][h[i]] = 1;
   }

   scanf("%d",&m);
   rep(id,m) {
      scanf("%s",&s);
      int len = strlen(s);
      int pos = 0, c = 0;
      ll value = 0;
      foru(i,1,len) {
         if (i > maxD) break;
         value = value*BASE + ll(s[i-1]-'0');
         if (list[i].count(value) > 0) {
            pos = i;
            c = list[i][value];
         }
      }
      if (pos < len) printf("-%d %d\n",pos,c);
      else printf("+%d %d\n",pos,c);
   }
   return 0;
}
