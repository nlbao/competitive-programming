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

const int MAX_N = 200007;
const int MAX_M = 100007;

int a[MAX_N];
vector< pair< int, PI > > e[MAX_M];

int main() {
   freopen("180E.in", "r", stdin);
   freopen("180E.out", "w", stdout);
   int n, m, p, res = 0;
   cin >> n >> m >> p;
   foru(i, 1, n) scanf("%d", &a[i]);
   int i = 1;
   while (i <= n) {
      int j = i, w = 0, k = e[a[i]].size();
      while (j < n && a[j+1] == a[i]) ++j;
      if (k) w = i-e[a[i]][k-1].sc.sc-1;
      e[a[i]].pb(mp(w, mp(i, j)));
      i = j+1;
   }
   foru(i, 1, m) {
      int l = 0, sumA = 0, sumW = 0;
      rep(r, e[i].size()) {
         sumA += e[i][r].sc.sc-e[i][r].sc.fr+1;
         sumW += e[i][r].fr;
         while (sumW > p) {
            sumA -= e[i][l].sc.sc-e[i][l].sc.fr+1;
            sumW -= e[i][++l].fr;
         }
         res = max(res, sumA);
      }
   }
   cout << res << endl;
   return 0;
}
