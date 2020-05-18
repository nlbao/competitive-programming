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

const int MAX_N = 1007;

int n;
int a[MAX_N], f[MAX_N];

void up(int i, int v)   {  if (i > n) return;   f[i] = max(f[i],v);  }

int main() {
   freopen("192B.in", "r", stdin);
   freopen("192B.out", "w", stdout);
   cin >> n;
   foru(i, 1, n) f[i] = -1;
   foru(i, 1, n) {
      scanf("%d", &a[i]);
      if (f[i] == -1) f[i] = a[i];
      else f[i] = min(f[i],a[i]);
      up(i+1,f[i]);
      up(i+2,f[i]);
   }
   cout << f[n];
   return 0;
}
