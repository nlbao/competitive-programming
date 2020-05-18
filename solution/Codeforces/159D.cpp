#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 2007;

bool ok[MAX_N][MAX_N];
ll f[MAX_N], g[MAX_N];

int main() {
   freopen("159D.in", "r", stdin);
   freopen("159D.out", "w", stdout);
   string s;
   getline(cin, s);
   int n = s.size();
   fab(i, 0, n-1) ok[i][i] = true;
   fab(i, 0, n-2) ok[i][i+1] = (s[i] == s[i+1]);
   fab(len, 3, n)
      fab(i, 0, n-len) {
         int j = i+len-1;
         ok[i][j] = (s[i] == s[j]) && (ok[i+1][j-1]);
      }
   fab(i, 0, n-1)
      fab(j, i, n-1)
         if (ok[i][j]) {
            ++f[i];
            ++g[j];
         }
   ll res = 0, cg = 1;
   fab(i, 1, n-1) {
      res += cg*f[i];
      cg += g[i];
   }
   cout << res << endl;
   return 0;
}


