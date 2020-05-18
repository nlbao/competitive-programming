#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 110;
const int L = 50000;

int main() {
   freopen("148C.in", "r", stdin);
   int n, a, b, s;
   int f[MAX_N];
   cin >> n >> a >> b;
   if (n == 1) {
      cout << 1;
      return 0;
   }
   f[1] = s = 1;
   fab(i, 2, b+1) {
      f[i] = s+1;
      s += f[i];
      if (f[i] > L) {
         cout << -1;
         return 0;
      }
   }
   if (b == 0) {
      f[2] = 1;
      ++s;
      ++b;
   }
   if (a+b+1 > n) {
      cout << -1;
      return 0;
   }
   fab(i, b+2, a+b+1) {
      f[i] = f[i-1]+1;
      if (f[i] > L) {
         cout << -1;
         return 0;
      }
   }
   fab(i, a+b+2, n) f[i] = 1;
   fab(i, 1, n) printf("%d ", f[i]);
   return 0;
}
