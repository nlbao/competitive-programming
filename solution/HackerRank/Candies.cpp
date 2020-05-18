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

const int MAX_N = 100010;

int a[MAX_N], f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("Candies.in", "r", stdin);
   freopen("Candies.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);
   a[0] = -1000000;
   a[n+1] = 1000000;

   f[n+1] = 0;
   ford(i,n,1)
      if (a[i] > a[i+1]) f[i] = f[i+1]+1;
      else f[i] = 1;

   ll res = 0;
   f[0] = 0;
   foru(i,1,n) {
      if (a[i] > a[i-1]) f[i] = max(f[i-1]+1,f[i]);
      res += ll(f[i]);
   }
   cout << res;
   return 0;
}
