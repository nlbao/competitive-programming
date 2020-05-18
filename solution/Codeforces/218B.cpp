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

const int MAX_N = 1003;
const int MAX_M = 1003;

int a[MAX_M], b[MAX_M];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("218B.in", "r", stdin);
   freopen("218B.out", "w", stdout);
#endif
   int n, m;
   scanf("%d%d",&n,&m);
   foru(i,1,m) a[i] = b[i] = read();
   a[0] = -1;
   int f = 0;
   foru(i,1,n) {
      int j = 0;
      foru(i,1,m)
         if (a[i] > a[j]) j = i;
      f += a[j];
      --a[j];
   }
   printf("%d ",f);

   foru(i,1,m) a[i] = b[i];
   a[0] = 10000000;
   f = 0;
   foru(i,1,n) {
      int j = 0;
      foru(i,1,m)
         if (a[i] > 0 && a[i] < a[j]) j = i;
      f += a[j];
      --a[j];
   }
   printf("%d",f);
   return 0;
}
