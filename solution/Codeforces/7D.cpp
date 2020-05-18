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

const int MAX_N = 5000007;
const int MODUN = 107;

char s[MAX_N];
int f[MAX_N];

int main() {
   // freopen("7D.in", "r", stdin);
   // freopen("7D.out", "w", stdout);
   scanf("%s", s);
   int n = strlen(s);
   int l = s[0], r = s[0], p = MODUN, res = 1;
   f[0] = 1;
   foru(i, 1, n-1) {
      l = l*MODUN+s[i];
      r = r+p*s[i];
      p *= MODUN;
      f[i] = 0;
      if (l == r) f[i] = f[(i+1)/2-1]+1;
      res += f[i];
   }
   cout << res;
   return 0;
}
