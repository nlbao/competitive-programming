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


int solve(int n) {
   foru(i, 0, n) {
      int t = n-4*i;
      if (t < 0) break;
      if (t%7 == 0) return t;
   }
   return -1;
}

int main() {
   freopen("CHEFLUCK.in", "r", stdin);
   freopen("CHEFLUCK.out", "w", stdout);
   int nTest, n;
   cin >> nTest;
   rep(testid, nTest) {
      scanf("%d", &n);
      printf("%d\n", solve(n));
   }
   return 0;
}
