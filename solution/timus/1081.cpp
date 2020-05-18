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

const int MAX_N = 50;

int f[MAX_N][2], res[MAX_N];

int main() {
   freopen("1081.in", "r", stdin);
   freopen("1081.out", "w", stdout);
   int n, k;
   scanf("%d%d",&n,&k);
   f[0][0] = 1;
   f[0][1] = 0;
   foru(i,1,n) {
      f[i][0] = f[i-1][0]+f[i-1][1];
      f[i][1] = f[i-1][0];
   }

   if (k > f[n][0]+f[n][1]) {
      printf("-1");
      return 0;
   }

   foru(i,1,n)
      if (k > f[n-i+1][0]) {
         printf("1");
         k -= f[n-i+1][0];
      }
      else printf("0");
   return 0;
}
