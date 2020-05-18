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

int nP;
bool ok[MAX_N];
int p[MAX_N], f[MAX_N];

int main() {
   freopen("406.in", "r", stdin);
   freopen("406.out", "w", stdout);
   nP = 0;
   fill(f,0);
   fill(ok,true);
   ok[0] = ok[1] = false;
   p[nP++] = f[1] = 1;
   for(int i = 2; i < MAX_N; ++i) {
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }
      f[i] = nP;
   }

   int n,c;
   while(cin >> n) {
      cin >> c;
      printf("%d %d:",n,c);
      int l,r,mid = f[n]/2;
      if (f[n]%2 == 0) l = max(mid-c,0);
      else l = max(mid-c+1,0);
      r = min(mid+c-1,f[n]-1);
      foru(i,l,r) printf(" %d",p[i]);
      printf("\n\n");
   }
   return 0;
}
