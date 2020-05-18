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
const int MODUN = 1000000007;

ll f[2][MAX_N], g[MAX_N];

int main() {
   freopen("PANSTACK.in", "r", stdin);
   freopen("PANSTACK.out", "w", stdout);
   fill(f, 0);
   fill(g, 0);
   f[0][1] = g[1] = 1;
   int t = 0;
   fab(i, 2, MAX_N) {
      int tt = t;
      t = (t+1)%2;
      fab(j, 1, i) {
         f[t][j] = (f[tt][j]*ll(j)+f[tt][j-1])%MODUN;
         g[i] = (g[i]+f[t][j])%MODUN;
      }
   }
   int nTest, n;
   cin >> nTest;
   fab(i, 1, nTest) {
      scanf("%d", &n);
      printf("%d\n", g[n]);
   }
   return 0;
}

