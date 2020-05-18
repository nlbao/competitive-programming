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

const int MAX_N = 1004;
const int MAX_K = 1004;
const ll MODUN = 1000000007;

int c[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll get_c(int k, int n) {
   if (n < 0 || k > n) return 0;
   if (k == 0 || k == n) return 1;
   return c[n][k];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("128C.in", "r", stdin);
   freopen("128C.out", "w", stdout);
#endif
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);
   fill(c,0);
   c[0][0] = 1;
   foru(i,1,max(m,n)) {
      c[i][0] = 1;
      foru(j,1,i)
         c[i][j] = (c[i-1][j] + c[i-1][j-1])%MODUN;
   }
   int res = (get_c(2*k,n-1)*get_c(2*k,m-1))%MODUN;
   cout << res;
   return 0;
}
