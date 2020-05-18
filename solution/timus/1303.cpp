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

const int MAX_N = 100010;
const int oo = 1000000000;

int n,m,nB;
PI a[MAX_N], b[MAX_N];

void solve() {
   nB = 0;
   rep(i,n) {
      if (a[i].fr <= 0) {
         if (nB == 0 || b[0].sc < a[i].sc) {
            b[0] = a[i];
            nB = 1;
            if (b[0].sc >= m) return;
         }
         continue;
      }
      if (nB == 0) return;
      if (a[i].fr > b[nB-1].sc) return;
      if (a[i].sc <= b[nB-1].sc) continue;
      if (nB == 1) b[nB++] = a[i];
      else
         if (a[i].fr <= b[nB-2].sc) b[nB-1] = a[i];
         else b[nB++] = a[i];
      if (b[nB-1].sc >= m) return;
   }
}

int main() {
   freopen("1303.in", "r", stdin);
   freopen("1303.out", "w", stdout);
   scanf("%d",&m);
   n = 0;
   for(;;) {
      int x,y;
      scanf("%d%d",&x,&y);
      if (x == 0 && y == 0) break;
      a[n++] = mp(x,y);
   }

   sort(a,a+n);
   solve();

   if (nB == 0 || b[nB-1].sc < m) printf("No solution");
   else {
      printf("%d\n",nB);
      rep(i,nB) printf("%d %d\n",b[i].fr,b[i].sc);
   }
   return 0;
}
