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

const int MAX_P = 21;
const ll MAX_RES = 4294967291LL;

ll n, res = 0;
ll p[30];

bool ok(ll n) {
   if (n < 1) return false;
   while (n > 0) {
      if (n%3 > 1) return false;
      n /= 3;
   }
   return true;
}

void tryf(int i, ll s) {
   if (s > MAX_RES) return;
   if (ok(s-n)) res = s;
   if (res > 0) return ;
   if (i > MAX_P) return;
   tryf(i+1,s);
   tryf(i+1,s+p[i]);
}

int main() {
   freopen("1261.in", "r", stdin);
   freopen("1261.out", "w", stdout);
   p[0] = 1;
   foru(i,1,21) p[i] = p[i-1]*3;

   cin >> n;
   tryf(0,0);
   if (res > 0) cout << res << " " << res-n;
   else cout << 0;
   return 0;
}
