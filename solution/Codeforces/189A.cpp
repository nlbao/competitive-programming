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

const int MAX_N = 4444;

int n, a, b, c;
int f[MAX_N];

void up(int i, int j) {
   if (i > n) return;
   f[i] = max(f[i], f[j]+1);
}

int main() {
   freopen("189A.in", "r", stdin);
   freopen("189A.out", "w", stdout);
   cin >> n >> a >> b >> c;
   fill(f, 0);
   f[a] = f[b] = f[c] = 1;
   foru(i, 1, n)
      if (f[i]) {
         up(i+a, i);
         up(i+b, i);
         up(i+c, i);
      }
   cout << f[n];
   return 0;
}
