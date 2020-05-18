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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 11111;

ll a[MAX_N], b[MAX_N];

int main() {
   freopen("177E1.in", "r", stdin);
   freopen("177E1.out", "w", stdout);
   int n, c;
   cin >> n >> c;
   foru(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[i] = x;   b[i] = y;
   }
   ll res = 0;
   foru(i, 1, 111111111) {
      ll sum = n;
      foru(j, 1, n) sum += (ll(i)*a[j])/b[j];
      if (sum == c) ++res;
      else if (sum > c) break;
   }
   cout << res << endl;
   cout << MAX_LL << endl;
   return 0;
}

