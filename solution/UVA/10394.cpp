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

const int MAX_N = 200000007;
const int MAX_SQRT_N = 15007;
const int MAX_S = 110000;
const int MAX_P = 11078950;
const int MAX_R = 100007;

int nP = 0, cnt = 0;
bool ok[MAX_S];
int p[MAX_P], r[MAX_R];

int main() {
   freopen("10394.in", "r", stdin);
   freopen("10394.out", "w", stdout);
   fill(ok,true);
   for(int i = 2; i < MAX_S; ++i)
      if (ok[i]) {
         p[cnt++] = i;
         ll j = i;
         for(j *= j; j < MAX_SQRT_N; j += i)
            ok[j] = false;
      }

   for(int k = 0, maxk = MAX_N/MAX_S; k <= maxk; ++k) {
      int start = k*MAX_S;
      fill(ok,true);
      rep(i,cnt) {
         int start_idx = (start+p[i]-1)/p[i];
         int j = max(start_idx,2)*p[i]-start;
         for(; j < MAX_S; j += p[i]) ok[j] = false;
      }
      if (k == 0) ok[0] = ok[1] = false;
      for(int i = 0; i < MAX_S && start+i < MAX_N; ++i)
         if (ok[i]) p[nP++] = start+i;
   }

   //cout << nP << endl;
   int nR = 0;
   rep(i,nP-1)
      if (p[i+1]-p[i] == 2) {
         r[++nR] = i;
         if (nR > MAX_R-3) break;
      }

   int n;
   while (scanf("%d",&n) == 1) {
      printf("(%d, %d)\n",p[r[n]],p[r[n]+1]);
   }
   return 0;
}
