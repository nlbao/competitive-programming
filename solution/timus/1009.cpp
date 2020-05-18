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


int main() {
   freopen("1009.in", "r", stdin);
   freopen("1009.out", "w", stdout);
   int n, k, s, f0;
   scanf("%d%d",&n,&k);
   f0 = 1;
   s = k;
   foru(i,2,n) {
      int t = s;
      s = f0 = t-f0;
      s += (k-1)*t;
   }
   printf("%d\n",s-f0);
   return 0;
}
