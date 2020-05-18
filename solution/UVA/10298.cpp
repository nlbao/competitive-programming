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

const int MAX_N = 1000000;
const ll BASE = 10007;
const ll MODUN = 1000000007;

int n;
char s[MAX_N];

ll num(int i) {   return s[i%n]; }

int solve() {
   ll p = 1, g = 0;
   rep(i, n) {
      p *= BASE;
      g = g*BASE+num(i);
   }
   ll f = g;
   foru(i, n, 2*n-1) {
      f = f*BASE+num(i)-num(i-n)*p;
      int k = i-n+1;
      if (f == g && k && n%k == 0) return (n/k);
   }
   return 0;
}

int main() {
   freopen("10298.in", "r", stdin);
   freopen("10298.out", "w", stdout);
   for(;;) {
      scanf("%s", s);
      n = strlen(s);
      if (n == 1 && s[0] == '.') break;
      printf("%d\n", solve());
   }
   return 0;
}
