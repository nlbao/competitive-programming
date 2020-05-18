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

const int MAX_N = 111;

int a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int move(int &x, int &y, int r1, int r2) {
   if (r1 < r2)
      foru(i,r1+1,r2) y = min(y,a[i]+1);
   else
      ford(i,r1-1,r2) y = min(y,a[i]+1);
   x = r2;
   return abs(r1-r2);
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("253C.in", "r", stdin);
   freopen("253C.out", "w", stdout);
#else
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n, r1,r2,c1,c2;
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);
   scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

   int res = 1000000000;
   if (r1 < r2)
      foru(i,1,r1)
         foru(j,r2,n) {
            int x = r1, y = c1, sum = 0;
            sum = move(x,y,r1,i) + move(x,y,i,j) + move(x,y,j,r2) + abs(y-c2);
            res = min(res,sum);
         }
   else
      foru(i,r1,n)
         foru(j,1,r2) {
            int x = r1, y = c1, sum = 0;
            sum = move(x,y,r1,i) + move(x,y,i,j) + move(x,y,j,r2) + abs(y-c2);
            res = min(res,sum);
         }
   cout << res;
   return 0;
}
