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

const int MAX_R = 1000000007;

int cnt(int n) {
   int c = 0;
   for(int i = 1; i*i <= n; ++i)
      if (n%i == 0) {
         int j = n/i;
         if (j > i) c += 2;
         else ++c;
      }
   return c;
}

int main() {
   freopen("294.in", "r", stdin);
   freopen("294.out", "w", stdout);
   int nTest, l, r;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d%d",&l,&r);
      int res = l, maxC = 0;
      foru(i,l,r) {
         int c = cnt(i);
         if (c > maxC) {
            maxC = c;
            res = i;
         }
      }
      printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,r,res,maxC);
   }
   return 0;
}
