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

const int MAX_N = 104;
const int MAX_M = 504;

int f[MAX_M];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("PARTY.in", "r", stdin);
   freopen("PARTY.out", "w", stdout);
#endif
   for(;;) {
      int w = read(), n = read();
      if (n == 0) break;
      fill(f,0);
      rep(i,n) {
         int a = read(), b = read();
         ford(j,w-a,0) f[j+a] = max(f[j+a],f[j]+b);
      }
      int r1 = 0, r2 = 0;
      foru(i,1,w)
         if (f[i] > r2) {
            r1 = i;
            r2 = f[i];
         }
      printf("%d %d\n",r1,r2);
   }
   return 0;
}
