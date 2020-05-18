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

const int MAX_N = 1403;

int n;
char a[MAX_N][MAX_N];
char s[MAX_N];

int solve(char x) {
   int res = 0;
   foru(i,1,n) {
      int c = 0;
      foru(j,1,n)
         if (a[i][j] == x) ++c, res = max(res,c);
         else c = 0;
   }

   foru(j,1,n) {
      int c = 0;
      foru(i,1,n)
         if (a[i][j] == x) ++c, res = max(res,c);
         else c = 0;
   }

   foru(k,-n+1,n-1) {
      int c = 0;
      foru(i,1,n)
         if (i-k > n || i-k < 1) continue;
         else if (a[i][i-k] == x) ++c, res = max(res,c);
         else c = 0;
   }

   foru(k,2,2*n) {
      int c = 0;
      foru(i,1,n)
         if (k-i < 1 || k-i > n) continue;
         else if (a[i][k-i] == x) ++c, res = max(res,c);
         else c = 0;
   }
   return res;
}

int main() {
   freopen("1287.in", "r", stdin);
   freopen("1287.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n) {
      scanf("%s",&s);
      foru(j,1,n) a[i][j] = s[j-1];
   }

   int a = solve('s'), b = solve('S');
   //cout << a << " " << b << endl;
   if (a > b) printf("s\n%d",a);
   else if (a < b) printf("S\n%d",b);
   else printf("?\n%d",a);
   return 0;
}
