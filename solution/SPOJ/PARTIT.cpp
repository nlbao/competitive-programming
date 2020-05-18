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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 12;
const int MAX_M = 222;

int f[MAX_M][MAX_N][MAX_M];
int a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void solve() {
   int m = read(), n = read();
   ll k = read();
   a[0] = 1;
   foru(i,1,n) {
      a[i] = 1;
      foru(j,a[i-1],MAX_M-1) {
         ll t = f[m][n-i+1][j];
         if (t < k) k -= t;
         else {
            a[i] = j;
            m -= j;
            break;
         }
      }
   }
   foru(i,1,n) printf("%d ",a[i]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("PARTIT.in", "r", stdin);
   freopen("PARTIT.out", "w", stdout);
#endif
   fill(f,0);
   foru(i,1,MAX_M-1) {
      f[i][1][i] = 1;
      if (i < MAX_N) f[i][i][1] = 1;
      foru(j,2,min(i-1,MAX_N-1))
         foru(k,1,min(i-1,i-j+1))
            foru(t,k,i-j-k+2)
               f[i][j][k] += f[i-k][j-1][t];
   }

   int nTest = read();
   rep(id,nTest) {
      solve();
      printf("\n");
   }
   return 0;
}
