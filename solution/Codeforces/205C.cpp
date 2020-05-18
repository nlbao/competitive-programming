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

ll f(ll n) {
   if (n < 10) return n;
   string s = "";
   ll m = n;
   while (n > 0) {
      s = char(n%10+int('0'))+s;
      n /= 10;
   }
   ll res = m/10-1;
   if (s[0] <= s[size(s)-1]) ++res;
   res += 9;
   return res;
}

int main() {
   freopen("205C.in", "r", stdin);
   freopen("205C.out", "w", stdout);
   ll l,r;
   cin >> l >> r;
   cout << f(r)-f(l-1);
   return 0;
}
