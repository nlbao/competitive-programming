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

const int MAX_N = 200007;

int a[MAX_N], p[MAX_N];

int main() {
   freopen("189C.in", "r", stdin);
   freopen("189C.out", "w", stdout);
   int n;
   cin >> n;
   foru(i, 1, n) scanf("%d", &a[i]);
   foru(i, 1, n) {
      int x;
      scanf("%d", &x);
      p[x] = i;
   }
   foru(i, 1, n) a[i] = p[a[i]];


   int y = n+1, maxA = 0;
   foru(i, 1, n) {
      if (y > n && maxA > a[i]) y = i;
      maxA = max(maxA, a[i]);
   }
   cout << n-y+1;
   return 0;
}
