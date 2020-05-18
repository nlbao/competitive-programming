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

bool ok(int n) {
   if (n < 1) return false;
   if (n == 1) return true;
   int k = sqrt(n);
   if (k*(k+1) == n || (k-1)*k == n || (k+1)*(k+2) == n) return true;
   return false;
}

string solve(int n) {
   if (n < 2) return "NO";
   n *= 2;
   foru(i, 1, sqrt(n)+1)
      if (ok(n-i*(i+1))) return "YES";
   return "NO";
}

int main() {
   freopen("192A.in", "r", stdin);
   freopen("192A.out", "w", stdout);
   int n;
   cin >> n;
   cout << solve(n);
   return 0;
}
