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

const int MAX_N = 2010;

int n, m = 0;
int a[MAX_N], s[MAX_N];

int gcd(int a, int b, int &x, int &y) {
   if (a == 0) {
      x = 0;   y = -1;
      return b;
   }
   int x1, y1;
   int d = gcd(b%a,a,x1,y1);
   x = -y1-(b/a)*x1;
   y = -x1;
   return d;
}

void solve(int p, int q) {
   int x, y;
   gcd(p,q,x,y);
   if (x < 1) x += abs(x/q)*q;
   if (x < 1) x += q;
   a[m++] = p*x;
}

int main() {
   freopen("1698.in", "r", stdin);
   freopen("1698.out", "w", stdout);
   scanf("%d",&n);

   return 0;
}
