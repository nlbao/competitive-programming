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

const int MAX_N = 111;

int a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("BUYING2.in", "r", stdin);
   freopen("BUYING2.out", "w", stdout);
#endif
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      int n, x, s = 0;
      scanf("%d%d",&n,&x);
      rep(i,n) {
         scanf("%d",&a[i]);
         s += a[i];
      }
      int t = s/x;
      rep(i,n)
         if ((s-a[i])/x == t) {
            t = -1;
            break;
         }
      printf("%d\n",t);
   }
   return 0;
}
