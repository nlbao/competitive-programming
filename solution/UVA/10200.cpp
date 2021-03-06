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

const int MAX_LEN = 10007;
const int MAX_N = 20007;

int nP = 0;
bool ok[MAX_N];
int p[MAX_N], c[MAX_LEN];

bool is_prime(int n) {
   for(int i = 0; i < nP && p[i]*p[i] <= n; ++i)
      if (n%p[i] == 0) return false;
   return true;
}

int main() {
   freopen("10200.in", "r", stdin);
   freopen("10200.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }

   c[0] = 1;
   foru(i,1,MAX_LEN-1) {
      c[i] = c[i-1];
      if (is_prime(i*i+i+41)) ++c[i];
   }

   int a,b;
   while (cin >> a >> b) {
      double s = c[b];
      if (a > 0) s -= c[a-1];
      printf("%.2lf\n",s*100.0/double(b-a+1)+1e-9);
   }
   return 0;
}
