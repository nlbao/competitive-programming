#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
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

const int MAX_N = 110;
const int oo = 1000000000;

int n, p;
int a[MAX_N], f[2][2][MAX_N];

int main() {
   freopen("IITI00.in", "r", stdin);
   freopen("IITI00.out", "w", stdout);
   cin >> n >> p;
   fab(i, 1, n) cin >> a[i];
   fab(i, 0, 1)
      fab(j, 0, 1)
         fab(k, 0, n) f[i][j][k] = -oo;
   f[0][0][0] = -a[1];
   f[0][1][1] = a[1];
   int t = 0;
   fab(i, 2, n) {
      int tt = t;
      t = (t+1)%2;
      fab(j, 0, i) {
         f[t][0][j] = max(f[tt][0][j],f[tt][1][j])-a[i];
         if (j > 0)
            f[t][1][j] = max(f[tt][0][j-1], f[tt][1][j-1])+a[i];
      }
   }
   cout << max(f[t][0][p], f[t][1][p]) << endl;
   return 0;
}

