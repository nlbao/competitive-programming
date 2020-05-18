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

const int MAX_N = 100004;

int n, k;
int a[MAX_N], c[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int find(int x) {
   fill(c,0);
   int d = 0;
   foru(i,1,x) {
      ++c[a[i]];
      if (c[a[i]] == 1) ++d;
   }
   int res = d;
   foru(i,x+1,n) {
      --c[a[i-x]];
      if (c[a[i-x]] == 0) --d;
      ++c[a[i]];
      if (c[a[i]] == 1) ++d;
      res = max(res,d);
   }
   return res;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("224B.in", "r", stdin);
   freopen("224B.out", "w", stdout);
#endif
   scanf("%d%d",&n,&k);
   foru(i,1,n) scanf("%d",&a[i]);
   int len = n+1, l = k, r = n;
   while (l <= r) {
      int mid = (l+r)/2, t = find(mid);
      if (t >= k) {
         len = mid;
         r = mid-1;
      }
      else l = mid+1;
   }

   if (len > n) {
      printf("-1 -1");
      return 0;
   }

   fill(c,0);
   int d = 0;
   foru(i,1,len) {
      ++c[a[i]];
      if (c[a[i]] == 1) ++d;
   }
   if (d == k) {
      printf("1 %d",len);
      return 0;
   }
   foru(i,len+1,n) {
      --c[a[i-len]];
      if (c[a[i-len]] == 0) --d;
      ++c[a[i]];
      if (c[a[i]] == 1) ++d;
      if (d == k) {
         printf("%d %d",i-len+1,i);
         return 0;
      }
   }
   return 0;
}
