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

const int MAX_N = 1000007;
const int MAX_M = 1000007;
const ll BASE = 10007;

int n, m;
int x[MAX_M], y[MAX_M];
ll h[MAX_N], s[MAX_N];


int main() {
   freopen("154C.in", "r", stdin);
   freopen("154C.out", "w", stdout);
   ll res = 0;
   cin >> n >> m;
   h[0] = 1;
   foru(i, 1, n) {
      h[i] = h[i-1]*BASE;
      s[i] = 0;
   }
   rep(i, m) {
      scanf("%d%d", &x[i], &y[i]);
      s[x[i]] += h[y[i]];
      s[y[i]] += h[x[i]];
   }

   rep(i, m)
      if (s[x[i]]+h[x[i]] == s[y[i]]+h[y[i]]) ++res;

   sort(s+1, s+n+1);

   for(int i = 1, j = 1; i <= n; i = j) {
      while (j <= n && s[j] == s[i]) ++j;
      res += ll(j-i)*ll(j-i-1)/2;
   }
   cout << res;
   return 0;
}
