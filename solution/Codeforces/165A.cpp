#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 207;

int main() {
   freopen("165A.in", "r", stdin);
   freopen("165A.out", "w", stdout);
   int n, res = 0;
   int x[MAX_N], y[MAX_N];
   bool u[MAX_N], d[MAX_N], l[MAX_N], r[MAX_N];
   cin >> n;
   fab(i, 1, n) {
      cin >> x[i] >> y[i];
      u[i] = d[i] = l[i] = r[i] = false;
   }
   fab(i, 1, n)
      fab(j, 1, n) {
         if ((x[j] > x[i]) && (y[j] == y[i])) r[i] = true;
         if ((x[j] < x[i]) && (y[j] == y[i])) l[i] = true;
         if ((x[j] == x[i]) && (y[j] < y[i])) d[i] = true;
         if ((x[j] == x[i]) && (y[j] > y[i])) u[i] = true;
      }
   fab(i, 1, n)
      if (u[i] && d[i] && l[i] && r[i]) ++res;
   cout << res << endl;
   return 0;
}


