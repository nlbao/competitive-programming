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

const int MAX_N = 21;
const int MAX_M = 103;
const int MAX_P = 1<<MAX_N;
const int oo = 1000000000;

int t, nQ;
int f[2][MAX_P], q[MAX_P];
bool inQ[MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }

void up(int mask, int price) {
   int tt = 1-t, m = nQ;
   rep(i,m) f[tt][q[i]] = f[t][q[i]];
   rep(i,m) {
      int u = q[i];
      int v = u|mask;
      if (f[t][u]+price < f[tt][v]) {
         f[tt][v] = f[t][u]+price;
         if (!inQ[v]) {
            q[nQ++] = v;
            inQ[v] = true;
         }
      }
   }
   t = tt;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1326.in", "r", stdin);
   freopen("1326.out", "w", stdout);
#endif
   int n, m;
   scanf("%d",&n);
   t = 0;
   foru(i,1,1<<n) f[0][i] = f[1][i] = oo;
   f[t][0] = 0;
   fill(inQ,false);
   nQ = 1;  q[0] = 0;   inQ[0] = true;

   rep(i,n) up(1<<i,read());
   scanf("%d",&m);
   rep(i,m) {
      int price = read(), k = read(), u = 0;
      rep(j,k) u |= 1<<(read()-1);
      up(u,price);
   }

   int u = 0, res = oo;
   n = read();
   rep(i,n) u |= 1<<(read()-1);
   rep(i,nQ)
      if ((q[i]&u) == u) res = min(res,f[t][q[i]]);
   printf("%d\n",res);
   return 0;
}
