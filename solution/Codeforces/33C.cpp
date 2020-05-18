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

const int MAX_N = 100004;

int s[MAX_N], g[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("33C.in", "r", stdin);
   freopen("33C.out", "w", stdout);
#endif
   int n = read();
   s[0] = 0;
   foru(i,1,n) s[i] = s[i-1] + read();
   int res = abs(s[n]);

   g[n] = -2000000000;
   ford(i,n-1,1) {
      g[i] = max(g[i+1], s[i] + s[i]);
      res = max(res,g[i] - s[n]);
   }

   foru(i,1,n-2) {
      int t = s[i]+s[i];
      res = max(res, g[i+1] - t - s[n]);
      res = max(res, s[n] - t);
   }
   res = max(res, s[n] - 2*s[n-1]);
   cout << res;
   return 0;
}
