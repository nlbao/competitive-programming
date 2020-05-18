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
const int MAX_P = 78510;

int nP = 0;
bool ok[MAX_N];
int p[MAX_P];

bool is_prime(int n) {
   if (n < 2) return false;
   if (n < MAX_N) return ok[n];
   rep(i,nP)
      if (p[i]*p[i] > n) break;
      else if (n%p[i] == 0) return false;
   return true;
}

int find(int n) {
   rep(i,nP)
      if (is_prime(n-p[i])) return p[i];
   return -1;
}

int main() {
   freopen("1356.in", "r", stdin);
   freopen("1356.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j < MAX_N; j += i)
            ok[j] = false;
      }

   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      if (is_prime(n)) {
         printf("%d\n",n);
         continue;
      }
      int i = find(n);
      if (i > 0) {
         printf("%d %d\n",i,n-i);
         continue;
      }
//n%2 == 1
      n -= 3;
      i = find(n);
      printf("3 %d %d\n",i,n-i);
   }
   return 0;
}
