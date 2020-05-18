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
typedef unsigned long long ull;
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

const int MAX_N = 100005;
const int MAX_A = 3000006;

int a[MAX_N];
int next[MAX_N][22];
bool ok[MAX_A];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("243A.in", "r", stdin);
   freopen("243A.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);

   rep(i,21) next[n][i] = MAX_A;
   ford(i,n-1,1)
      rep(j,21)
         if ((a[i+1]>>j)&1) next[i][j] = i+1;
         else next[i][j] = next[i+1][j];

   fill(ok,false);
   foru(i,1,n) {
      int x = a[i], j = i;
      while (j <= n) {
         x |= a[j];
         ok[x] = true;
         int pos = MAX_A;
         rep(k,21)
            if (((x>>k)&1) == 0)
               pos = min(pos, next[j][k]);
         j = pos;
      }
   }

   int res = 0;
   rep(i,MAX_A) res += ok[i];
   cout << res;
   return 0;
}
