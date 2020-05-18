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

const int MAX_N = 53;
const int MAX_S = 53;

int n, s;
ll f[MAX_N][MAX_S];

int gcd(int a, int b) {
   if (a == 0 || b == 0) return a+b;
   return gcd(b,a%b);
}

int main() {
   freopen("1091.in", "r", stdin);
   freopen("1091.out", "w", stdout);
   scanf("%d%d",&n,&s);
   fill(f,0);
   foru(i,3,s) {
      foru(d,2,i-1) {
         int dd = gcd(d,i);
         if (dd < 2) continue;
         ford(j,n,3)
            f[j][dd] += f[j-1][d];
         ++f[2][dd];
      }
   }
   ll res = 0;
   foru(d,2,s) res += f[n][d];
   res = min(res,10000LL);
   printf("%d\n",int(res));
   return 0;
}
