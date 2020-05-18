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

const int MAX_N = 10010;

int nP = 0;
bool ok[MAX_N];
int p[MAX_N];
ll s[MAX_N];

bool find(int n, int i) {
   if (s[i] == n) return true;
   int l = 0, r = i-1;
   while (l <= r) {
      int mid = (l+r)/2;
      ll t = s[i]-s[mid];
      if (t == n) return true;
      else if (t < n) r = mid-1;
      else l = mid+1;
   }
   return false;
}

int main() {
   freopen("1210.in", "r", stdin);
   freopen("1210.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j < MAX_N; j += i)
            ok[j] = false;
      }
   s[0] = p[0];
   foru(i,1,nP-1) s[i] = s[i-1]+p[i];

   for(;;) {
      int n, res = 0;
      scanf("%d",&n);
      if (n == 0) break;
      rep(i,nP)
         if (p[i] > n) break;
         else if (find(n,i)) ++res;
      printf("%d\n",res);
   }
   return 0;
}
