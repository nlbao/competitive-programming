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
   freopen("190A.in", "r", stdin);
   freopen("190A.out", "w", stdout);
   int n, m;
   cin >> n >> m;
   int r1 = n, r2 = n;
   if (n == 0 && m != 0) {
      cout << "Impossible";
      return 0;
   }
   if (n < m) r1 += m-n;
   if (m > 0) r2 += m-1;
   cout << r1 << " " << r2 << endl;
   return 0;
}
