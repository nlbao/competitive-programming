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

const int MAX_N = 1000010;

int a[MAX_N];

int gcd(int x, int y) {
   if (x == 0 || y == 0) return x+y;
   return gcd(y,x%y);
}

int main() {
   freopen("10407.in", "r", stdin);
   freopen("10407.out", "w", stdout);
   for(;;) {
      scanf("%d",&a[0]);
      if (a[0] == 0) break;
      int n = 1, x;
      for(;;) {
         scanf("%d",&x);
         if (x == 0) break;
         a[n++] = x;
      }
      int d = 0;
      foru(i,1,n-1) d = gcd(d,abs(a[i]-a[i-1]));
      printf("%d\n",d);
      n = 0;
   }
   return 0;
}
