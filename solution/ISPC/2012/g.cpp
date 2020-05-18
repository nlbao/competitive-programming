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

const int MAX_N = 17000000;

int n;
int d[MAX_N], e[MAX_N];
bool ok[MAX_N];

int solve(int i) {
   int s = 0;
   while (ok[i]) {
      ++s;
      ok[i] = false;
      i = e[i];
   }
   return s;
}

int main() {
   freopen("g.in", "r", stdin);
   freopen("g.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(i,nTest) {
      ll a, b, c;
      cin >> a >> b >> c >> n;
      fill(d,0);
      rep(i, n) {
         ll v = i;
         ++d[e[i] = (a*v*v+b*v+c)%n];
      }
      int res = 1;
      fill(ok,true);
      rep(i, n) if (d[i] == 0) res = max(res, solve(i));
      rep(i, n) if (ok[i]) res = max(res, solve(i));
      cout << res << endl;
   }
   return 0;
}
