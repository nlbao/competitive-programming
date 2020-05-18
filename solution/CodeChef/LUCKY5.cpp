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

string s;

int main() {
   freopen("LUCKY5.in", "r", stdin);
   freopen("LUCKY5.out", "w", stdout);
   int nTest;
   cin >> nTest;
   getline(cin, s);
   fab(i, 1, nTest) {
      getline(cin, s);
      int c = 0;
      fab(j, 0, int(s.size())-1)
         if ((s[j] != '4') && (s[j] != '7')) ++c;
      cout << c << endl;
   }
   return 0;
}
