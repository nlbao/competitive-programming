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

int a[100007];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("251A.in", "r", stdin);
   freopen("251A.out", "w", stdout);
#endif
   int n, d;
   scanf("%d%d",&n,&d);
   foru(i,1,n) scanf("%d",&a[i]);
   ll res = 0;
   foru(i,1,n-2) {
      int l = i+2, r = n;
      ll t = 0;
      while (l <= r) {
         int mid = (l+r)>>1;
         if (a[mid]-a[i] <= d) {
            t = mid;
            l = mid+1;
         }
         else r = mid-1;
      }
      if (t) {
         t -= i;
         res += (t*(t-1))/2;
      }
   }
   cout << res;
   return 0;
}
