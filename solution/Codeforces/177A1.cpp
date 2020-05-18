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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

int a[111][111];
bool ok[111][111];

int main() {
   freopen("177A1.in", "r", stdin);
   freopen("177A1.out", "w", stdout);
   int n, res = 0;
   fill(ok, false);
   cin >> n;
   foru(i, 1, n) {
      foru(j, 1, n)
         scanf("%d", &a[i][j]);
      ok[i][i] = true;
      ok[i][n-i+1] = true;
      int k = (n-1)/2+1;
      ok[i][k] = ok[k][i] = true;
   }
   foru(i, 1, n)
      foru(j, 1, n)
         if (ok[i][j]) res += a[i][j];
   cout << res;
   return 0;
}

