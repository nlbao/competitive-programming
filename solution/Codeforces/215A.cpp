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

int a[100], b[100];

int main() {
   freopen("215A.in", "r", stdin);
   freopen("215A.out", "w", stdout);
   int n,m;
   scanf("%d",&n);
   rep(i,n) scanf("%d",&a[i]);
   scanf("%d",&m);
   rep(i,m) scanf("%d",&b[i]);
   int x = 0, y = 1, res = 0;
   rep(i,n)
      rep(j,m) {
         if (b[j]%a[i] != 0) continue;
         int t = b[j]*y-x*a[i];
         if (t > 0) {
            x = b[j];
            y = a[i];
            res = 1;
         }
         else if (t == 0) ++res;
      }
   printf("%d",res);
   return 0;
}
