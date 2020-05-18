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

const int MAX_N = 20010;
const int BASE = 10007;

int n, k;
ll a[MAX_N], p[MAX_N], s[MAX_N];
VI h;

ll get_h(int i, int j) {
   if (i == 0) return s[j];
   return s[j]-s[i-1]*p[j-i+1];
}

bool ok(int len) {
   h.clear();
   foru(i, 1, n-len+1) h.pb(get_h(i,i+len-1));
   sort(all(h));
   int m = size(h);
   for(int i = 0, j = 0; i < m; i = j) {
      while (j < m && h[j] == h[i]) ++j;
      if (j-i >= k) return true;
   }
   return false;
}

int main() {
   freopen("3261.in", "r", stdin);
   freopen("3261.out", "w", stdout);
   cin >> n >> k;
   p[0] = 1;
   s[0] = 0;
   foru(i, 1, n) {
      scanf("%d", &a[i]);
      p[i] = p[i-1]*BASE;
      s[i] = s[i-1]*BASE+a[i];
   }

   int l = 1, r = n, res = 0;
   while (l <= r) {
      int mid = (l+r)/2;
      if (ok(mid)) {
         res = mid;
         l = mid+1;
      }
      else r = mid-1;
   }
   cout << res;
   return 0;
}
