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

const int MAX_N = 100007;

int n;
PI a[MAX_N];
int next[MAX_N], r[MAX_N];
bool ok[MAX_N];

void solve() {
   scanf("%d", &n);
   foru(i, 1, n) scanf("%d%d", &a[i].fr, &a[i].sc);
   sort(a+1, a+n+1);
   next[1] = 0;
   foru(i, 2, n) {
      next[i] = i-1;
      while (next[i] > 0 && a[next[i]].sc <= a[i].sc) next[i] = next[next[i]];
   }
   int nR = 0;
   fill(ok, true);
   ford(i, n, 1)
      if (ok[i]) {
         r[++nR] = 1;
         int j = next[i], maxW = a[i].sc;
         while (j > 0)
            if (a[j].sc <= maxW) j = next[j];
            else if (ok[j]) {
               ++r[nR];
               ok[j] = false;
               maxW = a[j].sc;
               j = next[j];
            }
            else --j;
      }
   printf("%d\n", nR);
   foru(i, 1, nR) printf("%d ", r[i]);
   printf("\n");
}

int main() {
   freopen("TRAINING.in", "r", stdin);
   freopen("TRAINING.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) solve();
   return 0;
}
