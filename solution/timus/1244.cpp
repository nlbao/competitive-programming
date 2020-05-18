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

const int MAX_N = 110;
const int MAX_F = MAX_N*1000;

int a[MAX_N], f[MAX_F], trace[MAX_F];
VI q;

int main() {
   freopen("1244.in", "r", stdin);
   freopen("1244.out", "w", stdout);
   int n,w;
   scanf("%d",&w);
   scanf("%d",&n);
   fill(f,0);
   f[0] = 1;
   q.pb(0);
   foru(id,1,n) {
      int x;
      scanf("%d",&x);
      int m = size(q);
      ford(i,MAX_F-1,0) {
         int y = x+i;
         if (y >= MAX_F) continue;
         if (f[y] == 0) {
            trace[y] = id;
         }
         f[y] += f[i];
      }
      a[id] = x;
   }
   f[0] = 0;

   if (f[w] == 0) printf("0");
   else if (f[w] > 1) printf("-1");
   else {
      fill(f,0);
      while (w > 0) {
         f[trace[w]] = 1;
         w -= a[trace[w]];
      }
      foru(i,1,n)
         if (f[i] == 0) printf("%d ",i);
   }
   return 0;
}
