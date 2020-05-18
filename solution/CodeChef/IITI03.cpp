#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100007;
const int oo = 1000000000;


int main() {
   freopen("IITI03.in", "r", stdin);
   freopen("IITI03.out", "w", stdout);
   int nTest;
   cin >> nTest;
   while (nTest > 0) {
      scanf("%d", n);
      fab(i, 1, n) scanf("%d", &a[i]);
      if (n < 3) {
         fab(i, 1, n) cout << a[i] << " ";
         cout << endl;
         return;
      }
      int x = n, y = n-1;
      --nTest;
   }
   return 0;
}
