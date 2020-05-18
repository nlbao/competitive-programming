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

const int MAX_N = 5004;
const int MAX_M = 400004;

pair<pair<int,int>, pair<int,int> > a[MAX_M];
int p[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int get_root(int u) {
   if (p[u] < 0) return u;
   return p[u] = get_root(p[u]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("COALSCAM.in", "r", stdin);
   freopen("COALSCAM.out", "w", stdout);
#endif
   int nTest = read();
   rep(id,nTest) {
      int n, m1, m2;
      scanf("%d%d%d",&n,&m1,&m2);
      rep(i,m1+m2) {
         int u, v, c;
         scanf("%d%d%d",&u,&v,&c);
         if (i < m1) a[i] = mp(mp(1,c),mp(u,v));
         else a[i] = mp(mp(0,-c),mp(u,v));
      }
      sort(a,a+m1+m2);

      rep(i,n) p[i] = -1;
      ll s1 = 0, s2 = 0;
      rep(i,m1+m2) {
         int u = a[i].sc.fr, v = a[i].sc.sc;
         int r1 = get_root(u), r2 = get_root(v);
         ll w = a[i].fr.sc;
         if (r1 != r2) {
            if (a[i].fr.fr == 0) {
               s1 -= w;
               s2 -= w;
            }
            else s2 += w;
            p[r1] += p[r2];
            p[r2] = r1;
         }
      }

      int f = -1;
      rep(i,n) {
         int t = get_root(i);
         if (t != f)
            if (f < 0) f = t;
            else {
               f = -1;
               break;
            }
      }
      if (f < 0) printf("Impossible\n");
      else printf("%I64d %I64d\n",s1,s2);
   }
   return 0;
}
