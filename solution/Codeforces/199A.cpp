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

const int MAX_N = 1000000001;

int m;
int f[300];


int main() {
   freopen("199A.in", "r", stdin);
   freopen("199A.out", "w", stdout);
   f[0] = 0;   f[1] = 1;
   int m = 2;
   for(; f[m-1] < MAX_N; ++m)
      f[m] = f[m-1]+f[m-2];
   int n;
   scanf("%d",&n);
   if (n < 4) {
      if (n == 0) printf("0 0 0\n");
      if (n == 1) printf("0 0 1\n");
      if (n == 2) printf("0 1 1\n");
      if (n == 3) printf("1 1 1\n");
      return 0;
   }

   foru(i,2,m-1)
      if (f[i] == n) {
         printf("%d %d %d\n",f[i-4],f[i-3],f[i-1]);
         return 0;
      }
   printf("I'm too stupid to solve this problem\n");
   return 0;
}
