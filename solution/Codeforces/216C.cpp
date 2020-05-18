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
   freopen("216C.in", "r", stdin);
   freopen("216C.out", "w", stdout);
#endif
   int n, m, k;
   scanf("%d%d%d",&n,&m,&k);
   if (m < n) {
      printf("%d\n",2*k);
      rep(i,k) printf("1 ");
      printf("%d ",n);
      rep(i,k-1) printf("%d ",n+1);
   }
   else {
      printf("%d\n",2*k+1);
      rep(i,k) printf("1 ");
      printf("%d ",n);
      rep(i,k-1) printf("%d ",n+1);
      if (k == 1) printf("%d",n+n-1);
      else printf("%d",n+n);
   }
   return 0;
}
