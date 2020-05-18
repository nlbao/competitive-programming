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

const int MAX_N = 1010;

int c[MAX_N], f[MAX_N];

int main() {
   freopen("11728.in", "r", stdin);
   freopen("11728.out", "w", stdout);
   fill(c,0);
   rep(i,MAX_N) f[i] = -1;
   for(int i = 1; i < MAX_N; ++i) {
      for(int j = i; j < MAX_N; j += i)
         c[j] += i;
      if (c[i] < MAX_N) f[c[i]] = i;
   }
   for(int id = 1; ; ++id) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      printf("Case %d: %d\n",id,f[n]);
   }
   return 0;
}
