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

int solve(int a, int b) {
   if (b%a > 0) return 0;
   b /= a;
   int res = 1;
   for(int i = 2; i*i <= b; ++i)
      while (b%i == 0) {
         ++res;
         b /= i;
      }
   if (b > 1) ++res;
   return res;
}

int main() {
   freopen("1355.in", "r", stdin);
   freopen("1355.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      int a, b;
      scanf("%d%d",&a,&b);
      printf("%d\n",solve(a,b));
   }
   return 0;
}
