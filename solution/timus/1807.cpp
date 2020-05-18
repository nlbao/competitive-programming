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

const int MAX_M = 31630;

int nP, nA;
int a[MAX_M];
ll p[MAX_M], f[MAX_M];
bool ok[MAX_M];

int solve(int n) {
   fill(ok,true);
   nP = 0;
   for(ll i = 2; i <= n; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j <= n; j += i)
            ok[j] = false;
      }
   foru(i,1,n) f[i] = 1;
   f[0] = 0;
   rep(i,nP) {
      ford(j,n,2)
         if (f[j] > 0)
            for(ll x = p[i]; x <= n-j; x *= p[i])
               f[j+x] = x;
      for(ll x = p[i]; x < n; x *= p[i]) f[x] = x;
   }
   //cout << n << " " << f[n] << endl;
   nA = 0;
   while (n > 0) {
      if (f[n] > 0) {
         a[nA++] = f[n];
         n -= f[n];
      }
      else {
         a[nA++] = 1;
         --n;
      }
   }
   return nA;
}

int main() {
   freopen("1807.in", "r", stdin);
   freopen("1807.out", "w", stdout);
   int n,m;
   scanf("%d",&n);
   for(int i = 2; i <= n; ++i)
      if (n%i == 0) {
         m = i;
         break;
      }

   solve(m);
   int g = n/m;
   rep(i,nA) printf("%d ",a[i]*g);
   return 0;
}
