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

map <string t, int> a;

int main() {
   freopen("4C.in", "r", stdin);
   freopen("4C.out", "w", stdout);
   int n;
   char s[44];
   cin >> n;
   rep(id, n) {
      scanf("%s", &s);
      string t = s;
      if (a.find(t) == a.end()) {
         a[t] = 0;
         printf("OK\n");
      }
      else {
         ++a[s];
         printf("%s%d\n", s, a[s]);
      }
   }
   return 0;
}
