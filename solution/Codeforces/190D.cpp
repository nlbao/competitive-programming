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

const int MAX_N = 444444;

vector<PI> b;
int a[MAX_N], c[MAX_N];

int main() {
   freopen("190D.in", "r", stdin);
   freopen("190D.out", "w", stdout);
   int n, k;
   cin >> n >> k;
   rep(i, n) {
      int x;
      scanf("%d", &x);
      b.pb(mp(x, i));
   }
   sort(all(b));
   for(int i = 0, j = 0, m = 0; i < n; i = j, ++m) {
      while (j < n && b[j].fr == b[i].fr) {
         a[b[j].sc] = m;
         ++j;
      }
   }
   fill(c, 0);
   ll res = 0, t = 0;
   rep(i, n) {
      ++c[a[i]];
      t += int(c[a[i]] >= k);
      res += t;
      cout << t << " ";
   }
   cout << endl;
   cout << res;
   return 0;
}
