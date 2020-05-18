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

ll modun;

int gcd(int a, int b) {
   if (a == 0) return b;
   return gcd(b%a,a);
}

int phi(int n) {
   int res = n, m = n;
   for(int i = 2; i*i <= n; ++i)
      if (n%i == 0) {
         res -= res/i;
         while (n%i == 0) n /= i;
      }
   if (n > 1) res -= res/n;
   return res;
}

ll mpow(ll a, ll x) {
   if (x == 0) return 1;
   if (x == 1) return a;
   ll t = mpow(a,x/2);
   t = (t*t)%modun;
   if (x%2 == 0) return t;
   else return (t*a)%modun;
}

int find(ll a, ll n) {
   ll res = n;
   for(ll i = 1; i*i <= n; ++i)
      if (n%i == 0) {
         if (mpow(a,i) == 1) return i;
         if (mpow(a,n/i) == 1) res = min(res,n/i);
      }
   return res;
}

int main() {
   freopen("1456.in", "r", stdin);
   freopen("1456.out", "w", stdout);
   int a, n;
   cin >> a >> n;
   modun = n;
   if (gcd(a,n) > 1) cout << 0;
   else cout << find(a,phi(n));
   return 0;
}
