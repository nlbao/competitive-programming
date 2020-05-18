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

const int MAX_N = 100004;

int a[MAX_N], c[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("231C.in", "r", stdin);
   freopen("231C.out", "w", stdout);
#endif
   int n, k;
   scanf("%d%d",&n,&k);
   rep(i,n) scanf("%d",&a[i]);
   sort(a,a+n);

   int maxc = 1, mina = a[0];
   int i = 0;
   ll s = 0;
   foru(j,1,n-1) {
      ll t = a[j]-a[j-1];
      s += ll(j-i)*t;
      while (s > k) {
         s -= t + a[j-1]-a[i];
         ++i;
      }
      if (j-i+1 > maxc) {
         maxc = j-i+1;
         mina = a[j];
      }
   }
   printf("%d %d",maxc,mina);
   return 0;
}
