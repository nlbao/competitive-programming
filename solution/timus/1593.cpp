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

const ll MAX_N = 1000000000000000LL;
const int oo = 1000000000;


int solve(ll n) {
   ll p = sqrt(double(n)), m = n;
   if (p*p == n) return 1;
   if (n%2 == 0) {
      p = sqrt(double(n/2));
      if (2*p*p == n) return 2;
   }

   bool two = true;
   for(ll i = 2; i*i <= n; ++i)
      if (n%i == 0) {
         ll t = 1;
         while (n%i == 0) {
            n /= i;
            t *= i;
         }
         if ((t+1)%4 == 0) {
            two = false;
            break;
         }
      }
   if (n > 1 && (n+1)%4 == 0) two = false;
   if (two) return 2;

   n = m;
   if ((n-7)%8 == 0) return 4;
   while (n%4 == 0) {
      n /= 4;
      if ((n-7)%8 == 0) return 4;
   }
   return 3;
}

bool check(ll s, ll p) {
   ll x = sqrt(double(p));
   return false;
}

int main() {
   freopen("1593.in", "r", stdin);
   freopen("1593.out", "w", stdout);
   ll n;
   cin >> n;
   cout << solve(n);
   return 0;
}
