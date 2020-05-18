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

const int MAX_N = 165000;
const int MAX_P = 15007;

int nP = 0;
bool is_prime[MAX_N];
int p[MAX_P];

int main() {
   freopen("1086.in", "r", stdin);
   freopen("1086.out", "w", stdout);
   fill(is_prime,true);
   for(int i = 2; i < MAX_N; ++i)
      if (is_prime[i]) {
         p[++nP] = i;
         for(ll j = i*1LL*i; j < MAX_N; j += i)
            is_prime[j] = false;
      }
   int k;
   scanf("%d",&k);
   rep(i,k) {
      int x;
      scanf("%d",&x);
      printf("%d\n",p[x]);
   }
   return 0;
}
