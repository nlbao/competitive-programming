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

const int MAX_N = 33;
const int MAX_K = 1003;

int a[MAX_N], p[MAX_N];
bool ok[MAX_N];
VI res[MAX_K];

int read() {   int x;   scanf("%d",&x);   return x;   }

void solve(int n) {
   foru(i,1,n) a[i] = i;
   int nP = 0, x = n;
   for(int i = 2; i <= x; ++i)
      while (x%i == 0) {
         p[nP++] = i;
         x /= i;
      }

   int nRes = 0, step = 1;
   rep(i,MAX_K) res[i].clear();
   rep(i,nP) {
      fill(ok,true);
      foru(x,1,n) if (ok[x]) {
         res[nRes].pb(p[i]);
         foru(j,0,p[i]-1) {
            int y = x + j*step;
            ok[y] = false;
            res[nRes].pb(y);
         }
         ++nRes;
      }
      step *= p[i];
   }

   printf("%d\n",nRes);
   rep(i,nRes) {
      int m = size(res[i]);
      rep(j,m) printf("%d ",res[i][j]);
      printf("\n");
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("EQUALIZ.in", "r", stdin);
   freopen("EQUALIZ.out", "w", stdout);
#endif
   int nTest = read();
   rep(id,nTest) {
      int n = read();
      rep(i,n) read();
      solve(n);
   }
   return 0;
}
