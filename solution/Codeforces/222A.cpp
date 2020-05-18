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

const int MAX_N = 100003;

int n,k;
int a[2*MAX_N], c[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("222A.in", "r", stdin);
   freopen("222A.out", "w", stdout);
#endif
   scanf("%d%d",&n,&k);
   fill(c,0);
   int m = 0;
   foru(i,1,n) {
      scanf("%d",&a[i]);
      ++c[a[i]];
      if (c[a[i]] == 1) ++m;
   }
   if (m == 1) {
      printf("0");
      return 0;
   }
   foru(i,1,n) {
      a[i+n] = a[i+k-1];
      ++c[a[i+n]];
      --c[a[i]];
      if (c[a[i]] == 0) --m;
      if (m == 1) {
         printf("%d",i);
         return 0;
      }
   }
   printf("-1");
   return 0;
}
