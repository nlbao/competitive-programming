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

const int MAX_N = 1007;
const int MAX_M = 1007;
double oo = 1000000000000.0;

double f[MAX_M], g[MAX_M];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1342.in", "r", stdin);
   freopen("1342.out", "w", stdout);
#endif
   int n, m, maxf = 0;
   scanf("%d%d",&n,&m);
   rep(i,m+2) f[i] = oo;
   f[0] = 0;
   rep(i,n) {
      double k = read(), p = read(), q = read(), a, b;
      if (k == 1) {
         a = 0;
         b = q;
      }
      else {
          a = (q-p)/(k-1);
          b = (p*k-q)/(k-1);
      }

      if (k == 1) g[1] = p;
      else {
         g[0] = 0;
         foru(j,1,k) {
            double x = (q-p)*j+(p*k-q);
            g[j] = g[j-1]+x;
            ford(t,j-1,1) g[t] = min(g[t],g[t-1]+x);
         }
         foru(j,2,k) g[j] /= (k-1);
      }

      //cout << k << " " << g[2] << endl;

      ford(t,maxf,0)
         foru(j,1,k)
            if (t+j > m) break;
            else f[t+j] = min(f[t+j],f[t]+g[j]);
      maxf = min(m,maxf+int(k));


      /*foru(j,1,k) {
         //double x = a*double(j)+b;
         double x;
         if (k == 1) x = p;
         else x = ((q-p)*j+(p*k-q))/(k-1);

         ford(t,min(maxf,m),0)
            f[t+1] = min(f[t+1],f[t]+x);
         maxf = min(m,maxf+1);
      }*/
   }

   if (maxf < m) {
      m = maxf;
      printf("Maximum possible amount: %d\n",m);
   }
   printf("Minimum possible cost: %.2f\n",f[m]);
   return 0;
}
