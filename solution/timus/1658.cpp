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

const int MAX_N = 901;
const int MAX_M = 8101;

int f[MAX_N][MAX_M], l[MAX_N][MAX_M];

void print_path(int x, int y) {
   int d = f[x][y];
   if (d == 0) return;
   printf("%d",d);
   if (d != x) print_path(x-d,y-d*d);
}

int main() {
   freopen("1658.in", "r", stdin);
   freopen("1658.out", "w", stdout);
   fill(f,0);
   rep(i,10) {
      int j = i*i;
      f[i][j] = i;
      l[i][j] = 1;
   }
   foru(i,1,MAX_N-1)
      foru(j,1,MAX_M-1) {
         if (f[i][j] == 0) continue;
         foru(k,1,9) {
            int ii = i+k, jj = j+k*k, x = f[ii][jj];
            if (ii >= MAX_N || jj >= MAX_M) continue;
            if (f[ii][jj] != 0)
               if (l[i][j] >= l[ii][jj]) continue;
               else if (l[i][j]+1 == l[ii][jj] && k >= f[ii][jj]) continue;
            f[ii][jj] = k;
            l[ii][jj] = l[i][j]+1;
         }
      }

   int nTest,s1,s2;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d%d",&s1,&s2);
      if (s1 >= MAX_N || s2 >= MAX_M || f[s1][s2] == 0 || l[s1][s2] > 100) printf("No solution");
      else print_path(s1,s2);
      printf("\n");
   }
   return 0;
}
