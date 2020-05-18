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

const int MAX_N = 1004;
const int MAX_M = 20;

int a[MAX_M], b[MAX_M], c[MAX_M], d[MAX_M];
int f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("106C.in", "r", stdin);
   freopen("106C.out", "w", stdout);
#endif
   int n,m;
   scanf("%d%d%d%d",&n,&m,&c[0],&d[0]);
   foru(i,1,m) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

   fill(f,0);
   for(int i = c[0]; i <= n; i += c[0]) f[i] = f[i-c[0]] + d[0];
   foru(i,1,m) {
      int limit = min(a[i]/b[i],n/c[i]), k = 1, s = 1;
      while (s <= limit) {
         int w = k*c[i], v = k*d[i];
         ford(j,n-w,0)
            f[j+w] = max(f[j+w], f[j]+v);
         k <<= 1;
         s += k;
      }
      s = limit - s + k;
      if (s < 1) continue;
      int w = s*c[i], v = s*d[i];
      ford(j,n-w,0)
         f[j+w] = max(f[j+w], f[j]+v);
   }

   int res = 0;
   foru(i,1,n) res = max(res,f[i]);
   printf("%d",res);
   return 0;
}
