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

int cal_len(int n) {
   int c = 0;
   while (n > 0) {
      n /= 10;
      ++c;
   }
   return c;
}

ll f(int n) {
   if (n < 1) return 0;
   if (n < 10) {
      int c = 0;
      foru(i,1,n) c += i;
      return c;
   }
   int len = cal_len(n);
   ll res = 0, p = 1;
   foru(i,1,len) {

   }


}

int main() {
#ifndef ONLINE_JUDGE
   freopen("CPCRC1C.in", "r", stdin);
   freopen("CPCRC1C.out", "w", stdout);
#endif
   for(;;) {
      int a, b;
      scanf("%d%d",&a,&b);
      if (a < 0) break;
      printf("%I64d\n",f(b)-f(a-1));
   }
   return 0;
}
