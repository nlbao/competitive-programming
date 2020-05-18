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

int read() {   int x;   scanf("%d",&x);   return x;   }

int check(int x, int y) {
   bool c[10];
   fill(c,false);
   while (x > 0) {
      c[x%10] = true;
      x /= 10;
   }
   while (y > 0) {
      if (c[y%10]) return 1;
      y /= 10;
   }
   return 0;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("221B.in", "r", stdin);
   freopen("221B.out", "w", stdout);
#endif
   int n, res = 0;
   scanf("%d",&n);
   for(int i = 1; i*i <= n; ++i)
      if (n%i == 0) {
         res += check(n,i);
         int j = n/i;
         if (j != i) res += check(n,j);
      }
   printf("%d",res);
   return 0;
}
