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

const int MAX_N = 100007;
const int BASE = 10007;

int n;
int a[MAX_N], b[MAX_N];
VI pos[MAX_N];
map <int, int> q;
ll p[MAX_N], s[MAX_N];

ll get_h(int i, int j) {
   if (!i) return s[j];
   return s[j]-s[i-1]*p[j-i+1];
}

int solve() {
   int left = -1, i = 0;
   while (i < n) {
      if (i < left) i = left;
      rep(j, size(pos[a[i]])) {
         int l = pos[a[i]][j], r = 2*l-i-1;
         if (l <= i || r >= n) continue;
         if (get_h(i,l-1) == get_h(l,r)) {
            left = i = l-1;
            break;
         }
      }
      ++i;
   }
   return ++left;
}

int main() {
#ifdef DEBUG
   freopen("19C.in", "r", stdin);
   freopen("19C.out", "w", stdout);
#endif
   int c = -1;
   cin >> n;
   rep(i, n) {
      scanf("%d", &b[i]);
      if (q.find(b[i]) == q.end()) q[b[i]] = ++c;
      a[i] = q[b[i]];
      pos[a[i]].pb(i);
   }

   p[0] = 1;
   s[0] = a[0];
   foru(i, 1, n) {
      p[i] = p[i-1]*BASE;
      s[i] = s[i-1]*BASE+a[i];
   }

   int res = solve();
   printf("%d\n", n-res);
   foru(i, res, n-1) printf("%d ", b[i]);
   return 0;
}
