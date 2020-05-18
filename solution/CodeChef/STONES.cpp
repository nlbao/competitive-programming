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


int main() {
   freopen("STONES.in", "r", stdin);
   freopen("STONES.out", "w", stdout);
   int nTest;
   string s, t;
   bool a[300];
   cin >> nTest;
   getline(cin, s);
   rep(testid, nTest) {
      getline(cin, s);
      getline(cin, t);
      fill(a, false);
      rep(i, size(s)) a[int(s[i])] = true;
      int res = 0;
      rep(i, size(t)) res += int(a[t[i]]);
      cout << res << endl;
   }
   return 0;
}
