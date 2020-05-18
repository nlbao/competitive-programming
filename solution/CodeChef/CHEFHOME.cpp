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

const ll MAXLL = 1000000000000000000ll;
const int MAX_N = 1007;

int n;
int x[MAX_N], y[MAX_N];
ll a[MAX_N], v[MAX_N];

ll solve() {
   if (n < 1) return 0;
   if (n == 1) return 1;
   sort(a+1, a+n+1);
   ll sl = 0, sr = 0, minV = MAXLL, c = 0;
   foru(i, 1, n) {
      sr += a[i];
      v[i] = MAXLL;
   }
   foru(i, 1, n-1) {
      sl += a[i];
      sr -= a[i];
      ll d = sr-sl, t = 2*i-n;
      if (t < 0) v[i+1] = d += t*a[i+1];
      else if (t > 0) v[i] = d += t*a[i];
      else v[i] = v[i+1] = d;
      minV = min(minV, d);
   }
   foru(i, 1, n)
      if (v[i] == minV && (i == 1 || a[i] > a[i-1])) ++c;
   if (n%2 == 0) {
      int i = n/2;
      if (v[i] == v[i+1] && a[i+1] > a[i]) c += a[i+1]-a[i]-1;
   }
   return c;
}

int main() {
   freopen("CHEFHOME.in", "r", stdin);
   freopen("CHEFHOME.out", "w", stdout);
   int nTest;
   cin >> nTest;
   rep(testid, nTest) {
      scanf("%d", &n);
      foru(i, 1, n) scanf("%d%d", &x[i], &y[i]);
      foru(i, 1, n) a[i] = x[i];
      ll res = solve();
      foru(i, 1, n) a[i] = y[i];
      res *= solve();
      cout << res << endl;
   }
   return 0;
}
