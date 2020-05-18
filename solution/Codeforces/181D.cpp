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
#define size(a) a.size()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1007;
const int MAX_K = 100007;
const ll MODUN = 1000000007;

string s, t;
int n, k;
VI a;

bool check(int p) {
   foru(i, p, p+n-1)
      if (s[i] != t[i-p]) return false;
   return true;
}

int main() {
   freopen("181D.in", "r", stdin);
   freopen("181D.out", "w", stdout);
   getline(cin,s);
   getline(cin,t);
   cin >> k;
   n = size(s);
   s = s+s;
   rep(i, n)
      if (check(i)) a.pb(i);
   if (!size(a)) {
      cout << 0;
      return 0;
   }
   ll f1 = 1, f2 = 0, m = n, res = 0;
   foru(i, 1, k) {
      ll tf1 = f1;
      f1 = ((m-1)*f2)%MODUN;
      f2 = (tf1+(m-2)*f2)%MODUN;
   }
   if (a[0] == 0) res = (f1+ll(size(a)-1)*f2)%MODUN;
   else res = (ll(size(a))*f2)%MODUN;
   cout << res;
   return 0;
}
