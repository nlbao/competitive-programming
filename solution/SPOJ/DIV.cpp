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

const int N = 1000007;

bool is_prime[N], ok[N];
int d[N];

int main() {
   freopen("DIV.in", "r", stdin);
   freopen("DIV.out", "w", stdout);
   fill(is_prime,true);
   fill(ok,false);
   rep(i,N) d[i] = 2;
   is_prime[0] = is_prime[1] = false;
   for(int i = 2; i < N; ++i)
      if (is_prime[i]) {
         for(int j = i+i; j < N; j += i) {
            is_prime[j] = false;
            ++d[j];
            int k = j/i;
            if (k < i && is_prime[k]) ok[j] = true;
         }
      }
      else
         for(int j = i+i; j < N; j += i) ++d[j];

   int cnt = 0;
   foru(i,2,1000000)
      if (ok[d[i]])
         if (++cnt == 9) {
            cout << i << endl;
            cnt = 0;
         }
   return 0;
}
