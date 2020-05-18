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

const int MAX_N = 1007;
const ll BASE = 10007;

int n;
char t[MAX_N];
string s;
ll p[MAX_N], h[MAX_N];
vector<ll> q;

void init() {
   s = "";
   rep(i, n)
      if (t[i] != ' ') s += t[i];
   n = size(s);
   p[0] = 1;
   h[0] = s[0];
   foru(i, 1, n-1) {
      p[i] = p[i-1]*BASE;
      h[i] = h[i-1]*BASE+s[i];
   }
}

ll get_h(int i, int j) {
   if (i == 0) return h[j];
   return h[j]-h[i-1]*p[j-i+1];
}

int solve(int len) {
   int c = 1;
   q.clear();
   rep(i, n-len+1)
      q.pb(get_h(i,i+len-1));
   sort(all(q));
   int m = size(q);
   for(int i = 0, j = 0; i < m; i = j) {
      while (j < m && q[j] == q[i]) ++j;
      c = max(c,j-i);
   }
   return c;
}

int main() {
   freopen("BUZZW.in", "r", stdin);
   freopen("BUZZW.out", "w", stdout);
   for(;;) {
      gets(t);
      n = strlen(t);
      if (n < 1) break;
      init();
      foru(i, 1, n) {
         int res = solve(i);
         if (res > 1) printf("%d\n", res);
         else {
            printf("\n");
            break;
         }
      }
   }
   return 0;
}
