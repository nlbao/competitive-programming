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

const int MAX_N = 1000010;
const int MAX_P = 80000;

int nP = 0;
bool ok[MAX_N];
int p[MAX_N];
int mu[MAX_N], m[MAX_N];

int cnt(int n) {
   int c = 0;
   rep(i,nP) {
      int x = p[i];
      if (x*x > n) break;
      while (n%x == 0) {
         ++c;
         n /= x;
      }
   }
   if (n > 1) ++c;
   return c;
}

int main() {
   freopen("10738.in", "r", stdin);
   freopen("10738.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   rep(i,MAX_N) mu[i] = 1;
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         mu[i] = -1;
         ll j = i, i2 = j*j;
         for(j *= j; j < MAX_N; j += i) {
            ok[j] = false;
            if (j%i2 == 0) mu[j] = 0;
         }
      }
      else if (mu[i] == 1 && cnt(i)%2 == 1) mu[i] = -1;

   m[0] = 0;
   foru(i,1,MAX_N-1) m[i] = m[i-1]+mu[i];

   for(;;) {
      int n;
      scanf("%d",&n);
      if (n == 0) break;
      printf("%8d%8d%8d\n",n,mu[n],m[n]);
   }
   return 0;
}
