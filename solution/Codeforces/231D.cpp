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

int main() {
#ifndef ONLINE_JUDGE
   freopen("231D.in", "r", stdin);
   freopen("231D.out", "w", stdout);
#endif
   int x, y, z, x1, y1, z1, s = 0;
   int a[7];
   scanf("%d%d%d",&x,&y,&z);
   scanf("%d%d%d",&x1,&y1,&z1);
   foru(i,1,6) scanf("%d",&a[i]);
   if (x > x1) s += a[6];
   else if (x < 0) s += a[5];
   if (y > y1) s += a[2];
   else if (y < 0) s += a[1];
   if (z > z1) s += a[4];
   else if (z < 0) s += a[3];
   printf("%d",s);
   return 0;
}
