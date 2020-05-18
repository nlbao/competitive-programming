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

const int MAX_K = 100004;
const int MAX_N = 104;

int c[MAX_N];
int f[MAX_K], trace[MAX_K];
int a[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("232A.in", "r", stdin);
   freopen("232A.out", "w", stdout);
#endif
   int k, n = 85;
   scanf("%d",&k);
   foru(i,0,n) c[i] = (i*(i-1)*(i-2))/6;

   fill(trace,0);
   foru(i,1,k) f[i] = MAX_N*100;
   f[0] = 0;
   foru(i,3,n)
      foru(j,0,k-c[i]) {
         int t = f[j]+i, jj = j+c[i];
         if (t < f[jj]) {
            f[jj] = t;
            trace[jj] = i;
         }
      }
   foru(i,1,k) {
      int d = 1;
      foru(j,2,f[i]) {
         if (i+d > k) break;
         int t = f[i]+1, ii = i+d;
         if (t < f[ii]) {
            f[ii] = t;
            trace[ii] = -j;
         }
         d += j;
      }
   }
   if (f[k] > 100) {
      printf("-1");
      return 0;
   }

   n = 0;
   fill(a,0);
   while (k > 0) {
      int d = trace[k];
      cout << k << " " << d << endl;
      if (d < 0) {
         k += d;
         d = 1;
      }
      else {
         k -= c[d];
         foru(i,n+1,n+d)
            foru(j,i+1,n+d) a[i][j] = a[j][i] = 1;
         n += d;
      }
   }

   printf("%d\n",n);
   foru(i,1,n) {
      foru(j,1,n) printf("%d",a[i][j]);
      printf("\n");
   }
   return 0;
}
