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

int n, m;
int a[1111][1111];

bool ok(int x1, int y1, int x2, int y2) {
   if (x1 < 1 || y1 < 1 || x2 > n || y2 > n) return false;
   foru(i,x1,x2)
      foru(j,y1,y2)
         if (a[i][j] == 0) return false;
   return true;
}

int solve() {
   fill(a,0);
   rep(id,m) {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x][y] = 1;
      foru(i,x-2,x)
         foru(j,y-2,y)
            if (ok(i,j,i+2,j+2)) return id+1;
   }
   return -1;
}

int main() {
   freopen("203B.in", "r", stdin);
   freopen("203B.out", "w", stdout);
   cin >> n >> m;
   cout << solve();
   return 0;
}
