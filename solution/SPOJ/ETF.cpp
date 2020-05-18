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

const int MAX_N = 1007;
const int MAX_P = MAX_N;

int nP = 0;
bool is_prime[MAX_N];
int p[MAX_P];
ll p2[MAX_P];

int main() {
   freopen("ETF.in", "r", stdin);
   freopen("ETF.out", "w", stdout);
   fill(is_prime,true);
   foru(i,2,MAX_N-1)
      if (is_prime[i]) {
         p[++nP] = i;
         p2[nP] = i*i;
         for(int j = i*i; j < MAX_N; j += i)
            is_prime[j] = false;
      }

   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      int n;
      scanf("%d",&n);
      int res = n;
      for(int i = 1; i <= nP && p2[i] <= n; ++i)
         if (n%p[i] == 0) {
            res -= res/p[i];
            while (n%p[i] == 0) n /= p[i];
         }
      if (n > 1) res -= res/n;
      printf("%d\n",res);
   }
   return 0;
}
