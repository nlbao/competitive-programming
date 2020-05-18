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

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("218A.in", "r", stdin);
   freopen("218A.out", "w", stdout);
#endif
   int n, k;
   scanf("%d%d",&n,&k);
   int m = 2*n+1;
   int a[500];
   foru(i,1,m) a[i] = read();
   for(int i = 2; k > 0 && i < m; ++i)
      if (i%2 == 0 && a[i] > a[i-1]+1 && a[i] > a[i+1]+1) {
         --a[i];
         --k;
      }
   foru(i,1,m) printf("%d ",a[i]);
   return 0;
}
