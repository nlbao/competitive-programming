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

const int MAX_N = 60;
const int MAX_S = 1010;

int n, s;
ll f[MAX_N][MAX_S];

int main() {
   freopen("1036.in", "r", stdin);
   freopen("1036.out", "w", stdout);
   scanf("%d%d",&n,&s);
   fill(f,0);
   foru(i,0,9) f[1][i] = 1;
   foru(i,1,n-1)
      foru(j,0,s)
         if (f[i][j] > 0)
            rep(k,s-j+1) f[i+1][j+k] += f[i][j];
   ll res = 0;
   if (s%2 == 0) {
      s /= 2;
      res = f[n][s]*f[n][s];
   }
   printf("%d",res);
   return 0;
}
