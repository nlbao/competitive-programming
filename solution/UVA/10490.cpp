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

const int MAX_N = 33;

ll p[MAX_N];

bool is_prime(ll n) {
   if (n < 2) return false;
   for(ll i = 2; i*i <= n; ++i)
      if (n%i == 0) return false;
   return true;
}

int main() {
   freopen("10490.in", "r", stdin);
   freopen("10490.out", "w", stdout);
   p[0] = 1;
   foru(i,1,MAX_N-1) p[i] = p[i-1]*2;
   for(;;) {
      int n;
      cin >> n;
      if (n == 0) break;
      if (is_prime(p[n]-1)) cout <<"Perfect: " << p[n-1]*(p[n]-1) << "!\n";
      else if (is_prime(n)) cout << "Given number is prime. But, NO perfect number is available.\n";
      else cout << "Given number is NOT prime! NO perfect number is available.\n";
   }
   return 0;
}
