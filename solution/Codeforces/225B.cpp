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

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("225B.in", "r", stdin);
   freopen("225B.out", "w", stdout);
#endif
   int s, k, n = 1;
   scanf("%d%d",&s,&k);
   ll a[200] , sum[200];
   a[0] = 0;   a[1] = 1;
   sum[0] = 0; sum[1] =1;
   while (sum[n] < s) {
      a[++n] = 0;
      foru(i,max(1,n-k),n-1) a[n] += a[i];
      sum[n] = sum[n-1]+a[n];
   }


   int m = 0;
   int res[200];
   ford(i,n,1)
      if (sum[i] >= s && a[i] <= s) {
         res[m++] = a[i];
         s -= a[i];
      }

   if (m == 1) res[m++] = 0;
   printf("%d\n",m);
   rep(i,m) printf("%d ",res[i]);
   return 0;
}
