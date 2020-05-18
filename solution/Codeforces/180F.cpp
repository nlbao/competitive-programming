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

const int MAX_N = 100007;

int n;
int a[MAX_N], b[MAX_N], p[MAX_N];

int main() {
   freopen("180F.in", "r", stdin);
   freopen("180F.out", "w", stdout);
   cin >> n;
   fill(p, 0);
   foru(i, 1, n) scanf("%d", &a[i]);
   foru(i, 1, n) {
      scanf("%d", &b[i]);
      p[a[i]] = b[i];
   }
   foru(i, 1, n) printf("%d ", p[i]);
   return 0;
}
