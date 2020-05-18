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

const int MAX_N = 10010;
const int MODUN = 2007;

int n;
int f[MAX_N], g[MAX_N];

int solve(int n) {
   int s = -f[n]*g[1];
   for(int d = 2; d*d <= n; ++d)
      if (n%d == 0) {
         int p = n/d;
         s -= f[d]*g[p];
         if (p > d) s -= f[p]*g[d];
      }
   while (s < 0) s += MODUN;
   return s%MODUN;
}

int main() {
   freopen("1554.in", "r", stdin);
   freopen("1554.out", "w", stdout);
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&f[i]);
   g[1] = 1;
   foru(i,2,n) g[i] = solve(i);
   foru(i,1,n) printf("%d ",g[i]);
   return 0;
}
