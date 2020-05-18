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

const ll MODUN = 1000000007LL;

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("166E.in", "r", stdin);
   freopen("166E.out", "w", stdout);
#endif
   int n, t = 0;
   ll f[2][4];
   ll s[2];
   scanf("%d",&n);

   fill(f,0);
   f[0][0] = 1;
   s[0] = 1;
   rep(i,n) {
      int tt = t;
      t = (t+1)&1;
      s[t] = 0;
      rep(j,4) {
         f[t][j] = (s[tt]-f[tt][j])%MODUN;
         while (f[t][j] < 0) f[t][j] += MODUN;
         f[t][j] %= MODUN;
         s[t] = (s[t]+f[t][j])%MODUN;
      }
   }
   printf("%d",f[t][0]);
   return 0;
}
