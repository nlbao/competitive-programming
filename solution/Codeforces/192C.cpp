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

char s[100];
int f[33][33];
int g[33];

int num(char x) { return x-'a';  }

int main() {
   freopen("192C.in", "r", stdin);
   freopen("192C.out", "w", stdout);
   int n, res = 0;
   cin >> n;
   fill(f, 0);
   rep(id, n) {
      scanf("%s", s);
      int m = strlen(s), x = num(s[0]), y = num(s[m-1]);
      rep(i, 30) g[i] = f[i][x];
      rep(i, 30)
         if (g[i]) f[i][y] = max(f[i][y],g[i]+m);
      f[x][y] = max(f[x][y], m);
   }
   rep(i, 30) res = max(res, f[i][i]);
   cout << res;
   return 0;
}
