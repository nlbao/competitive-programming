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

const int MAX_N = 250007;
const ll BASE = 10007;
const ll MODUN = 1000000009LL;

int n;
char s[MAX_N], t[MAX_N];
ll p[MAX_N], h[MAX_N];

ll mmod(ll x) {   while (x < 0) x += MODUN;  return x%MODUN;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1423.in", "r", stdin);
   freopen("1423.out", "w", stdout);
#endif
   scanf("%d", &n);
   scanf("%s%s", s, t);
   p[0] = 1;
   ll g = t[0];
   foru(i, 1, n-1) {
      p[i] = mmod(p[i-1]*BASE);
      g = mmod(g + ll(t[i])*p[i]);
   }
   h[n-1] = s[n-1];
   ford(i, n-2, 0) h[i] = mmod(h[i+1]*BASE + ll(s[i]));

   int res = -1;
   if (h[0] == g) res = 0;
   ll x = 0;
   foru(i, 1, n-1) {
      x = mmod(x + ll(s[i-1])*p[i-1]);
      if (res >= 0) break;
      if (mmod(h[i]+mmod(x*p[n-i])) == g) res = i;
   }
   if (res > 0) res = n-res;
   cout << res;
   return 0;
}
