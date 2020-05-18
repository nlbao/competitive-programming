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

int main() {
   freopen("146A.in", "r", stdin);
   freopen("146A.out", "w", stdout);
   int n, s1 = 0, s2 = 0;
   bool ok = true;
   cin >> n;
   fab(i, 1, n) {
      char ch;
      cin >> ch;
      int j = int(ch)-int('0');
      if ((j != 4) && (j != 7)) {
         ok = false;
         break;
      }
      if (i <= n/2) s1 += j;
      else s2 += j;
   }
   if ((!ok) || (s1 != s2)) cout << "NO" << endl;
   else cout << "YES" << endl;
   return 0;
}

