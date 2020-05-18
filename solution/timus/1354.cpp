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

const int MAX_N = 10007;
const ll BASE = 10007;
const ll MODUN = 1000000009LL;

char s[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
   freopen("1354.in", "r", stdin);
   freopen("1354.out", "w", stdout);
#endif
   gets(s);
   int n = strlen(s);
   if (n == 1) {
      printf("%c%c", s[0], s[0]);
      return 0;
   }
   ll h = 0, g = 0, p = 1, res = n-1;
   ford(i, n-1, 1) {
      h = (h*BASE+s[i])%MODUN;
      g = (g+p*s[i])%MODUN;
      p = (p*BASE)%MODUN;
      if (h == g) res = i;
   }
   foru(i, 0, n-1) printf("%c", s[i]);
   ford(i, res-1, 0) printf("%c", s[i]);
   return 0;
}
