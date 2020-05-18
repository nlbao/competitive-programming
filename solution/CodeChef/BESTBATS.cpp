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

const int n = 11;

int k, res, sum, maxS;
int a[n];

void gen(int i, int p) {
   if (i == k) {
      if (sum == maxS) ++res;
      else if (sum > maxS) {
         maxS = sum;
         res = 1;
      }
      return;
   }
   foru(j, p+1, n-(k-i)+1) {
      sum += a[j];
      gen(i+1, j);
      sum -= a[j];
   }
}

int main() {
   freopen("BESTBATS.in", "r", stdin);
   freopen("BESTBATS.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) {
      foru(i, 1, n) scanf("%d", &a[i]);
      scanf("%d", &k);
      res = maxS = sum = 0;
      gen(0, 0);
      printf("%d\n", res);
   }
   return 0;
}
