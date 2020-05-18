#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100010;
const int MAX_M = 1050;
const ll MD = 1000000007;

int n, k;
int a[MAX_N];
ll b[MAX_M];
ll f[MAX_M][MAX_M];
ll fact[MAX_N], inv[MAX_N];

void enter() {
   scanf("%d%d", &n, &k);
   fab(i, 1, n) scanf("%d", &a[i]);
}

bool is_lucky(int n) {
   while (n > 0) {
      if ((n%10 != 4) && (n%10 != 7)) return false;
      n /= 10;
   }
   return true;
}

ll mpow(ll a, ll b) {
   if (b == 0) return 1;
   if (b == 1) return a%MD;
   ll t = mpow(a, b/2);
   t = (t*t)%MD;
   if (b%2 == 0) return t;
   else return (a*t)%MD;
}

void init_c() {
   fact[0] = 1;
   inv[0] = 1;
   fab(i, 1, n) {
      fact[i] = (fact[i-1]*i)%MD;
      inv[i] = mpow(fact[i], MD-2);
   }
}

ll cal_c(int k, int n) {
   if (k > n) return 0;
   if ((k == 0) || (k == n)) return 1;
   return (fact[n]*((inv[k]*inv[n-k])%MD))%MD;
}

void solve() {
   sort(a, a+n+1);
   int m = 0, nUnlucky = 0, i = 1;
   while (i <= n) {
      int j = i;
      while ((j < n) && (a[j+1] == a[i])) ++j;
      if (is_lucky(a[i])) b[++m] = j-i+1;
      else nUnlucky += j-i+1;
      i = j+1;
   }

   fill(f, 0);
   fab(i, 0, m) f[i][0] = 1;
   f[1][1] = b[1];
   fab(i, 2, m)
      fab(j, 1, min(i, k))
         f[i][j] = (f[i-1][j]+f[i-1][j-1]*b[i])%MD;

   ll res = 0;
   fab(i, 0, m)
      if ((i <= k) && (k-i <= nUnlucky)) {
         res += (f[m][i]*cal_c(k-i, nUnlucky))%MD;
         res %= MD;
      }
   cout << res << endl;
}

int main() {
   freopen("146E.in", "r", stdin);
   freopen("146E.out", "w", stdout);
   enter();
   init_c();
   solve();
   return 0;
}

