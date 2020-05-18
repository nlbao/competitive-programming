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

const int MAX_N = 20;
const int MAX_M = 110;

int a[MAX_N][MAX_M], b[MAX_N][MAX_M], c[MAX_N][MAX_M];
vector< PI > w;

int main() {
   freopen("181C.in", "r", stdin);
   freopen("181C.out", "w", stdout);
   int n, m, k, res = 0;
   cin >> n >> m >> k;
   foru(i, 1, n) {
      string s;
      getline(cin, s);
      getline(cin, s);
      foru(j, 1, m) scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
   }
   foru(i, 1, n)
      foru(j, 1, n) if (i != j) {
         w.clear();
         foru(t, 1, m)
            w.pb(mp(b[j][t]-a[i][t], c[i][t]));
         sort(all(w));
         int sumW = 0, sumC = 0;
         ford(t, m-1, 0)
            if (w[t].fr <= 0 || sumC == k) break;
            else {
               int x = min(k-sumC, w[t].sc);
               sumW += x*w[t].fr;
               sumC += x;
            }
         res = max(res, sumW);
      }
   cout << res;
   return 0;
}
