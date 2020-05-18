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

int find(int x, int n) {
   int l = 0, r = n, t = n;
   while (l <= r) {
      int mid = (l+r)/2;
      if ((mid+1)*x > n) {
         t = mid;
         r = mid-1;
      }
      else l = mid+1;
   }
   return t;
}

int main() {
   freopen("10852.in", "r", stdin);
   freopen("10852.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }
   int nTest;
   scanf("%d\n",&nTest);
   rep(id,nTest) {
      int n, maxS = -MAX_N, x = 0;
      scanf("%d",&n);
      rep(i,nP)
         if (p[i] > n) break;
         else {
            int k = find(p[i],n);
            if (n-k*p[i] > maxS) {
               maxS = n-k*p[i];
               x = p[i];
            }
         }
      printf("%d\n",x);
   }
   return 0;
}
