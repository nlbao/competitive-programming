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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1010;

int n, nRes = 0, nStack = 0;
vector< pair<int, PI> > stack[30], res[30];

void mprint(int a, int b, int c) {  printf("%d+%d=%d", a, b, c);   }

int main() {
   freopen("PARALLEL.in", "r", stdin);
   freopen("PARALLEL.out", "w", stdout);
   cin >> n;
   if (n == 1) {
      printf("0\n");
      return 0;
   }
   int len = 2, pr = n;
   while (len <= n) {
      ++nRes;
      int l = len/2, r = len;
      while (r <= n) {
         fab(i, l+1, r) res[nRes].pb(mp(i, mp(l, i)));
         l = r+(len/2);
         r += len;
      }
      if (r-len+1 <= pr) ++nStack;
      fab(i, r-len+1, pr) stack[nStack].pb(mp(i, mp(r-len, i)));
      pr = r-len;
      len += len;
   }
   int s = 0;
   cout << nRes+nStack << endl;
   fab(i, 1, nRes) {
      int m = res[i].size();
      if (m == 0) break;
      printf("%d ", m);
      fab(j, 0, m-2) {
         mprint(res[i][j].sc.fr, res[i][j].sc.sc, res[i][j].fr);
         printf(" ");
      }
      mprint(res[i][m-1].sc.fr, res[i][m-1].sc.sc, res[i][m-1].fr);
      printf("\n");
      s += m;
   }
   fba(i, nStack, 1) {
      int m = stack[i].size();
      if (m == 0) continue;
      printf("%d ", m);
      fab(j, 0, m-2) {
         mprint(stack[i][j].sc.fr, stack[i][j].sc.sc, stack[i][j].fr);
         printf(" ");
      }
      mprint(stack[i][m-1].sc.fr, stack[i][m-1].sc.sc, stack[i][m-1].fr);
      printf("\n");
      //s += m;
   }
   cout << s << endl;
   return 0;
}

