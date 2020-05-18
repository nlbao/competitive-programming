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


int solve(string a, string b) {
   int n = a.size(), a7 = 0, b7 = 0, res = 0;
   fab(i, 0, n-1) {
      if (a[i] == '7') ++a7;
      if (b[i] == '7') ++b7;
   }
   if (a7 < b7)
      fab(i, 0, n-1)
         if ((a[i] == '4') && (b[i] == '7')) {
            a[i] = '7';
            ++res;
         }
   if (a7 > b7)
      fab(i, 0, n-1)
         if ((a[i] == '7') && (b[i] == '4')) {
            a[i] = '4';
            ++res;
         }
   fab(i, 0, n-1)
      if ((a[i] == '7') && (b[i] == '4')) ++res;
   return res;
}

int main() {
   freopen("146C.in", "r", stdin);
   freopen("146C.out", "w", stdout);
   string a, b;
   cin >> a >> b;
   cout << min(solve(a, b), solve(b, a));
   return 0;
}

